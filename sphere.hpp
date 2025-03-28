#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "hittable.hpp"
#include "vec3.hpp"

/**
 * @brief A class for a sphere representation.
 */
class sphere: public hittable {
public:
  sphere(point3 center, double radius, std::shared_ptr<material> material): 
  center(center), radius(radius), mat(material) {}

  /**
   * @brief Determine if the sphere is hit by the incoming ray r.
   * 
   * @param r the incoming ray.
   * @param ray_t defines an acceptable range to search for solutions.
   * @param rec a struct that is populated with hit data.
   * @return true if the hittable object is hit, false otherwise.
   */
  bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b - a*c;

    if (discriminant < 0) return false;

    auto sqrtd = std::sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range. 
    auto root = (-half_b - sqrtd) / a;
    if (!ray_t.surrounds(root)) {
      root = (-half_b + sqrtd) / a;
      if (!ray_t.surrounds(root)) {
        return false;
      }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat = mat;

    return true;
  }
private:
  point3 center;
  double radius;
  std::shared_ptr<material> mat;
};

#endif //SPHERE_HPP