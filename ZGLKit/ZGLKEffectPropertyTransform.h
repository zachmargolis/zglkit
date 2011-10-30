//
//  ZGLKEffectPropertyTransform.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//


#import "ZGLKEffectProperty.h"
#import "ZGLKMatrix4.h"


@interface ZGLKEffectPropertyTransform : ZGLKEffectProperty

@property (nonatomic) ZGLKMatrix4 modelviewMatrix;
@property (nonatomic) ZGLKMatrix4 normalMatrix;
@property (nonatomic) ZGLKMatrix4 projectionMatrix;
@property (nonatomic) ZGLKMatrix4 textureMatrix;

@end
