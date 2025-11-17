#include <iostream>
#include <fstream>
#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"

int main() {
    int width = 800;
    int height = 600;

    Vector3 camera(0, 0, 0);
    double fov = 90.0;

    Sphere sphere(Vector3(0, 0, -3), 1.0);
    Plane  plane(Vector3(0, 1, 0), 1.0); // y = -1

    std::ofstream ppm("output_sequential.ppm");
    ppm << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            double px = (2 * (x + 0.5) / (double)width - 1) * tan(fov * 0.5);
            double py = (1 - 2 * (y + 0.5) / (double)height) * tan(fov * 0.5);

            Ray ray(camera, Vector3(px, py, -1).normalize());

            double t;
            bool hitSphere = sphere.intersect(ray, t);
            bool hitPlane  = plane.intersect(ray, t);

            int r = 0, g = 0, b = 0;

            if (hitSphere) { r = 255; }
            else if (hitPlane) { g = 255; }
            else { b = 255; }

            ppm << r << " " << g << " " << b << " ";
        }
        ppm << "\n";
    }

    ppm.close();
    std::cout << "Imagen generada: output_sequential.ppm\n";
    return 0;
}
