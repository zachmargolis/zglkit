//
//  ZGLKView.m
//  ZGLKit
//
//  Created by Zach Margolis on 10/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "ZGLKView.h"


@interface ZGLKView ()

@property (nonatomic) BOOL recreateFramebufferOnNextDraw;

@end


@implementation ZGLKView

@synthesize context = _context;
@synthesize delegate = _delegate;
@synthesize drawableColorFormat = _drawableColorFormat;
@synthesize drawableDepthFormat = _drawableDepthFormat;
@synthesize drawableHeight = _drawableHeight;
@synthesize drawableMultisample = _drawableMultisample;
@synthesize drawableStencilFormat = _drawableStencilFormat;
@synthesize drawableWidth = _drawableWidth;
@synthesize enableSetNeedsDisplay = _enableSetNeedsDisplay;
@synthesize recreateFramebufferOnNextDraw = _recreateFramebufferOnNextDraw;

#pragma mark Initialization

- (id)initWithFrame:(CGRect)frame context:(EAGLContext *)inContext;
{
    self = [super initWithFrame:frame];
    if (!self) {
        return nil;
    }
    
    _context = [inContext retain];
    
    return self;
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
}

- (void)setDrawableDepthFormat:(GLKViewDrawableDepthFormat)drawableDepthFormat;
{
    _drawableDepthFormat = drawableDepthFormat;
    self.recreateFramebufferOnNextDraw = YES;
}

- (void)setDrawableMultisample:(GLKViewDrawableMultisample)drawableMultisample;
{
    _drawableMultisample = drawableMultisample;
    self.recreateFramebufferOnNextDraw = YES;
}

- (void)setDrawableStencilFormat:(GLKViewDrawableStencilFormat)drawableStencilFormat;
{
    _drawableStencilFormat = drawableStencilFormat;
    self.recreateFramebufferOnNextDraw = YES;
}

#pragma mark Public Methods

- (void)bindDrawable;
{
}

- (void)deleteDrawable;
{
}

- (void)display;
{
    if (self.recreateFramebufferOnNextDraw) {
    }
    
    [self bindDrawable];
    
    [self.delegate glKView:self drawInRect:self.bounds];
}

- (UIImage *)snapshot;
{
    return nil;
}

@end
