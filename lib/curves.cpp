#include "curves.h"

#include <iostream>
#include <cmath>

//--------------------------------------------------
// Class AbstractCurve:
//--------------------------------------------------

AbstractCurve::~AbstractCurve() {}

//--------------------------------------------------
// Class Circle
//--------------------------------------------------

Circle::Circle(double radius)
        : m_radius(radius)
{
}

Circle::~Circle() {}

double Circle::getRadius() const
{
    return m_radius;
}

Point3D Circle::getPoint(double t) const
    {
        return Point3D
        {
            m_radius * cos(t),   // x
            m_radius * sin(t)    // y
        };
    }
Vector3D Circle::getVector(double t) const
    {
        return Vector3D
        {
            -1 * m_radius * sin(t),  // x
            m_radius * cos(t)        // y
        };
    }
CurveType Circle::getCurveType() const
    {
        return CIRCLE;
    }

//--------------------------------------------------
//Class Ellipse
//--------------------------------------------------

Ellipse::Ellipse(double radiusX, double radiusY)
        : m_radiusX(radiusX), m_radiusY(radiusY)
{
}
Ellipse::~Ellipse() {}

double Ellipse::getRadiusX()
{
    return m_radiusX;
}
double Ellipse::getRadiusY()
{
    return m_radiusY;
}

Point3D Ellipse::getPoint(double t) const
    {
        return Point3D
        {
            m_radiusX * cos(t),   // x
            m_radiusY * sin(t)    // y
        };
    }
Vector3D Ellipse::getVector(double t) const
    {
        return Vector3D
        {
            -1 * m_radiusX * sin(t),  // x
            m_radiusY * cos(t)        // y
        };
    }
CurveType Ellipse::getCurveType() const
    {
        return ELLIPSE;
    }

//--------------------------------------------------
//Class 3D helix
//--------------------------------------------------

Helix::Helix(double radius, double step)
        : m_radius(radius), m_step(step)
{
}

Helix::~Helix() {}

Point3D Helix::getPoint(double t) const
    {
        return Point3D
        {
            m_radius * cos(t),          // x
            m_radius * sin(t),          // y
            m_step / (2 * M_PI) * t     // z
        };
    }
Vector3D Helix::getVector(double t) const
    {
        return Vector3D
        {
            -1 * m_radius * sin(t),   // x
            m_radius * cos(t),        // y
            m_step / (2 * M_PI)       // z
        };
    }
CurveType Helix::getCurveType() const
    {
        return HELIX;
    }
