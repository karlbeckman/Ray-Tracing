#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include "rt_weekend.hpp"

class material;

/**
 * @brief A struct for storing hit data.
 */
struct hit_record {
  point3 p;
  vec3 normal;
  std::shared_ptr<material> mat;
  double t;
  bool front_face;

  /**
   * @brief Set the hit record normal vector.
   * 
   * @param r the incoming ray.
   * @param outward_normal normal pointing out from the hittable object.
   * @note the parameter 'outward_normal' is assumed to have unit length.
   */
  void set_face_normal(const ray&r, const vec3& outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0; // Determine if the ray is inside the object or not. 
    normal = front_face ? outward_normal : -outward_normal;
  }
};

/**
 * @brief An interface for objects in the scene that 
 * may be hit.
 */
struct hittable {
  virtual ~hittable() = default;

  /**
   * @brief Determine if the hittable object is hit by r.
   * 
   * @param r the incoming ray.
   * @param ray_t defines an acceptable range to search for solutions.
   * @param rec a struct that is populated with hit data.
   * @return true if the hittable object is hit, false otherwise.
   */
  virtual bool hit(const ray&r, interval ray_t, hit_record& rec) const = 0;
};

#endif //HITTABLE_HPP