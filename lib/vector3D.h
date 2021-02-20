#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

struct Vector3D
{
    double x{};
    double y{};
    double z{};
};

inline std::ostream& operator<<(std::ostream &os, const Vector3D &vector)
{
    return os << "3D vector{" << vector.x << ", "
                              << vector.y << ", "
                              << vector.z << "}";
}

#endif // VECTOR3D_H
