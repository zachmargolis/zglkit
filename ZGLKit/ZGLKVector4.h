//
//  ZGLKVector4.h
//  ZGLKit
//
//  Based directly on GLKVector4.h from Apple, Inc.
//

#ifndef ZGLKit_ZGLKVector4_h
#define ZGLKit_ZGLKVector4_h

#include <stdbool.h>
#include <math.h>

#if defined(__ARM_NEON__)
#include <arm_neon.h>
#endif

#include <ZGLKit/ZGLKMathTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark -
#pragma mark Prototypes
#pragma mark -

static __inline__ ZGLKVector4 ZGLKVector4Make(float x, float y, float z, float w);
static __inline__ ZGLKVector4 ZGLKVector4MakeWithArray(float values[4]);
static __inline__ ZGLKVector4 ZGLKVector4MakeWithVector3(ZGLKVector3 vector, float w);

static __inline__ ZGLKVector4 ZGLKVector4Negate(ZGLKVector4 vector);

static __inline__ ZGLKVector4 ZGLKVector4Add(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
static __inline__ ZGLKVector4 ZGLKVector4Subtract(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
static __inline__ ZGLKVector4 ZGLKVector4Multiply(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
static __inline__ ZGLKVector4 ZGLKVector4Divide(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);

static __inline__ ZGLKVector4 ZGLKVector4AddScalar(ZGLKVector4 vector, float value);
static __inline__ ZGLKVector4 ZGLKVector4SubtractScalar(ZGLKVector4 vector, float value);
static __inline__ ZGLKVector4 ZGLKVector4MultiplyScalar(ZGLKVector4 vector, float value);
static __inline__ ZGLKVector4 ZGLKVector4DivideScalar(ZGLKVector4 vector, float value);

/*
 Returns a vector whose elements are the larger of the corresponding elements of the vector arguments.
 */
static __inline__ ZGLKVector4 ZGLKVector4Maximum(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
/*
 Returns a vector whose elements are the smaller of the corresponding elements of the vector arguments.
 */
static __inline__ ZGLKVector4 ZGLKVector4Minimum(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);

/*
 Returns true if all of the first vector's elements are equal to all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector4AllEqualToVector4(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
/*
 Returns true if all of the vector's elements are equal to the provided value.
 */
static __inline__ bool ZGLKVector4AllEqualToScalar(ZGLKVector4 vector, float value);
/*
 Returns true if all of the first vector's elements are greater than all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector4AllGreaterThanVector4(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
/*
 Returns true if all of the vector's elements are greater than the provided value.
 */
static __inline__ bool ZGLKVector4AllGreaterThanScalar(ZGLKVector4 vector, float value);
/*
 Returns true if all of the first vector's elements are greater than or equal to all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector4AllGreaterThanOrEqualToVector4(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
/*
 Returns true if all of the vector's elements are greater than or equal to the provided value.
 */
static __inline__ bool ZGLKVector4AllGreaterThanOrEqualToScalar(ZGLKVector4 vector, float value);

static __inline__ ZGLKVector4 ZGLKVector4Normalize(ZGLKVector4 vector);

static __inline__ float ZGLKVector4DotProduct(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);
static __inline__ float ZGLKVector4Length(ZGLKVector4 vector);
static __inline__ float ZGLKVector4Distance(ZGLKVector4 vectorStart, ZGLKVector4 vectorEnd);

static __inline__ ZGLKVector4 ZGLKVector4Lerp(ZGLKVector4 vectorStart, ZGLKVector4 vectorEnd, float t);

/*
 Performs a 3D cross product. The last component of the resulting cross product will be zeroed out.
 */
static __inline__ ZGLKVector4 ZGLKVector4CrossProduct(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight);

/*
 Project the vector, vectorToProject, onto the vector, projectionVector.
 */
static __inline__ ZGLKVector4 ZGLKVector4Project(ZGLKVector4 vectorToProject, ZGLKVector4 projectionVector);

#pragma mark -
#pragma mark Implementations
#pragma mark -

static __inline__ ZGLKVector4 ZGLKVector4Make(float x, float y, float z, float w)
{
    ZGLKVector4 v = { x, y, z, w };
    return v;
}

static __inline__ ZGLKVector4 ZGLKVector4MakeWithArray(float values[4])
{
#if defined(__ARM_NEON__)
    float32x4_t v = vld1q_f32(values);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { values[0], values[1], values[2], values[3] };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4MakeWithVector3(ZGLKVector3 vector, float w)
{
    ZGLKVector4 v = { vector.v[0], vector.v[1], vector.v[2], w };
    return v;
}

static __inline__ ZGLKVector4 ZGLKVector4Negate(ZGLKVector4 vector)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vnegq_f32(*(float32x4_t *)&vector);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { -vector.v[0], -vector.v[1], -vector.v[2], -vector.v[3] };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4Add(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vaddq_f32(*(float32x4_t *)&vectorLeft,
                              *(float32x4_t *)&vectorRight);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vectorLeft.v[0] + vectorRight.v[0],
        vectorLeft.v[1] + vectorRight.v[1],
        vectorLeft.v[2] + vectorRight.v[2],
        vectorLeft.v[3] + vectorRight.v[3] };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4Subtract(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vsubq_f32(*(float32x4_t *)&vectorLeft,
                              *(float32x4_t *)&vectorRight);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vectorLeft.v[0] - vectorRight.v[0],
        vectorLeft.v[1] - vectorRight.v[1],
        vectorLeft.v[2] - vectorRight.v[2],
        vectorLeft.v[3] - vectorRight.v[3] };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4Multiply(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vmulq_f32(*(float32x4_t *)&vectorLeft,
                              *(float32x4_t *)&vectorRight);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vectorLeft.v[0] * vectorRight.v[0],
        vectorLeft.v[1] * vectorRight.v[1],
        vectorLeft.v[2] * vectorRight.v[2],
        vectorLeft.v[3] * vectorRight.v[3] };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4Divide(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x4_t *vLeft = (float32x4_t *)&vectorLeft;
    float32x4_t *vRight = (float32x4_t *)&vectorRight;
    float32x4_t estimate = vrecpeq_f32(*vRight);    
    estimate = vmulq_f32(vrecpsq_f32(*vRight, estimate), estimate);
    estimate = vmulq_f32(vrecpsq_f32(*vRight, estimate), estimate);
    float32x4_t v = vmulq_f32(*vLeft, estimate);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vectorLeft.v[0] / vectorRight.v[0],
        vectorLeft.v[1] / vectorRight.v[1],
        vectorLeft.v[2] / vectorRight.v[2],
        vectorLeft.v[3] / vectorRight.v[3] };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4AddScalar(ZGLKVector4 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vaddq_f32(*(float32x4_t *)&vector,
                              vdupq_n_f32((float32_t)value));
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vector.v[0] + value,
        vector.v[1] + value,
        vector.v[2] + value,
        vector.v[3] + value };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4SubtractScalar(ZGLKVector4 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vsubq_f32(*(float32x4_t *)&vector,
                              vdupq_n_f32((float32_t)value));
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vector.v[0] - value,
        vector.v[1] - value,
        vector.v[2] - value,
        vector.v[3] - value };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4MultiplyScalar(ZGLKVector4 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vmulq_f32(*(float32x4_t *)&vector,
                              vdupq_n_f32((float32_t)value));
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vector.v[0] * value,
        vector.v[1] * value,
        vector.v[2] * value,
        vector.v[3] * value };
    return v;   
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4DivideScalar(ZGLKVector4 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x4_t values = vdupq_n_f32((float32_t)value);
    float32x4_t estimate = vrecpeq_f32(values);    
    estimate = vmulq_f32(vrecpsq_f32(values, estimate), estimate);
    estimate = vmulq_f32(vrecpsq_f32(values, estimate), estimate);
    float32x4_t v = vmulq_f32(*(float32x4_t *)&vector, estimate);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vector.v[0] / value,
        vector.v[1] / value,
        vector.v[2] / value,
        vector.v[3] / value };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4Maximum(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vmaxq_f32(*(float32x4_t *)&vectorLeft,
                              *(float32x4_t *)&vectorRight);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 max = vectorLeft;
    if (vectorRight.v[0] > vectorLeft.v[0])
        max.v[0] = vectorRight.v[0];
    if (vectorRight.v[1] > vectorLeft.v[1])
        max.v[1] = vectorRight.v[1];
    if (vectorRight.v[2] > vectorLeft.v[2])
        max.v[2] = vectorRight.v[2];
    if (vectorRight.v[3] > vectorLeft.v[3])
        max.v[3] = vectorRight.v[3];
    return max;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4Minimum(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vminq_f32(*(float32x4_t *)&vectorLeft,
                              *(float32x4_t *)&vectorRight);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 min = vectorLeft;
    if (vectorRight.v[0] < vectorLeft.v[0])
        min.v[0] = vectorRight.v[0];
    if (vectorRight.v[1] < vectorLeft.v[1])
        min.v[1] = vectorRight.v[1];
    if (vectorRight.v[2] < vectorLeft.v[2])
        min.v[2] = vectorRight.v[2];
    if (vectorRight.v[3] < vectorLeft.v[3])
        min.v[3] = vectorRight.v[3];
    return min;
#endif
}

static __inline__ bool ZGLKVector4AllEqualToVector4(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON_)
    float32x4_t v1 = *(float32x4_t *)&vectorLeft;
    float32x4_t v2 = *(float32x4_t *)&vectorRight;
    uint32x4_t vCmp = vceqq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vget_low_u32(vCmp), vget_high_u32(vCmp));
    vAnd = vand_u32(vAnd, vext_u32(vAnd, vAnd, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vectorLeft.v[0] == vectorRight.v[0] &&
        vectorLeft.v[1] == vectorRight.v[1] &&
        vectorLeft.v[2] == vectorRight.v[2] &&
        vectorLeft.v[3] == vectorRight.v[3])
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector4AllEqualToScalar(ZGLKVector4 vector, float value)
{
#if defined(__ARM_NEON_)
    float32x4_t v1 = *(float32x4_t *)&vector;
    float32x4_t v2 = vdupq_n_f32(value);
    uint32x4_t vCmp = vceqq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vget_low_u32(vCmp), vget_high_u32(vCmp));
    vAnd = vand_u32(vAnd, vext_u32(vAnd, vAnd, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vector.v[0] == value &&
        vector.v[1] == value &&
        vector.v[2] == value &&
        vector.v[3] == value)
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector4AllGreaterThanVector4(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON_)
    float32x4_t v1 = *(float32x4_t *)&vectorLeft;
    float32x4_t v2 = *(float32x4_t *)&vectorRight;
    uint32x4_t vCmp = vcgtq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vget_low_u32(vCmp), vget_high_u32(vCmp));
    vAnd = vand_u32(vAnd, vext_u32(vAnd, vAnd, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vectorLeft.v[0] > vectorRight.v[0] &&
        vectorLeft.v[1] > vectorRight.v[1] &&
        vectorLeft.v[2] > vectorRight.v[2] &&
        vectorLeft.v[3] > vectorRight.v[3])
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector4AllGreaterThanScalar(ZGLKVector4 vector, float value)
{
#if defined(__ARM_NEON_)
    float32x4_t v1 = *(float32x4_t *)&vector;
    float32x4_t v2 = vdupq_n_f32(value);
    uint32x4_t vCmp = vcgtq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vget_low_u32(vCmp), vget_high_u32(vCmp));
    vAnd = vand_u32(vAnd, vext_u32(vAnd, vAnd, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vector.v[0] > value &&
        vector.v[1] > value &&
        vector.v[2] > value &&
        vector.v[3] > value)
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector4AllGreaterThanOrEqualToVector4(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON_)
    float32x4_t v1 = *(float32x4_t *)&vectorLeft;
    float32x4_t v2 = *(float32x4_t *)&vectorRight;
    uint32x4_t vCmp = vcgeq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vget_low_u32(vCmp), vget_high_u32(vCmp));
    vAnd = vand_u32(vAnd, vext_u32(vAnd, vAnd, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vectorLeft.v[0] >= vectorRight.v[0] &&
        vectorLeft.v[1] >= vectorRight.v[1] &&
        vectorLeft.v[2] >= vectorRight.v[2] &&
        vectorLeft.v[3] >= vectorRight.v[3])
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector4AllGreaterThanOrEqualToScalar(ZGLKVector4 vector, float value)
{
#if defined(__ARM_NEON_)
    float32x4_t v1 = *(float32x4_t *)&vector;
    float32x4_t v2 = vdupq_n_f32(value);
    uint32x4_t vCmp = vcgeq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vget_low_u32(vCmp), vget_high_u32(vCmp));
    vAnd = vand_u32(vAnd, vext_u32(vAnd, vAnd, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vector.v[0] >= value &&
        vector.v[1] >= value &&
        vector.v[2] >= value &&
        vector.v[3] >= value)
        compare = true;
    return compare;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4Normalize(ZGLKVector4 vector)
{
    float scale = 1.0f / ZGLKVector4Length(vector);
    ZGLKVector4 v = ZGLKVector4MultiplyScalar(vector, scale);
    return v;
}

static __inline__ float ZGLKVector4DotProduct(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vmulq_f32(*(float32x4_t *)&vectorLeft,
                              *(float32x4_t *)&vectorRight);
    float32x2_t v2 = vpadd_f32(vget_low_f32(v), vget_high_f32(v));
    v2 = vpadd_f32(v2, v2);
    return vget_lane_f32(v2, 0);
#else
    return vectorLeft.v[0] * vectorRight.v[0] +
    vectorLeft.v[1] * vectorRight.v[1] +
    vectorLeft.v[2] * vectorRight.v[2] +
    vectorLeft.v[3] * vectorRight.v[3];
#endif
}

static __inline__ float ZGLKVector4Length(ZGLKVector4 vector)
{
#if defined(__ARM_NEON__)
    float32x4_t v = vmulq_f32(*(float32x4_t *)&vector,
                              *(float32x4_t *)&vector);
    float32x2_t v2 = vpadd_f32(vget_low_f32(v), vget_high_f32(v));
    v2 = vpadd_f32(v2, v2);
    return sqrt(vget_lane_f32(v2, 0));
#else
    return sqrt(vector.v[0] * vector.v[0] +
                vector.v[1] * vector.v[1] +
                vector.v[2] * vector.v[2] +
                vector.v[3] * vector.v[3]);
#endif
}

static __inline__ float ZGLKVector4Distance(ZGLKVector4 vectorStart, ZGLKVector4 vectorEnd)
{
    return ZGLKVector4Length(ZGLKVector4Subtract(vectorEnd, vectorStart));
}

static __inline__ ZGLKVector4 ZGLKVector4Lerp(ZGLKVector4 vectorStart, ZGLKVector4 vectorEnd, float t)
{
#if defined(__ARM_NEON__)
    float32x4_t vDiff = vsubq_f32(*(float32x4_t *)&vectorEnd,
                                  *(float32x4_t *)&vectorStart);
    vDiff = vmulq_f32(vDiff, vdupq_n_f32((float32_t)t));
    float32x4_t v = vaddq_f32(*(float32x4_t *)&vectorStart, vDiff);
    return *(ZGLKVector4 *)&v;
#else
    ZGLKVector4 v = { vectorStart.v[0] + ((vectorEnd.v[0] - vectorStart.v[0]) * t),
        vectorStart.v[1] + ((vectorEnd.v[1] - vectorStart.v[1]) * t),
        vectorStart.v[2] + ((vectorEnd.v[2] - vectorStart.v[2]) * t),
        vectorStart.v[3] + ((vectorEnd.v[3] - vectorStart.v[3]) * t) };
    return v;
#endif
}

static __inline__ ZGLKVector4 ZGLKVector4CrossProduct(ZGLKVector4 vectorLeft, ZGLKVector4 vectorRight)
{
    ZGLKVector4 v = { vectorLeft.v[1] * vectorRight.v[2] - vectorLeft.v[2] * vectorRight.v[1],
        vectorLeft.v[2] * vectorRight.v[0] - vectorLeft.v[0] * vectorRight.v[2],
        vectorLeft.v[0] * vectorRight.v[1] - vectorLeft.v[1] * vectorRight.v[0],
        0.0f };
    return v;
}

static __inline__ ZGLKVector4 ZGLKVector4Project(ZGLKVector4 vectorToProject, ZGLKVector4 projectionVector)
{
    float scale = ZGLKVector4DotProduct(projectionVector, vectorToProject) / ZGLKVector4DotProduct(projectionVector, projectionVector);
    ZGLKVector4 v = ZGLKVector4MultiplyScalar(projectionVector, scale);
    return v;
}

#ifdef __cplusplus
}
#endif

#endif // ZGLKit_ZGLKVector4_h
