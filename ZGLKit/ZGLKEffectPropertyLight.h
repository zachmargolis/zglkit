//
//  ZGLKEffectPropertyLight.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "ZGLKEffectProperty.h"
#import "ZGLKVector3.h"
#import "ZGLKVector4.h"

typedef enum {
    ZGLKLightingTypePerVertex,
    ZGLKLightingTypePerPixel,
} ZGLKLightingType;

@class ZGLKEffectPropertyTransform;

@interface ZGLKEffectPropertyLight : ZGLKEffectProperty

@property (nonatomic) ZGLKVector4 diffuseColor;
@property (nonatomic) GLboolean enabled;
@property (nonatomic) GLfloat linearAttenuation;
@property (nonatomic) ZGLKVector4 position;
@property (nonatomic) GLfloat quadraticAttenuation;
@property (nonatomic) ZGLKVector4 specularColor;
@property (nonatomic) GLfloat spotCutoff;
@property (nonatomic) ZGLKVector3 spotDirection;
@property (nonatomic) GLfloat spotExponent;
@property (nonatomic, retain) ZGLKEffectPropertyTransform *transform;

@end
