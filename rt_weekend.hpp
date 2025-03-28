#ifndef RT_WEEKEND_HPP
#define RT_WEEKEND_HPP

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions

/**
 * @brief Convert an angle in degrees to radians.
 * 
 * @param degrees the angle in degrees.
 * @return the angle in radians.
 */
inline double double_to_radians(double degrees) {
  return degrees * pi / 180.0;
}

/**
 * @return a pseudo random double in [0, 1).
 */
inline double random_double() {
  // Returns a random number in [0, 1).
  return rand() / (RAND_MAX + 1.0);
}

/**
 * @return a pseudo random double in [min, max).
 */
inline double random_double(double min, double max) {
  // Returns a random real number in [max, min).
  return min + (max - min) * random_double();
}

// Common headers

#include "interval.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "color.hpp"

#endif //RT_WEEKEND_HPP