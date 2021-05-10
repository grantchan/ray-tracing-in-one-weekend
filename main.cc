#include <iostream>
#include "ray.h"
#include "vec3.h"

bool hit_sphere(const point& center, double radius, const ray& r) {
    vec3<double> oc = r.origin() - center;
    double a = r.direction().dot(r.direction());
    double b = 2.0 * oc.dot(r.direction());
    double c = oc.dot(oc) - radius * radius;
    return (b*b - 4*a*c) > 0;
}

int main() {
    const double aspect_ratio = 16.0/9.0;

    int img_width = 800;
    int img_height = static_cast<int>(img_width / aspect_ratio);
    
    // view port
    double vp_height = 2.0;
    double vp_width = aspect_ratio * vp_height;
    double focal_length = 1.0;

    point origin(0, 0, 0);
    vec3<double> x_offset(vp_width, 0, 0);
    vec3<double> y_offset(0, vp_height, 0);
    vec3<double> z_offset(0, 0, focal_length);
    point lower_left_corner = origin - x_offset/2 - y_offset/2 - z_offset;

    // render
    std::cout << "P3\n" << img_width << " " << img_height << "\n255\n";
    for (int i = img_height-1; i >=0; i--) {
        double v = double(i) / (img_height-1);

        for (int j = 0; j < img_width; j++) {
            double u = double(j) / (img_width-1);

            point dir = lower_left_corner;
            dir += u*x_offset;
            dir += v*y_offset;
            dir -= origin;
            ray r(origin, dir);
            if (hit_sphere(point(0, 0, -1), 0.5, r)) {
                color c(255, 0, 0);

                std::cout << c.x() << ' ' << c.y() << ' ' << c.z() << '\n';
            } else {
                vec3<double> unit_dir = unit_vector(r.direction());
                double t = 0.5*(unit_dir.y() + 1.0);
                vec3<double> cc = 255.999 * (vec3<double>(1.0-t, 1.0-t, 1.0-t) + t*vec3<double>(0.5, 0.7, 1.0));

                color c((int)cc.x(), (int)cc.y(), (int)cc.z());

                std::cout << c.x() << ' ' << c.y() << ' ' << c.z() << '\n';  
            }
        }
    }

    return 0;
}