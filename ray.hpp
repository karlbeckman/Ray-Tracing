#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

/**
 * @brief A class that represents a line/ray in 3D on the form
 * a + bt, where a is the ray origin and b is the ray
 * direction.
 */
class ray {
public:
  ray() {}
  ray(const point3& origin, const vec3& direction)
    : orig(origin), dir(direction) {}
  
  point3 origin() const {return orig;}
  vec3 direction() const {return dir;}

  /**
   * @brief Compute an arbitrary point on the ray.
   * 
   * @param t a real-valued number.
   * @return r(t). 
   */
  point3 at(double t) const {
    return orig + dir*t;
  }

private:
  point3 orig;
  vec3 dir;
};

#endif //RAY_HPP