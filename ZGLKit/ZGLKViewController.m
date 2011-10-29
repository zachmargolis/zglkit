//
//  ZGLKViewController.m
//  ZGLKit
//
//  Created by Zach Margolis on 10/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "ZGLKViewController.h"
#import "NSDate+ZGLKAdditions.h"
#import "ZGLKView.h"
#import <QuartzCore/CADisplayLink.h>


@interface ZGLKViewController ()

@property (nonatomic, assign) CADisplayLink *displayLink;
@property (nonatomic, retain) NSDate *firstResume;
@property (nonatomic, readwrite) NSInteger framesDisplayed;
@property (nonatomic, readwrite) NSInteger framesPerSecond;
@property (nonatomic, retain) NSDate *lastDraw;
@property (nonatomic, retain) NSDate *lastResume;
@property (nonatomic, retain) NSDate *lastUpdate;

- (void)ZGLKViewController_commonInit;
- (void)displayLinkDidFire:(CADisplayLink *)sender;
- (void)pause;
- (void)resume;
- (void)update;

@end


@implementation ZGLKViewController

@synthesize delegate = _delegate;
@synthesize displayLink = _displayLink;
@synthesize firstResume = _firstResume;
@synthesize framesDisplayed = _framesDisplayed;
@synthesize framesPerSecond = _framesPerSecond;
@synthesize lastDraw = _lastDraw;
@synthesize lastResume = _lastResume;
@synthesize lastUpdate = _lastUpdate;
@synthesize paused = _paused;
@synthesize pauseOnWillResignActive = _pauseOnWillResignActive;
@synthesize preferredFramesPerSecond = _preferredFramesPerSecond;
@synthesize resumeOnDidBecomeActive = _resumeOnDidBecomeActive;
@synthesize timeSinceFirstResume = _timeSinceFirstResume;
@synthesize timeSinceLastDraw = _timeSinceLastDraw;
@synthesize timeSinceLastResume = _timeSinceLastResume;
@synthesize timeSinceLastUpdate = _timeSinceLastUpdate;

#pragma mark Initialization

- (id)init;
{
    self = [super init];
    if (!self) {
        return nil;
    }
    
    [self ZGLKViewController_commonInit];
    
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder;
{
    self = [super initWithCoder:aDecoder];
    if (!self) {
        return nil;
    }
    
    [self ZGLKViewController_commonInit];
    
    return self;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil;
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (!self) {
        return nil;
    }
    
    [self ZGLKViewController_commonInit];
    
    return self;
}

- (void)ZGLKViewController_commonInit;
{
    _preferredFramesPerSecond = 30;
    
    // Explicitly use setters to invoke their side effects
    self.pauseOnWillResignActive = YES;
    self.resumeOnDidBecomeActive = YES;
}

- (void)dealloc;
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
    _displayLink = nil;
    
    [_firstResume release];
    _firstResume = nil;
    
    [_lastDraw release];
    _lastDraw = nil;
    
    [_lastResume release];
    _lastResume = nil;
    
    [_lastUpdate release];
    _lastUpdate = nil;

    [super dealloc];
}

#pragma mark Accessors/Mutators

- (NSInteger)framesPerSecond;
{
    if (self.paused || !self.lastResume) {
        return 0;
    }
    
    return (NSInteger)((double)self.framesDisplayed / [NSDate timeIntervalSinceDate:self.lastResume]);
}

- (void)setResumeOnDidBecomeActive:(BOOL)resumeOnDidBecomeActive;
{
    if (_resumeOnDidBecomeActive == resumeOnDidBecomeActive) {
        return;
    }
    
    if (resumeOnDidBecomeActive) {
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(resume) name:UIApplicationDidBecomeActiveNotification object:nil];
    } else {
        [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidBecomeActiveNotification object:nil];
    }
    
    _resumeOnDidBecomeActive = resumeOnDidBecomeActive;
}

- (void)setPauseOnWillResignActive:(BOOL)pauseOnWillResignActive;
{
    if (_pauseOnWillResignActive == pauseOnWillResignActive) {
        return;
    }
    
    if (pauseOnWillResignActive) {
        [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(pause) name:UIApplicationWillResignActiveNotification object:nil];
    } else {
        [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationWillResignActiveNotification object:nil];
    }
    
    _pauseOnWillResignActive = pauseOnWillResignActive;
}

- (void)setPaused:(BOOL)paused;
{
    if (_paused == paused) {
        return;
    }
    
    if ([self.delegate respondsToSelector:@selector(ZGLKViewController:willPause:)]) {
        [self.delegate glkViewController:self willPause:paused];
    }
        
    if (paused) {
        [self pause];
    } else {
        [self resume];
    }
    
    _paused = paused;
}

- (void)setPreferredFramesPerSecond:(NSInteger)preferredFramesPerSecond;
{
    _preferredFramesPerSecond = preferredFramesPerSecond;
    
    if (!self.paused) {
        [self pause];
        [self resume];
    }
}

- (NSTimeInterval)timeSinceFirstResume;
{
    return [NSDate timeIntervalSinceDate:self.firstResume];
}

- (NSTimeInterval)timeSinceLastDraw;
{
    return [NSDate timeIntervalSinceDate:self.lastDraw];
}

- (NSTimeInterval)timeSinceLastResume;
{
    return [NSDate timeIntervalSinceDate:self.lastResume];
}

- (NSTimeInterval)timeSinceLastUpdate;
{
    return [NSDate timeIntervalSinceDate:self.lastUpdate];
}

#pragma mark Animation

- (void)pause;
{
    [self.displayLink invalidate];
    self.displayLink = nil;
}

- (void)resume;
{
    self.displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(displayLinkDidFire:)];

    NSInteger animationFrameInterval = 1;
    if (_preferredFramesPerSecond >= 1) {
        const NSInteger displayLinkFramesPerInterval = 60;
        animationFrameInterval = displayLinkFramesPerInterval / _preferredFramesPerSecond;
    }
    
    self.displayLink.frameInterval = animationFrameInterval;
    [self.displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
    NSDate *date = [NSDate date];
    if (!self.firstResume) {
        self.firstResume = date;
    }
    self.lastResume = date;
}

- (void)displayLinkDidFire:(CADisplayLink *)sender;
{
    // TODO: ordering?
    [self update];
    [self.delegate glkViewControllerUpdate:self];
    self.lastUpdate = [NSDate date];
    
    ZGLKView *view = (ZGLKView *)self.view;
    if ([view isKindOfClass:[ZGLKView class]]) {
        [view display];
    }    
    self.lastDraw = [NSDate date];
    
    self.framesDisplayed = self.framesDisplayed + 1;
}

- (void)update;
{
    // Stub for subclasses
}


#pragma mark UIViewController

- (void)setView:(UIView *)view;
{
    [super setView:view];
    
    if ([view isKindOfClass:[ZGLKView class]]) {
        ((ZGLKView *)view).enableSetNeedsDisplay = NO;
    }
}

@end
