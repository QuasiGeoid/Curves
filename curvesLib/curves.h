#ifndef CURVES_H
#define CURVES_H

#include "curves_global.h"
#include "point3D.h"
#include "vector3D.h"

//--------------------------------------------------
// Abstract curve class
//--------------------------------------------------

class CURVES_EXPORT AbstractCurve
{
public:
    virtual ~AbstractCurve();

    virtual Point3D getPoint(double t) const = 0;   // return 3D point per parameter t along the curve
    virtual Vector3D getVector(double t) const = 0; // return 3D vector per parameter t along the curve
    virtual void getCurveType() const = 0;
};

//--------------------------------------------------
// Class Circle
//--------------------------------------------------

class CURVES_EXPORT Circle : public AbstractCurve
{
public:
    Circle(double radius = 1.0);
    virtual ~Circle();

    double getRadius() const;

    Point3D getPoint(double t) const override;
    Vector3D getVector(double t) const override;
    void getCurveType() const override;

private:
    double m_radius;
};

//--------------------------------------------------
//Class Ellipse
//--------------------------------------------------

class CURVES_EXPORT Ellipse : public AbstractCurve
{

public:
    Ellipse(double radiusX = 1.0, double radiusY = 0.5);
    virtual ~Ellipse();

    double getRadiusX();
    double getRadiusY();

    Point3D getPoint(double t) const override;
    Vector3D getVector(double t) const override;
    void getCurveType() const override;

private:
    double m_radiusX;
    double m_radiusY;
};

//--------------------------------------------------
//Class 3D helix
//--------------------------------------------------

class CURVES_EXPORT Helix : public AbstractCurve
{
public:
    Helix(double radius = 1.0, double step = 1.0);
    virtual ~Helix();

    double getRadius();
    double getStep();

    Point3D getPoint(double t) const override;
    Vector3D getVector(double t) const override;
    void getCurveType() const override;

private:
    double m_radius;
    double m_step;
};

#endif // CURVES_H
