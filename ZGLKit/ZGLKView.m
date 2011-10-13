//
//  ZGLKView.m
//  ZGLKit
//
//  Created by Zach Margolis on 10/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "ZGLKView.h"
#import <QuartzCore/QuartzCore.h>


@interface ZGLKView ()

@property (nonatomic) BOOL recreateFramebufferOnNextDraw;
@property (nonatomic, readwrite) NSInteger drawableHeight;
@property (nonatomic, retain) NSMutableDictionary *drawableProperties;
@property (nonatomic, readwrite) NSInteger drawableWidth;
@property (nonatomic, readonly) CAEAGLLayer *EAGLLayer;

- (void)ZGLKView_commonInit;
- (void)createDrawable;
- (void)presentDrawable;

@end


@implementation ZGLKView

@synthesize context = _context;
@synthesize delegate = _delegate;
@synthesize drawableColorFormat = _drawableColorFormat;
@synthesize drawableDepthFormat = _drawableDepthFormat;
@synthesize drawableHeight = _drawableHeight;
@synthesize drawableMultisample = _drawableMultisample;
@synthesize drawableProperties = _drawableProperties;
@synthesize drawableStencilFormat = _drawableStencilFormat;
@synthesize drawableWidth = _drawableWidth;
@synthesize enableSetNeedsDisplay = _enableSetNeedsDisplay;
@synthesize recreateFramebufferOnNextDraw = _recreateFramebufferOnNextDraw;

#pragma mark Class Methods

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

#pragma mark Initialization

- (id)initWithFrame:(CGRect)frame;
{
    return [self initWithFrame:frame context:nil];
}

- (id)initWithFrame:(CGRect)frame context:(EAGLContext *)inContext;
{
    self = [super initWithFrame:frame];
    if (!self) {
        return nil;
    }
    
    _context = [inContext retain];
    
    [self ZGLKView_commonInit];
    
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder;
{
    self = [super initWithCoder:aDecoder];
    if (!self) {
        return nil;
    }
    
    [self ZGLKView_commonInit];
    
    return self;
}

- (void)ZGLKView_commonInit;
{
    self.recreateFramebufferOnNextDraw = YES;
    self.drawableProperties = [NSMutableDictionary dictionary];
    
    // Set the scale to the screen scale (retina detect)
    CGFloat screenScale = [[UIScreen mainScreen] scale];
    self.EAGLLayer.contentsScale = screenScale;
    self.contentScaleFactor = screenScale; 
}

- (void)dealloc;
{
    [_context release];
    _context = nil;
    
    [super dealloc];
}

#pragma mark Accessors/Mutators

- (void)setDrawableColorFormat:(GLKViewDrawableColorFormat)drawableColorFormat;
{
    _drawableColorFormat = drawableColorFormat;
    self.recreateFramebufferOnNextDraw = YES;
    
    NSString *drawablePropertyValue = nil;
    switch (drawableColorFormat) {
        case GLKViewDrawableColorFormatRGBA8888:
            drawablePropertyValue = kEAGLColorFormatRGBA8;
            break;
        case GLKViewDrawableColorFormatRGB565:
            drawablePropertyValue = kEAGLColorFormatRGB565;
            break;
    }
    [self.drawableProperties setObject:drawablePropertyValue forKey:kEAGLDrawablePropertyColorFormat];
}

- (void)setDrawableDepthFormat:(GLKViewDrawableDepthFormat)drawableDepthFormat;
{
    _drawableDepthFormat = drawableDepthFormat;
    self.recreateFramebufferOnNextDraw = YES;
    // TODO
}

- (void)setDrawableMultisample:(GLKViewDrawableMultisample)drawableMultisample;
{
    _drawableMultisample = drawableMultisample;
    self.recreateFramebufferOnNextDraw = YES;
    // TODO
}

- (void)setDrawableStencilFormat:(GLKViewDrawableStencilFormat)drawableStencilFormat;
{
    _drawableStencilFormat = drawableStencilFormat;
    self.recreateFramebufferOnNextDraw = YES;
    // TODO
}

- (CAEAGLLayer *)EAGLLayer;
{
    NSAssert([self.layer isKindOfClass:[CAEAGLLayer class]], @"Expected self.layer to be a CAEAGLLayer. self.layer: %@", self.layer);
    return (CAEAGLLayer *)self.layer;
}

#pragma mark GLKView

- (void)bindDrawable;
{
    [EAGLContext setCurrentContext:_context];
    
    glBindFramebuffer(GL_FRAMEBUFFER, _defaultFramebuffer);
    glViewport(0, 0, _drawableWidth, _drawableHeight);
}

- (void)deleteDrawable;
{
    if (!_context) {
        return;
    }
    
    [EAGLContext setCurrentContext:_context];
    
    if (_defaultFramebuffer) {
        glDeleteFramebuffers(1, &_defaultFramebuffer);
        _defaultFramebuffer = 0;
    }
    
    if (_colorRenderbuffer) {
        glDeleteRenderbuffers(1, &_colorRenderbuffer);
        _colorRenderbuffer = 0;
    }
}

- (void)display;
{
    if (self.recreateFramebufferOnNextDraw) {
        [self deleteDrawable];
        [self createDrawable];
        self.EAGLLayer.drawableProperties = self.drawableProperties;
    }
    
    [self bindDrawable];
    
    // TODO: figure out ordering
    [self drawRect:self.bounds];
    [self.delegate glKView:self drawInRect:self.bounds];

    [self presentDrawable];
}

- (UIImage *)snapshot;
{
    // TODO
    return nil;
}

#pragma mark UIView

- (void)drawRect:(CGRect)rect;
{
    // TOOD: remove and just stub for subclasses?
    [super drawRect:rect];
}

#pragma mark Private Methods

- (void)createDrawable;
{
    if (!_context || _defaultFramebuffer) {
        return;
    }

    [EAGLContext setCurrentContext:_context];
    
    // Create default framebuffer object.
    glGenFramebuffers(1, &_defaultFramebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, _defaultFramebuffer);
    
    // Create color render buffer and allocate backing store.
    glGenRenderbuffers(1, &_colorRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, _colorRenderbuffer);
    [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:self.EAGLLayer];
    
    NSInteger drawableHeight = 0;
    NSInteger drawableWidth = 0;
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &drawableHeight);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &drawableWidth);
    self.drawableHeight = drawableHeight;
    self.drawableWidth = drawableWidth;
    
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _colorRenderbuffer);
    
    NSAssert(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, @"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));
}

- (void)presentDrawable;
{
    glBindRenderbuffer(GL_RENDERBUFFER, _colorRenderbuffer);
    NSAssert([_context presentRenderbuffer:GL_RENDERBUFFER], @"Failed to present renderbuffer");
}

@end
