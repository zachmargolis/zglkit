//
//  ZGLKView.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef enum {
    GLKViewDrawableColorFormatRGBA8888 = 0,
    GLKViewDrawableColorFormatRGB565,
} GLKViewDrawableColorFormat;

typedef enum {
    GLKViewDrawableDepthFormatNone = 0,
    GLKViewDrawableDepthFormat16,
    GLKViewDrawableDepthFormat24,
} GLKViewDrawableDepthFormat;

typedef enum {
    GLKViewDrawableStencilFormatNone = 0,
    GLKViewDrawableStencilFormat8,
} GLKViewDrawableStencilFormat;

typedef enum {
    GLKViewDrawableMultisampleNone = 0,
    GLKViewDrawableMultisample4X,
} GLKViewDrawableMultisample;


@class EAGLContext;
@protocol ZGLKViewDelegate;



@interface ZGLKView : UIView {
    GLuint _defaultFramebuffer;
    GLuint _colorRenderbuffer;
}

@property (nonatomic, retain) EAGLContext *context;
@property (nonatomic, assign) id <ZGLKViewDelegate> delegate;
@property (nonatomic) GLKViewDrawableColorFormat drawableColorFormat;
@property (nonatomic) GLKViewDrawableDepthFormat drawableDepthFormat;
@property (nonatomic, readonly) NSInteger drawableHeight;
@property (nonatomic) GLKViewDrawableMultisample drawableMultisample;
@property (nonatomic) GLKViewDrawableStencilFormat drawableStencilFormat;
@property (nonatomic, readonly) NSInteger drawableWidth;
@property (nonatomic) BOOL enableSetNeedsDisplay;

- (id)initWithFrame:(CGRect)frame context:(EAGLContext *)inContext;

- (void)bindDrawable;
- (void)deleteDrawable;
- (void)display;
- (UIImage *)snapshot;

@end


@protocol ZGLKViewDelegate <NSObject>

- (void)glKView:(ZGLKView *)view drawInRect:(CGRect)rect;

@end
