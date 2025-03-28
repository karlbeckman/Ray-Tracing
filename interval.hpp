#ifndef INTERVAL_HPP
#define INTERVAL_HPP

/**
 * @brief A class to manage real-valued intervals with a
 * minimum and a maximum.
 */
struct interval {
  double min, max;

  interval(): min(+infinity), max(-infinity) {} // Default interval is empty.

  interval(double min_, double max_): min(min_), max(max_) {}

  /**
   * @param x the value to check.
   * @return true if x lies in the interval [min, max], false otherwise.
   */
  bool contains(double x) const {
    return min <= x && x <= max;
  }

  /**
   * @param x the value to check.
   * @return true if x lies in the interval (min, max), false otherwise. 
   */
  bool surrounds(double x) const {
    return min < x && x < max;
  }

  /**
   * @param x the value to check.
   * @return x, if x lies in the interval [min, max]. Otherwise
   * a clamped value is returned.
   */
  double clamp(double x) const {
    if (x < min) return min;
    if (x > max) return max;
    return x;
  }

  static const interval empty, universe;
};

static const interval empty(+infinity, -infinity);
static const interval universe(-infinity, +infinity);

#endif //INTERVAL_HPP