#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <iostream>

#include "rt_weekend.hpp"

/**
 * @brief A 3D vector class.
 */
class vec3 {
public:
  vec3(): e{0, 0, 0} {}
  vec3(double ex, double ey, double ez): e{ex, ey, ez} {}

  double x() const {return e[0];}
  double y() const {return e[1];}
  double z() const {return e[2];}

  vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
  double operator[](int i) const {return e[i];}
  double& operator[] (int i) {return e[i];}

  vec3& operator+=(const vec3& v) {
    e[0] += v[0];
    e[1] += v[1];
    e[2] += v[2];

    return *this;
  }

  vec3& operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;

    return *this;
  }

  vec3& operator/=(double t) {
    return *this *= 1/t;
  }

  double length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
  }

  /**
   * @brief Helper function to avoid NaNs and infinities.
   * 
   * @return true if all vector components are close to zero,
   * false otherwise.
   */
  bool near_zero() const {
    // Return true if the vector is close to zero in all dimensions.
    auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
  }

  double length() const {
    return std::sqrt(length_squared());
  }

  /**
   * @return a pseudo random vector where 
   * (x, y, z) lies in [0, 1).  
   */
  static vec3 random() {
    return vec3(random_double(), random_double(), random_double());
  }

  static vec3 random(double min, double max) {
    return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
  }

private:
  double e[3];
};

// point 3 is just an alias for vec3, but useful for clarity in code.
using point3 = vec3;

// Vector utility functions.

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3& u, const vec3& v) {
  return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
} 

inline vec3 operator-(const vec3& u, const vec3& v) {
  return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator*(const vec3& u, const vec3& v) {
  return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator*(double t, const vec3& v) {
  return vec3(v.x() * t, v.y() * t, v.z() * t);
}

inline vec3 operator*(const vec3& v, double t) {
  return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
  return (1/t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
  return u.x() * v.x() +
         u.y() * v.y() + 
         u.z() * v.z();
}

inline vec3 cross(const vec3& u, const vec3& v) {
  return vec3(u.y() * v.z() - u.z() * v.y(),
              u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x());
}

inline vec3 unit_vector(const vec3& v) {
  return v / v.length();
}

inline vec3 random_in_unit_disk() {
  while(true) {
    auto p = vec3(random_double(-1, 1), random_double(-1, 1), 0);
    if (p.length_squared() < 1) {
      return p;
    }
  }
}

inline vec3 random_in_unit_sphere() {
  while(true) {
    auto v = vec3::random(-1, 1);
    if (v.length_squared() < 1) 
      return v;
  }
}

inline vec3 random_unit_vector() {
  return unit_vector(random_in_unit_sphere());
}

inline vec3 random_on_hemisphere(const vec3& normal) {
  vec3 on_unit_sphere = random_unit_vector();
  if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal.
    return on_unit_sphere;
  else
    return -on_unit_sphere;
}

inline vec3 reflect(const vec3& v, const vec3& n) {
  return v - 2*dot(v, n)*n;
}

inline vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
  auto cost_theta = fmin(dot(-uv, n), 1.0);
  vec3 r_out_perp = etai_over_etat * (uv + cost_theta*n);
  vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
  return r_out_parallel + r_out_perp;
} 

#endif //VEC3_HPP