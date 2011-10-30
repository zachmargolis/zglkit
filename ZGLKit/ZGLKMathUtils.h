//
//  ZGLKMathUtils.h
//  ZGLKit
//
//  Based directly on GLKMathUtils.h from Apple, Inc.
//

#include <math.h>
#include <stdbool.h>

#include <ZGLKit/ZGLKMathTypes.h>

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
    
static __inline__ float ZGLKMathDegreesToRadians(float degrees) { return degrees * (M_PI / 180); };
static __inline__ float ZGLKMathRadiansToDegrees(float radians) { return radians * (180 / M_PI); };

ZGLKVector3 ZGLKMathProject(ZGLKVector3 object, ZGLKMatrix4 model, ZGLKMatrix4 projection, int *viewport);
ZGLKVector3 ZGLKMathUnproject(ZGLKVector3 window, ZGLKMatrix4 model, ZGLKMatrix4 projection, int *viewport, bool *success);

#ifdef __OBJC__
NSString *NSStringFromZGLKMatrix2(ZGLKMatrix2 matrix);
NSString *NSStringFromZGLKMatrix3(ZGLKMatrix3 matrix);
NSString *NSStringFromZGLKMatrix4(ZGLKMatrix4 matrix);

NSString *NSStringFromZGLKVector2(ZGLKVector2 vector);
NSString *NSStringFromZGLKVector3(ZGLKVector3 vector);
NSString *NSStringFromZGLKVector4(ZGLKVector4 vector);

NSString *NSStringFromZGLKQuaternion(ZGLKQuaternion quaternion);
#endif
    
#ifdef __cplusplus
}
#endif
