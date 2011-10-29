//
//  ZGKLBaseEffect.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "ZGLKEffectPropertyLight.h"
#import "ZGLKNamedEffect.h"
#import "ZGLKVector4.h"

@class ZGLKEffectPropertyFog;
@class ZGLKEffectPropertyMaterial;
@class ZGLKEffectPropertyTexture;
@class ZGLKEffectPropertyTransform;

@interface ZGLKBaseEffect : NSObject <ZGLKNamedEffect>

@property (nonatomic) GLboolean colorMaterialEnabled;
@property (nonatomic) ZGLKVector4 constantColor;
@property (nonatomic, readonly) ZGLKEffectPropertyFog *fog;
@property (nonatomic, retain) NSString *label;
@property (nonatomic, readonly) ZGLKEffectPropertyLight *light0;
@property (nonatomic, readonly) ZGLKEffectPropertyLight *light1;
@property (nonatomic, readonly) ZGLKEffectPropertyLight *light2;
@property (nonatomic, assign) ZGLKLightingType lightingType;
@property (nonatomic, assign) ZGLKVector4 lightModelAmbientColor;
@property (nonatomic, assign) GLboolean lightModelTwoSided;
@property (nonatomic, readonly) ZGLKEffectPropertyMaterial *material;
@property (nonatomic, readonly) ZGLKEffectPropertyTexture *texture2d0;
@property (nonatomic, readonly) ZGLKEffectPropertyTexture *texture2d1;
@property (nonatomic, retain) NSArray *textureOrder;
@property (nonatomic, assign) GLboolean texturingEnabled;
@property (nonatomic, readonly) ZGLKEffectPropertyTransform *transform;
@property (nonatomic, assign) GLboolean useConstantColor;

@end
