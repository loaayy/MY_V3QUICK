
#ifndef __CCCAMERA_ACTION_H__
#define __CCCAMERA_ACTION_H__

#include "2d/CCActionInterval.h"
#include "math/CCMath.h"

NS_CC_BEGIN

class Camera;

/**
 * @addtogroup actions
 * @{
 */

/** 
@brief Base class for Camera actions
@ingroup Actions
*/
class CC_DLL ActionCamera : public ActionInterval //<NSCopying> 
{
public:
    /**
     * @js ctor
     */
    ActionCamera();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~ActionCamera(){};

    // Overrides
    virtual void startWithTarget(Node *target) override;
    virtual ActionCamera * reverse() const override;
	virtual ActionCamera *clone() const override;

    /* sets the Eye value of the Camera */
    void setEye(const Vec3 &eye);
    void setEye(float x, float y, float z);
    /* returns the Eye value of the Camera */
    const Vec3& getEye() const { return _eye; }
    /* sets the Center value of the Camera */
    void setCenter(const Vec3 &center);
    /* returns the Center value of the Camera */
    const Vec3& getCenter() const { return _center; }
    /* sets the Up value of the Camera */
    void setUp(const Vec3 &up);
    /* Returns the Up value of the Camera */
    const Vec3& getUp() const { return _up; }

protected:

    void restore();
    void updateTransform();

    Vec3 _center;
    Vec3 _eye;
    Vec3 _up;
};

/** 
@brief OrbitCamera action
Orbits the camera around the center of the screen using spherical coordinates
@ingroup Actions
*/
class CC_DLL OrbitCamera : public ActionCamera //<NSCopying> 
{
public:
    /** creates a OrbitCamera action with radius, delta-radius,  z, deltaZ, x, deltaX */
    static OrbitCamera* create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX);
    
    /** positions the camera according to spherical coordinates */
    void sphericalRadius(float *r, float *zenith, float *azimuth);

    // Overrides
	OrbitCamera *clone() const override;
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
    
CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    OrbitCamera();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~OrbitCamera();
    
    /** initializes a OrbitCamera action with radius, delta-radius,  z, deltaZ, x, deltaX */
    bool initWithDuration(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX);

protected:
    float _radius;
    float _deltaRadius;
    float _angleZ;
    float _deltaAngleZ;
    float _angleX;
    float _deltaAngleX;

    float _radZ;
    float _radDeltaZ;
    float _radX;
    float _radDeltaX;
};

// end of actions group
/// @}

NS_CC_END

#endif //__CCCAMERA_ACTION_H__
