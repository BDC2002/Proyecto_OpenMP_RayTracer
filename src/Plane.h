#ifndef PLANE_H
#define PLANE_H

#include "Ray.h"

struct Plane {
    Vector3 normal;
    double d; // ax + by + cz + d = 0

    Plane(const Vector3& n, double d_) : normal(n), d(d_) {}

    bool intersect(const Ray& ray, double& t) const {
        double denom = normal.dot(ray.dir);
        if (fabs(denom) < 1e-6) return false;

        t = -(normal.dot(ray.origin) + d) / denom;
        return t > 0;
    }
};

#endif
