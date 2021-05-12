#ifndef VEC3_H
#define VEC3_H

#include <cmath>

template <class T>
class vec3 {
public:
    vec3(const T& x, const T& y, const T& z) : _x(x), _y(y), _z(z) {}
    vec3(const vec3& v) : _x(v._x), _y(v._y), _z(v._z) {}
    
    T x() const { return _x; }
    T y() const { return _y; }
    T z() const { return _z; }

    double dot(const vec3<T> rhs) const { return _x*rhs.x() + _y*rhs.y() + _z*rhs.z(); }

    double length() const { return std::sqrt(_x*_x + _y*_y + _z*_z); }
    
    const vec3 unit() const { return *this / length(); }
    
    // unary operator overloading
    const vec3 operator-() { return vec3<T>(-_x, -_y, -_z); }
    
    // binary operator overloading
    const vec3 operator+(const int rhs)    const { return vec3<T>(_x + rhs, _y + rhs, _z + rhs); }
    const vec3 operator+(const float rhs)  const { return vec3<T>(_x + rhs, _y + rhs, _z + rhs); }
    const vec3 operator+(const double rhs) const { return vec3<T>(_x + rhs, _y + rhs, _z + rhs); }
    const vec3 operator+(const vec3& rhs)  const { return vec3<T>(_x + rhs.x(), _y + rhs.y(), _z + rhs.z()); }
    
    const vec3 operator-(const int rhs)    const { return vec3<T>(_x - rhs, _y - rhs, _z - rhs); }
    const vec3 operator-(const float rhs)  const { return vec3<T>(_x - rhs, _y - rhs, _z - rhs); }
    const vec3 operator-(const double rhs) const { return vec3<T>(_x - rhs, _y - rhs, _z - rhs); }
    const vec3 operator-(const vec3& rhs)  const { return vec3<T>(_x - rhs.x(), _y - rhs.y(), _z - rhs.z()); }

    const vec3 operator*(const int rhs)    const { return vec3<T>(_x * rhs, _y * rhs, _z * rhs); }
    const vec3 operator*(const float rhs)  const { return vec3<T>(_x * rhs, _y * rhs, _z * rhs); }
    const vec3 operator*(const double rhs) const { return vec3<T>(_x * rhs, _y * rhs, _z * rhs); }
    const vec3 operator*(const vec3& rhs)  const { return vec3<T>(_x * rhs.x(), _y * rhs.y(), _z * rhs.z()); }

    const vec3 operator/(const int rhs)    const { return vec3<T>(_x / rhs, _y / rhs, _z / rhs); }
    const vec3 operator/(const float rhs)  const { return vec3<T>(_x / rhs, _y / rhs, _z / rhs); }
    const vec3 operator/(const double rhs) const { return vec3<T>(_x / rhs, _y / rhs, _z / rhs); }
    const vec3 operator/(const vec3& rhs)  const { return vec3<T>(_x / rhs.x(), _y / rhs.y(), _z / rhs.z()); }

    vec3& operator=(const vec3& rhs) { _x = rhs._x; _y = rhs._y; _z = rhs._z; return *this; }
    
    vec3& operator+=(const int rhs)    { _x += rhs; _y += rhs; _z += rhs; return *this; }
    vec3& operator+=(const float rhs)  { _x += rhs; _y += rhs; _z += rhs; return *this; }
    vec3& operator+=(const double rhs) { _x += rhs; _y += rhs; _z += rhs; return *this; }
    vec3& operator+=(const vec3 rhs)   { _x += rhs.x(); _y += rhs.y(); _z += rhs.z(); return *this; }
    
    vec3& operator-=(const int rhs)    { _x -= rhs; _y -= rhs; _z -= rhs; return *this; }
    vec3& operator-=(const float rhs)  { _x -= rhs; _y -= rhs; _z -= rhs; return *this; }
    vec3& operator-=(const double rhs) { _x -= rhs; _y -= rhs; _z -= rhs; return *this; }
    vec3& operator-=(const vec3 rhs)   { _x -= rhs.x(); _y -= rhs.y(); _z -= rhs.z(); return *this; }

    vec3& operator*=(const int rhs)    { _x *= rhs; _y *= rhs; _z *= rhs; return *this; }
    vec3& operator*=(const float rhs)  { _x *= rhs; _y *= rhs; _z *= rhs; return *this; }
    vec3& operator*=(const double rhs) { _x *= rhs; _y *= rhs; _z *= rhs; return *this; }
    vec3& operator*=(const vec3 rhs)   { _x *= rhs.x(); _y *= rhs.y(); _z *= rhs.z(); return *this; }
    
    vec3& operator/=(const int rhs)    { _x /= rhs; _y /= rhs; _z /= rhs; return *this; }
    vec3& operator/=(const float rhs)  { _x /= rhs; _y /= rhs; _z /= rhs; return *this; }
    vec3& operator/=(const double rhs) { _x /= rhs; _y /= rhs; _z /= rhs; return *this; }
    vec3& operator/=(const vec3 rhs)   { _x /= rhs.x(); _y /= rhs.y(); _z /= rhs.z(); return *this; }

private:
    T _x, _y, _z;
};

template <class T> const vec3<T> operator+(const int lhs, const vec3<T>& rhs)    { return rhs + lhs; }
template <class T> const vec3<T> operator+(const float lhs, const vec3<T>& rhs)  { return rhs + lhs; }
template <class T> const vec3<T> operator+(const double lhs, const vec3<T>& rhs) { return rhs + lhs; }

template <class T> const vec3<T> operator*(const int lhs, const vec3<T>& rhs)    { return rhs * lhs; }
template <class T> const vec3<T> operator*(const float lhs, const vec3<T>& rhs)  { return rhs * lhs; }
template <class T> const vec3<T> operator*(const double lhs, const vec3<T>& rhs) { return rhs * lhs; }

using color = vec3<int>;
using point = vec3<double>;

#endif