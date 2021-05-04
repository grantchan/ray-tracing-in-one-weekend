#ifndef VEC3D_H
#define VEC3D_H

#include <cmath>

class vec3d {

private:
    double _x, _y, _z;

public:
    vec3d() : _x(0), _y(0), _z(0) {}
    vec3d(double x, double y, double z) {
        _x = x;
        _y = y;
        _z = z;
    }

    inline double x() const { return _x; }
    inline double y() const { return _y; }
    inline double z() const { return _z; }
};

#endif