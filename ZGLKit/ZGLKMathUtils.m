//
//  ZGLKMathUtils.m
//  ZGLKit
//
//  Based directly on GLKMathUtils.h from Apple, Inc.
//

#import "ZGLKMathUtils.h"
#import "ZGLKVector3.h"
#import "ZGLKMatrix4.h"

ZGLKVector3 ZGLKMathProject(ZGLKVector3 object, ZGLKMatrix4 model, ZGLKMatrix4 projection, int *viewport) {
    assert(viewport);
    ZGLKVector3 v = ZGLKMatrix4MultiplyVector3(ZGLKMatrix4Multiply(model, projection), object);
    
    GLfloat x = viewport[0] + ((viewport[2] * (v.x + 1.0f)) / 2.0f);
    GLfloat y = viewport[1] + ((viewport[3] * (v.y + 1.0f)) / 2.0f);
    GLfloat z = (v.z + 1.0f) / 2.0f;
    return ZGLKVector3Make(x, y, z);
}

ZGLKVector3 ZGLKMathUnproject(ZGLKVector3 window, ZGLKMatrix4 model, ZGLKMatrix4 projection, int *viewport, bool *success) {
    assert(viewport);
    bool canInvert = false;
    ZGLKMatrix4 inverted = ZGLKMatrix4Invert(ZGLKMatrix4Multiply(projection, model), &canInvert);
    if (success) {
        *success = canInvert;
    }
    
    if (!canInvert) {
        return ZGLKVector3Make(0.0f, 0.0f, 0.0f);
    }
    
    GLfloat x = ((2.0f * window.x - viewport[0]) / viewport[2]) - 1.0f;
    GLfloat y = ((2.0f * window.y - viewport[1]) / viewport[3]) - 1.0f;
    GLfloat z = (2.0f * window.z) - 1.0f;
    ZGLKVector4 unproject4 = ZGLKMatrix4MultiplyVector4(inverted, ZGLKVector4Make(x, y, z, 1.0f));
    return ZGLKVector3Make(unproject4.x, unproject4.y, unproject4.z);
}

#ifdef __OBJC__
NSString *NSStringFromZGLKMatrix2(ZGLKMatrix2 matrix) {
    return nil;
}

NSString *NSStringFromZGLKMatrix3(ZGLKMatrix3 matrix) {
    return nil;
}

NSString *NSStringFromZGLKMatrix4(ZGLKMatrix4 matrix) {
    return nil;
}

NSString *NSStringFromZGLKVector2(ZGLKVector2 vector) {
    return nil;    
}

NSString *NSStringFromZGLKVector3(ZGLKVector3 vector) {
    return nil;
}

NSString *NSStringFromZGLKVector4(ZGLKVector4 vector) {
    return nil;
}

NSString *NSStringFromZGLKQuaternion(ZGLKQuaternion quaternion) {
    return nil;
}

#endif // __OBJC__
