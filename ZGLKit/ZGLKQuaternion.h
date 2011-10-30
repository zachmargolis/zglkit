//
//  ZGLKQuaternion.h
//  ZGLKit
//
//  Based directly on GLKQuaternion.h from Apple, Inc.
//

#ifndef ZGLKit_ZGLKQuaternion_h
#define ZGLKit_ZGLKQuaternion_h

#include <stddef.h>
#include <math.h>

#include <ZGLKit/ZGLKMathTypes.h>

#include <ZGLKit/ZGLKVector3.h>
#include <ZGLKit/ZGLKVector4.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark -
#pragma mark Prototypes
#pragma mark -

extern const ZGLKQuaternion ZGLKQuaternionIdentity; 

/*
 x, y, and z represent the imaginary values.
 */
static __inline__ ZGLKQuaternion ZGLKQuaternionMake(float x, float y, float z, float w);

/*
 vector represents the imaginary values.
 */
static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithVector3(ZGLKVector3 vector, float scalar);

/*
 values[0], values[1], and values[2] represent the imaginary values.
 */
static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithArray(float values[4]);

/*
 Assumes the axis is already normalized.
 */
static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithAngleAndAxis(float radians, float x, float y, float z);
/*
 Assumes the axis is already normalized.
 */
static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithAngleAndVector3Axis(float radians, ZGLKVector3 axisVector);

ZGLKQuaternion ZGLKQuaternionMakeWithMatrix3(ZGLKMatrix3 matrix);
ZGLKQuaternion ZGLKQuaternionMakeWithMatrix4(ZGLKMatrix4 matrix);

/*
 Calculate and return the angle component of the angle and axis form.
 */
float ZGLKQuaternionAngle(ZGLKQuaternion quaternion);

/*
 Calculate and return the axis component of the angle and axis form.
 */
ZGLKVector3 ZGLKQuaternionAxis(ZGLKQuaternion quaternion);

static __inline__ ZGLKQuaternion ZGLKQuaternionAdd(ZGLKQuaternion quaternionLeft, ZGLKQuaternion quaternionRight);
static __inline__ ZGLKQuaternion ZGLKQuaternionSubtract(ZGLKQuaternion quaternionLeft, ZGLKQuaternion quaternionRight);
static __inline__ ZGLKQuaternion ZGLKQuaternionMultiply(ZGLKQuaternion quaternionLeft, ZGLKQuaternion quaternionRight);

ZGLKQuaternion ZGLKQuaternionSlerp(ZGLKQuaternion quaternionStart, ZGLKQuaternion quaternionEnd, float t);

static __inline__ float ZGLKQuaternionLength(ZGLKQuaternion quaternion);

static __inline__ ZGLKQuaternion ZGLKQuaternionConjugate(ZGLKQuaternion quaternion);
static __inline__ ZGLKQuaternion ZGLKQuaternionInvert(ZGLKQuaternion quaternion);
static __inline__ ZGLKQuaternion ZGLKQuaternionNormalize(ZGLKQuaternion quaternion);

static __inline__ ZGLKVector3 ZGLKQuaternionRotateVector3(ZGLKQuaternion quaternion, ZGLKVector3 vector);
void ZGLKQuaternionRotateVector3Array(ZGLKQuaternion quaternion, ZGLKVector3 *vectors, size_t vectorCount);

/*
 The fourth component of the vector is ignored when calculating the rotation.
 */
static __inline__ ZGLKVector4 ZGLKQuaternionRotateVector4(ZGLKQuaternion quaternion, ZGLKVector4 vector);
void ZGLKQuaternionRotateVector4Array(ZGLKQuaternion quaternion, ZGLKVector4 *vectors, size_t vectorCount);

#pragma mark -
#pragma mark Implementations
#pragma mark -

static __inline__ ZGLKQuaternion ZGLKQuaternionMake(float x, float y, float z, float w)
{
    ZGLKQuaternion q = { x, y, z, w };
    return q;
}

static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithVector3(ZGLKVector3 vector, float scalar)
{
    ZGLKQuaternion q = { vector.v[0], vector.v[1], vector.v[2], scalar };
    return q;
}

static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithArray(float values[4])
{
    ZGLKQuaternion q = { values[0], values[1], values[2], values[3] };
    return q;
}

static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithAngleAndAxis(float radians, float x, float y, float z)
{
    float halfAngle = radians * 0.5f;
    float scale = sinf(halfAngle);
    ZGLKQuaternion q = { scale * x, scale * y, scale * z, cosf(halfAngle) };
    return q;
}

static __inline__ ZGLKQuaternion ZGLKQuaternionMakeWithAngleAndVector3Axis(float radians, ZGLKVector3 axisVector)
{
    return ZGLKQuaternionMakeWithAngleAndAxis(radians, axisVector.v[0], axisVector.v[1], axisVector.v[2]);
}

static __inline__ ZGLKQuaternion ZGLKQuaternionAdd(ZGLKQuaternion quaternionLeft, ZGLKQuaternion quaternionRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vaddq_f32(*(float32x4_t *)&quaternionLeft,
                              *(float32x4_t *)&quaternionRight);
    return *(ZGLKQuaternion *)&v;
#else
    ZGLKQuaternion q = { quaternionLeft.q[0] + quaternionRight.q[0],
        quaternionLeft.q[1] + quaternionRight.q[1],
        quaternionLeft.q[2] + quaternionRight.q[2],
        quaternionLeft.q[3] + quaternionRight.q[3] };
    return q;
#endif
}

static __inline__ ZGLKQuaternion ZGLKQuaternionSubtract(ZGLKQuaternion quaternionLeft, ZGLKQuaternion quaternionRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vsubq_f32(*(float32x4_t *)&quaternionLeft,
                              *(float32x4_t *)&quaternionRight);
    return *(ZGLKQuaternion *)&v;
#else
    ZGLKQuaternion q = { quaternionLeft.q[0] - quaternionRight.q[0],
        quaternionLeft.q[1] - quaternionRight.q[1],
        quaternionLeft.q[2] - quaternionRight.q[2],
        quaternionLeft.q[3] - quaternionRight.q[3] };
    return q;
#endif
}

static __inline__ ZGLKQuaternion ZGLKQuaternionMultiply(ZGLKQuaternion quaternionLeft, ZGLKQuaternion quaternionRight)
{
    ZGLKQuaternion q = { quaternionLeft.q[3] * quaternionRight.q[0] +
        quaternionLeft.q[0] * quaternionRight.q[3] +
        quaternionLeft.q[1] * quaternionRight.q[2] -
        quaternionLeft.q[2] * quaternionRight.q[1],
        
        quaternionLeft.q[3] * quaternionRight.q[1] +
        quaternionLeft.q[1] * quaternionRight.q[3] +
        quaternionLeft.q[2] * quaternionRight.q[0] -
        quaternionLeft.q[0] * quaternionRight.q[2],
        
        quaternionLeft.q[3] * quaternionRight.q[2] +
        quaternionLeft.q[2] * quaternionRight.q[3] +
        quaternionLeft.q[0] * quaternionRight.q[1] -
        quaternionLeft.q[1] * quaternionRight.q[0],
        
        quaternionLeft.q[3] * quaternionRight.q[3] -
        quaternionLeft.q[0] * quaternionRight.q[0] -
        quaternionLeft.q[1] * quaternionRight.q[1] -
        quaternionLeft.q[2] * quaternionRight.q[2] };
    return q;
}

static __inline__ float ZGLKQuaternionLength(ZGLKQuaternion quaternion)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vmulq_f32(*(float32x4_t *)&quaternion,
                              *(float32x4_t *)&quaternion);
    float32x2_t v2 = vpadd_f32(vget_low_f32(v), vget_high_f32(v));
    v2 = vpadd_f32(v2, v2);
    return sqrt(vget_lane_f32(v2, 0)); 
#else
    return sqrt(quaternion.q[0] * quaternion.q[0] + 
                quaternion.q[1] * quaternion.q[1] +
                quaternion.q[2] * quaternion.q[2] +
                quaternion.q[3] * quaternion.q[3]);
#endif
}

static __inline__ ZGLKQuaternion ZGLKQuaternionConjugate(ZGLKQuaternion quaternion)
{
#if defined(__ARM_NEON__)
    float32x4_t *q = (float32x4_t *)&quaternion;
    
    uint32_t signBit = 0x80000000;
    uint32_t zeroBit = 0x0;
    uint32x4_t mask = vdupq_n_u32(signBit);
    mask = vsetq_lane_u32(zeroBit, mask, 3);
    *q = vreinterpretq_f32_u32(veorq_u32(vreinterpretq_u32_f32(*q), mask));
    
    return *(ZGLKQuaternion *)q;
#else
    ZGLKQuaternion q = { -quaternion.q[0], -quaternion.q[1], -quaternion.q[2], quaternion.q[3] };
    return q;
#endif
}

static __inline__ ZGLKQuaternion ZGLKQuaternionInvert(ZGLKQuaternion quaternion)
{
#if defined(__ARM_NEON__)
    float32x4_t *q = (float32x4_t *)&quaternion;
    float32x4_t v = vmulq_f32(*q, *q);
    float32x2_t v2 = vpadd_f32(vget_low_f32(v), vget_high_f32(v));
    v2 = vpadd_f32(v2, v2);
    float32_t scale = 1.0f / vget_lane_f32(v2, 0);
    v = vmulq_f32(*q, vdupq_n_f32(scale));
    
    uint32_t signBit = 0x80000000;
    uint32_t zeroBit = 0x0;
    uint32x4_t mask = vdupq_n_u32(signBit);
    mask = vsetq_lane_u32(zeroBit, mask, 3);
    v = vreinterpretq_f32_u32(veorq_u32(vreinterpretq_u32_f32(v), mask));
    
    return *(ZGLKQuaternion *)&v;
#else
    float scale = 1.0f / (quaternion.q[0] * quaternion.q[0] + 
                          quaternion.q[1] * quaternion.q[1] +
                          quaternion.q[2] * quaternion.q[2] +
                          quaternion.q[3] * quaternion.q[3]);
    ZGLKQuaternion q = { -quaternion.q[0] * scale, -quaternion.q[1] * scale, -quaternion.q[2] * scale, quaternion.q[3] * scale };
    return q;
#endif
}

static __inline__ ZGLKQuaternion ZGLKQuaternionNormalize(ZGLKQuaternion quaternion)
{
    float scale = 1.0f / ZGLKQuaternionLength(quaternion);
#if defined(__ARM_NEON__)
    float32x4_t v = vmulq_f32(*(float32x4_t *)&quaternion,
                              vdupq_n_f32((float32_t)scale));
    return *(ZGLKQuaternion *)&v;
#else
    ZGLKQuaternion q = { quaternion.q[0] * scale, quaternion.q[1] * scale, quaternion.q[2] * scale, quaternion.q[3] * scale };
    return q;
#endif
}

static __inline__ ZGLKVector3 ZGLKQuaternionRotateVector3(ZGLKQuaternion quaternion, ZGLKVector3 vector)
{
    ZGLKQuaternion rotatedQuaternion = ZGLKQuaternionMake(vector.v[0], vector.v[1], vector.v[2], 0.0f);
    rotatedQuaternion = ZGLKQuaternionMultiply(ZGLKQuaternionMultiply(quaternion, rotatedQuaternion), ZGLKQuaternionInvert(quaternion));
    
    return ZGLKVector3Make(rotatedQuaternion.q[0], rotatedQuaternion.q[1], rotatedQuaternion.q[2]);
}

static __inline__ ZGLKVector4 ZGLKQuaternionRotateVector4(ZGLKQuaternion quaternion, ZGLKVector4 vector)
{
    ZGLKQuaternion rotatedQuaternion = ZGLKQuaternionMake(vector.v[0], vector.v[1], vector.v[2], 0.0f);
    rotatedQuaternion = ZGLKQuaternionMultiply(ZGLKQuaternionMultiply(quaternion, rotatedQuaternion), ZGLKQuaternionInvert(quaternion));
    
    return ZGLKVector4Make(rotatedQuaternion.q[0], rotatedQuaternion.q[1], rotatedQuaternion.q[2], vector.v[3]);
}

#ifdef __cplusplus
}
#endif

#endif // ZGLKit_ZGLKQuaternion_h
