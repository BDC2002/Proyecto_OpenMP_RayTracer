#ifndef SPHERE_H
#define SPHERE_H

#include "Ray.h"

struct Sphere {
    Vector3 center;
    double radius;

    Sphere(const Vector3& c, double r) : center(c), radius(r) {}

    bool intersect(const Ray& ray, double& t) const {
        Vector3 oc = ray.origin - center;
        double b = 2 * oc.dot(ray.dir);
        double c = oc.dot(oc) - radius * radius;
        double disc = b*b - 4*c;

        if (disc < 0) return false;
        disc = std::sqrt(disc);
        double t0 = (-b - disc) / 2;
        double t1 = (-b + disc) / 2;

        if (t0 > 0) { t = t0; return true; }
        if (t1 > 0) { t = t1; return true; }
        return false;
    }
};

#endif
