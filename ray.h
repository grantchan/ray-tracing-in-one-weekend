#ifndef RAY_H
#define RAY_H

#include "vec3d.h"

class ray {
public:
    ray(const vec3d& org, const vec3d& dir) : _org(org), _dir(dir) {}
    ray(const ray& r) {
        _org = r._org;
        _dir = r._dir;
    }

    vec3d origin() const { return _org; }
    vec3d direction() const { return _dir; }
    vec3d at(double t) const { return _org + t * _dir; }

private:
    vec3d _org, _dir;
};

#endif