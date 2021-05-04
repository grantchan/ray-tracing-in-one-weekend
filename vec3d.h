#ifndef VEC3D_H
#define VEC3D_H

#include <cmath>

class vec3d {
public:
    vec3d() : _x(0), _y(0), _z(0) {}
    vec3d(double x, double y, double z) : _x(x), _y(y), _z(z) {}
    vec3d(const vec3d& v) {
        _x = v._x;
        _y = v._y;
        _z = v._z;
    }

    inline double x() const { return _x; }
    inline double y() const { return _y; }
    inline double z() const { return _z; }

private:
    double _x, _y, _z;
};

const vec3d operator+(const vec3d& lhs, const vec3d& rhs) {
    return vec3d(lhs.x()+rhs.x(), lhs.y()+rhs.y(), lhs.z()+rhs.z());
}
const vec3d operator*(const vec3d& lhs, const vec3d& rhs) {
    return vec3d(lhs.x()*rhs.x(), lhs.y()*rhs.y(), lhs.z()*rhs.z());
}
const vec3d operator*(double lhs, const vec3d& rhs) {
    return vec3d(lhs*rhs.x(), lhs*rhs.y(), lhs*rhs.z());
}

#endif