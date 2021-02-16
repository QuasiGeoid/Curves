#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>

struct Point3D
{
    double x{};
    double y{};
    double z{};
};

inline std::ostream& operator<<(std::ostream &os, const Point3D &point)
{
    return os << "3D point{" << point.x << ", "
                             << point.y << ", "
                             << point.z << "}";
}

#endif // POINT3D_H
