#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
public:
    ray(const vec3<double>& org, const vec3<double>& dir) : _org(org), _dir(dir) {}
    ray(const ray& r) : _org(r.origin()), _dir(r.direction()) {}

    vec3<double> origin() const { return _org; }
    vec3<double> direction() const { return _dir; }
    vec3<double> at(double t) const { return _org + t * _dir; }

private:
    vec3<double> _org, _dir;
};

#endif