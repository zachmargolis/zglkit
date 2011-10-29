//
//  ZGLKBaseEffect.m
//  ZGLKit
//
//  Created by Zach Margolis on 10/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "ZGLKBaseEffect.h"
#import "ZGLKEffectPropertyLight.h"

@interface ZGLKEffectPropertyLight (ZGLKBaseEffect)

- (void)configureEffect;

@end

@implementation ZGLKBaseEffect

@synthesize colorMaterialEnabled = _colorMaterialEnabled;
@synthesize constantColor = _constantColor;
@synthesize fog = _fog;
@synthesize label = _label;
@synthesize light0 = _light0;
@synthesize light1 = _light1;
@synthesize light2 = _light2;
@synthesize lightingType = _lightingType;
@synthesize lightModelAmbientColor = _lightModelAmbientColor;
@synthesize lightModelTwoSided = _lightModelTwoSided;
@synthesize material = _material;
@synthesize texture2d0 = _texture2d0;
@synthesize texture2d1 = _texture2d1;
@synthesize textureOrder = _textureOrder;
@synthesize texturingEnabled = _texturingEnabled;
@synthesize transform = _transform;
@synthesize useConstantColor = _useConstantColor;

#pragma mark ZGLKNamedEffect

- (void)prepareToDraw;
{
    [_light0 configureEffect];
    [_light1 configureEffect];
    [_light2 configureEffect];
}

@end

@implementation ZGLKEffectPropertyLight

- (void)configureEffect;
{
    if (!self.enabled) {
        return;
    }
}

@end
