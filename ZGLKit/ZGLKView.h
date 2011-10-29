//
//  ZGLKView.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef enum {
    ZGLKViewDrawableColorFormatRGBA8888 = 0,
    ZGLKViewDrawableColorFormatRGB565,
} ZGLKViewDrawableColorFormat;

typedef enum {
    ZGLKViewDrawableDepthFormatNone = 0,
    ZGLKViewDrawableDepthFormat16,
    ZGLKViewDrawableDepthFormat24,
} ZGLKViewDrawableDepthFormat;

typedef enum {
    ZGLKViewDrawableStencilFormatNone = 0,
    ZGLKViewDrawableStencilFormat8,
} ZGLKViewDrawableStencilFormat;

typedef enum {
    ZGLKViewDrawableMultisampleNone = 0,
    ZGLKViewDrawableMultisample4X,
} ZGLKViewDrawableMultisample;


@class EAGLContext;
@protocol ZGLKViewDelegate;



@interface ZGLKView : UIView {
    GLuint _defaultFramebuffer;
    GLuint _colorRenderbuffer;
}

@property (nonatomic, retain) EAGLContext *context;
@property (nonatomic, assign) id <ZGLKViewDelegate> delegate;
@property (nonatomic) ZGLKViewDrawableColorFormat drawableColorFormat;
@property (nonatomic) ZGLKViewDrawableDepthFormat drawableDepthFormat;
@property (nonatomic, readonly) NSInteger drawableHeight;
@property (nonatomic) ZGLKViewDrawableMultisample drawableMultisample;
@property (nonatomic) ZGLKViewDrawableStencilFormat drawableStencilFormat;
@property (nonatomic, readonly) NSInteger drawableWidth;
@property (nonatomic) BOOL enableSetNeedsDisplay;

- (id)initWithFrame:(CGRect)frame context:(EAGLContext *)inContext;

- (void)bindDrawable;
- (void)deleteDrawable;
- (void)display;
- (UIImage *)snapshot;

@end


@protocol ZGLKViewDelegate <NSObject>

- (void)glkView:(ZGLKView *)view drawInRect:(CGRect)rect;

@end
