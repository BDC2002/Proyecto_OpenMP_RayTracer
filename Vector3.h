#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

struct Vector3 {
    double x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    Vector3 operator + (const Vector3& v) const { return Vector3(x+v.x, y+v.y, z+v.z); }
    Vector3 operator - (const Vector3& v) const { return Vector3(x-v.x, y-v.y, z-v.z); }
    Vector3 operator * (double s) const { return Vector3(x*s, y*s, z*s); }

    double dot(const Vector3& v) const { return x*v.x + y*v.y + z*v.z; }

    Vector3 normalize() const {
        double m = std::sqrt(x*x + y*y + z*z);
        return Vector3(x/m, y/m, z/m);
    }
};

#endif
