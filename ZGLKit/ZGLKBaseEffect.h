//
//  ZGKLBaseEffect.h
//  ZGLKit
//
//  Created by Zach Margolis on 10/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZGLKNamedEffect.h"
#import "ZGLKVector4.h"

@class GLKEffectPropertyFog;
@class GLKEffectPropertyLight;
@class GLKEffectPropertyMaterial;
@class GLKEffectPropertyTexture;

@interface ZGLKBaseEffect : NSObject <ZGLKNamedEffect>
/*
@property (nonatomic) GLboolean colorMaterialEnabled;
@property (nonatomic) ZGLKVector4 constantColor;
@property (nonatomic, readonly) GLKEffectPropertyFog *fog;
@property (nonatomic, retain) NSString *label;
@property (nonatomic, readonly) GLKEffectPropertyLight *light0;
@property (nonatomic, readonly) GLKEffectPropertyLight *light1;
@property (nonatomic, readonly) GLKEffectPropertyLight *light2;
@property (nonatomic, assign) GLKLightingType lightingType;
@property (nonatomic, assign) ZGLKVector4 lightModelAmbientColor;
@property (nonatomic, assign) GLboolean lightModelTwoSided;
@property (nonatomic, readonly) GLKEffectPropertyMaterial *material;
@property (nonatomic, readonly) GLKEffectPropertyTexture *texture2d0;
@property (nonatomic, readonly) GLKEffectPropertyTexture *texture2d1;
@property (nonatomic, retain) NSArray *textureOrder;
@property (nonatomic, assign) GLboolean texturingEnabled;
@property (nonatomic, readonly) GLKEffectPropertyTransform *transform;
@property (nonatomic, assign) GLboolean useConstantColor;
*/
@end
