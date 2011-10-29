//
//  ZGLKVector2.h
//  ZGLKit
//
//  Based directly on GLKVector2.h from Apple, Inc.
//

#ifndef ZGLKit_ZGLKVector2_h
#define ZGLKit_ZGLKVector2_h

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

static __inline__ ZGLKVector2 ZGLKVector2Make(float x, float y);
static __inline__ ZGLKVector2 ZGLKVector2MakeWithArray(float values[2]);

static __inline__ ZGLKVector2 ZGLKVector2Negate(ZGLKVector2 vector);

static __inline__ ZGLKVector2 ZGLKVector2Add(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
static __inline__ ZGLKVector2 ZGLKVector2Subtract(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
static __inline__ ZGLKVector2 ZGLKVector2Multiply(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
static __inline__ ZGLKVector2 ZGLKVector2Divide(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);

static __inline__ ZGLKVector2 ZGLKVector2AddScalar(ZGLKVector2 vector, float value);
static __inline__ ZGLKVector2 ZGLKVector2SubtractScalar(ZGLKVector2 vector, float value);
static __inline__ ZGLKVector2 ZGLKVector2MultiplyScalar(ZGLKVector2 vector, float value);
static __inline__ ZGLKVector2 ZGLKVector2DivideScalar(ZGLKVector2 vector, float value);

/*
 Returns a vector whose elements are the larger of the corresponding elements of the vector arguments.
 */
static __inline__ ZGLKVector2 ZGLKVector2Maximum(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
/*
 Returns a vector whose elements are the smaller of the corresponding elements of the vector arguments.
 */
static __inline__ ZGLKVector2 ZGLKVector2Minimum(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);

/*
 Returns true if all of the first vector's elements are equal to all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector2AllEqualToVector2(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
/*
 Returns true if all of the vector's elements are equal to the provided value.
 */
static __inline__ bool ZGLKVector2AllEqualToScalar(ZGLKVector2 vector, float value);
/*
 Returns true if all of the first vector's elements are greater than all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector2AllGreaterThanVector2(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
/*
 Returns true if all of the vector's elements are greater than the provided value.
 */
static __inline__ bool ZGLKVector2AllGreaterThanScalar(ZGLKVector2 vector, float value);
/*
 Returns true if all of the first vector's elements are greater than or equal to all of the second vector's arguments.
 */
static __inline__ bool ZGLKVector2AllGreaterThanOrEqualToVector2(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
/*
 Returns true if all of the vector's elements are greater than or equal to the provided value.
 */
static __inline__ bool ZGLKVector2AllGreaterThanOrEqualToScalar(ZGLKVector2 vector, float value);

static __inline__ ZGLKVector2 ZGLKVector2Normalize(ZGLKVector2 vector);

static __inline__ float ZGLKVector2DotProduct(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight);
static __inline__ float ZGLKVector2Length(ZGLKVector2 vector);
static __inline__ float ZGLKVector2Distance(ZGLKVector2 vectorStart, ZGLKVector2 vectorEnd);

static __inline__ ZGLKVector2 ZGLKVector2Lerp(ZGLKVector2 vectorStart, ZGLKVector2 vectorEnd, float t);

/*
 Project the vector, vectorToProject, onto the vector, projectionVector.
 */
static __inline__ ZGLKVector2 ZGLKVector2Project(ZGLKVector2 vectorToProject, ZGLKVector2 projectionVector);

#pragma mark -
#pragma mark Implementations
#pragma mark -

static __inline__ ZGLKVector2 ZGLKVector2Make(float x, float y)
{
    ZGLKVector2 v = { x, y };
    return v;
}

static __inline__ ZGLKVector2 ZGLKVector2MakeWithArray(float values[2])
{
#if defined(__ARM_NEON__)
    float32x2_t v = vld1_f32(values);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { values[0], values[1] };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Negate(ZGLKVector2 vector)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vneg_f32(*(float32x2_t *)&vector);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { -vector.v[0] , -vector.v[1] };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Add(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vadd_f32(*(float32x2_t *)&vectorLeft,
                             *(float32x2_t *)&vectorRight);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vectorLeft.v[0] + vectorRight.v[0],
        vectorLeft.v[1] + vectorRight.v[1] };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Subtract(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vsub_f32(*(float32x2_t *)&vectorLeft,
                             *(float32x2_t *)&vectorRight);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vectorLeft.v[0] - vectorRight.v[0],
        vectorLeft.v[1] - vectorRight.v[1] };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Multiply(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vmul_f32(*(float32x2_t *)&vectorLeft,
                             *(float32x2_t *)&vectorRight);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vectorLeft.v[0] * vectorRight.v[0],
        vectorLeft.v[1] * vectorRight.v[1] };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Divide(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x2_t *vLeft = (float32x2_t *)&vectorLeft;
    float32x2_t *vRight = (float32x2_t *)&vectorRight;
    float32x2_t estimate = vrecpe_f32(*vRight);    
    estimate = vmul_f32(vrecps_f32(*vRight, estimate), estimate);
    estimate = vmul_f32(vrecps_f32(*vRight, estimate), estimate);
    float32x2_t v = vmul_f32(*vLeft, estimate);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vectorLeft.v[0] / vectorRight.v[0],
        vectorLeft.v[1] / vectorRight.v[1] };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2AddScalar(ZGLKVector2 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vadd_f32(*(float32x2_t *)&vector,
                             vdup_n_f32((float32_t)value));
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vector.v[0] + value,
        vector.v[1] + value };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2SubtractScalar(ZGLKVector2 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vsub_f32(*(float32x2_t *)&vector,
                             vdup_n_f32((float32_t)value));
    return *(ZGLKVector2 *)&v;
#else    
    ZGLKVector2 v = { vector.v[0] - value,
        vector.v[1] - value };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2MultiplyScalar(ZGLKVector2 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vmul_f32(*(float32x2_t *)&vector,
                             vdup_n_f32((float32_t)value));
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vector.v[0] * value,
        vector.v[1] * value };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2DivideScalar(ZGLKVector2 vector, float value)
{
#if defined(__ARM_NEON__)
    float32x2_t values = vdup_n_f32((float32_t)value);
    float32x2_t estimate = vrecpe_f32(values);    
    estimate = vmul_f32(vrecps_f32(values, estimate), estimate);
    estimate = vmul_f32(vrecps_f32(values, estimate), estimate);
    float32x2_t v = vmul_f32(*(float32x2_t *)&vector, estimate);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vector.v[0] / value,
        vector.v[1] / value };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Maximum(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vmax_f32(*(float32x2_t *)&vectorLeft,
                             *(float32x2_t *)&vectorRight);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 max = vectorLeft;
    if (vectorRight.v[0] > vectorLeft.v[0])
        max.v[0] = vectorRight.v[0];
    if (vectorRight.v[1] > vectorLeft.v[1])
        max.v[1] = vectorRight.v[1];
    return max;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Minimum(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vmin_f32(*(float32x2_t *)&vectorLeft,
                             *(float32x2_t *)&vectorRight);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 min = vectorLeft;
    if (vectorRight.v[0] < vectorLeft.v[0])
        min.v[0] = vectorRight.v[0];
    if (vectorRight.v[1] < vectorLeft.v[1])
        min.v[1] = vectorRight.v[1];
    return min;
#endif
}

static __inline__ bool ZGLKVector2AllEqualToVector2(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON_)
    float32x2_t v1 = *(float32x2_t *)&vectorLeft;
    float32x2_t v2 = *(float32x2_t *)&vectorRight;
    uint32x2_t vCmp = vceq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vCmp, vext_u32(vCmp, vCmp, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vectorLeft.v[0] == vectorRight.v[0] &&
        vectorLeft.v[1] == vectorRight.v[1])
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector2AllEqualToScalar(ZGLKVector2 vector, float value)
{
#if defined(__ARM_NEON_)
    float32x2_t v1 = *(float32x2_t *)&vector;
    float32x2_t v2 = vdup_n_f32(value);
    uint32x2_t vCmp = vceq_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vCmp, vext_u32(vCmp, vCmp, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vector.v[0] == value &&
        vector.v[1] == value)
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector2AllGreaterThanVector2(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON_)
    float32x2_t v1 = *(float32x2_t *)&vectorLeft;
    float32x2_t v2 = *(float32x2_t *)&vectorRight;
    uint32x2_t vCmp = vcgt_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vCmp, vext_u32(vCmp, vCmp, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vectorLeft.v[0] > vectorRight.v[0] &&
        vectorLeft.v[1] > vectorRight.v[1])
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector2AllGreaterThanScalar(ZGLKVector2 vector, float value)
{
#if defined(__ARM_NEON_)
    float32x2_t v1 = *(float32x2_t *)&vector;
    float32x2_t v2 = vdup_n_f32(value);
    uint32x2_t vCmp = vcgt_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vCmp, vext_u32(vCmp, vCmp, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vector.v[0] > value &&
        vector.v[1] > value)
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector2AllGreaterThanOrEqualToVector2(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON_)
    float32x2_t v1 = *(float32x2_t *)&vectorLeft;
    float32x2_t v2 = *(float32x2_t *)&vectorRight;
    uint32x2_t vCmp = vcge_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vCmp, vext_u32(vCmp, vCmp, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vectorLeft.v[0] >= vectorRight.v[0] &&
        vectorLeft.v[1] >= vectorRight.v[1])
        compare = true;
    return compare;
#endif
}

static __inline__ bool ZGLKVector2AllGreaterThanOrEqualToScalar(ZGLKVector2 vector, float value)
{
#if defined(__ARM_NEON_)
    float32x2_t v1 = *(float32x2_t *)&vector;
    float32x2_t v2 = vdup_n_f32(value);
    uint32x2_t vCmp = vcge_f32(v1, v2);
    uint32x2_t vAnd = vand_u32(vCmp, vext_u32(vCmp, vCmp, 1));
    vAnd = vand_u32(vAnd, vdup_n_u32(1));
    return (bool)vget_lane_u32(vAnd, 0);
#else
    bool compare = false;
    if (vector.v[0] >= value &&
        vector.v[1] >= value)
        compare = true;
    return compare;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Normalize(ZGLKVector2 vector)
{
    float scale = 1.0f / ZGLKVector2Length(vector);
    ZGLKVector2 v = ZGLKVector2MultiplyScalar(vector, scale);
    return v;
}

static __inline__ float ZGLKVector2DotProduct(ZGLKVector2 vectorLeft, ZGLKVector2 vectorRight)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vmul_f32(*(float32x2_t *)&vectorLeft,
                             *(float32x2_t *)&vectorRight);
    v = vpadd_f32(v, v);
    return vget_lane_f32(v, 0);
#else
    return vectorLeft.v[0] * vectorRight.v[0] + vectorLeft.v[1] * vectorRight.v[1];
#endif
}

static __inline__ float ZGLKVector2Length(ZGLKVector2 vector)
{
#if defined(__ARM_NEON__)
    float32x2_t v = vmul_f32(*(float32x2_t *)&vector,
                             *(float32x2_t *)&vector);
    v = vpadd_f32(v, v);
    return sqrt(vget_lane_f32(v, 0)); 
#else
    return sqrt(vector.v[0] * vector.v[0] + vector.v[1] * vector.v[1]);
#endif
}

static __inline__ float ZGLKVector2Distance(ZGLKVector2 vectorStart, ZGLKVector2 vectorEnd)
{
    return ZGLKVector2Length(ZGLKVector2Subtract(vectorEnd, vectorStart));
}

static __inline__ ZGLKVector2 ZGLKVector2Lerp(ZGLKVector2 vectorStart, ZGLKVector2 vectorEnd, float t)
{
#if defined(__ARM_NEON__)
    float32x2_t vDiff = vsub_f32(*(float32x2_t *)&vectorEnd,
                                 *(float32x2_t *)&vectorStart);
    vDiff = vmul_f32(vDiff, vdup_n_f32((float32_t)t));
    float32x2_t v = vadd_f32(*(float32x2_t *)&vectorStart, vDiff);
    return *(ZGLKVector2 *)&v;
#else
    ZGLKVector2 v = { vectorStart.v[0] + ((vectorEnd.v[0] - vectorStart.v[0]) * t),
        vectorStart.v[1] + ((vectorEnd.v[1] - vectorStart.v[1]) * t) };
    return v;
#endif
}

static __inline__ ZGLKVector2 ZGLKVector2Project(ZGLKVector2 vectorToProject, ZGLKVector2 projectionVector)
{
    float scale = ZGLKVector2DotProduct(projectionVector, vectorToProject) / ZGLKVector2DotProduct(projectionVector, projectionVector);
    ZGLKVector2 v = ZGLKVector2MultiplyScalar(projectionVector, scale);
    return v;
}

#ifdef __cplusplus
}
#endif

#endif // ZGLKit_ZGLKVector2_h
