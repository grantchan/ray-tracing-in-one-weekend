#include <iostream>
#include "vec3d.h"

int main() {
    int width = 200;
    int height = 100;
    std::cout << "P3\n" << width << " " << height << "\n255\n";
    for (int i = height-1; i >=0; i--) {
        for (int j = 0; j < width; j++) {
            vec3d v(double(j) / double(width), (double)i / (double)height, 0.2);
            int r = int(255.99 * v.x());
            int g = int(255.99 * v.y());
            int b = int(255.99 * v.z());

            std::cout << r << " " << g << " " << b << "\n";
        }
    }

    return 0;
}