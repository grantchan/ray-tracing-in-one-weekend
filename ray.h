#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
    ray(const point& org, const point& dir) : _org(org), _dir(dir) {}
    ray(const ray& r) : _org(r.origin()), _dir(r.direction()) {}

    point origin() const { return _org; }
    point direction() const { return _dir; }
    point at(double t) const { return _org + t * _dir; }

private:
    point _org, _dir;
};

#endif