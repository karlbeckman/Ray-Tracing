#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP

#include "hittable.hpp"

#include <memory>
#include <vector>

/**
 * @brief A structure for storing hittable objects.
 */
struct hittable_list: public hittable {
  std::vector<std::shared_ptr<hittable>> objects;

  hittable_list() {}
  hittable_list(std::shared_ptr<hittable> object) { add(object); }

  void clear() { objects.clear(); }

  void add(std::shared_ptr<hittable> object) {
    objects.push_back(object);
  }

  /**
   * @brief Determine if any objects in the list are hit by r.
   * 
   * @param r the incoming ray.
   * @param ray_t defines an acceptable range to search for solutions.
   * @param rec a struct that is populated with hit data.
   * @return true if at least one object in the list is hit, false otherwise.
   */
  bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
    hit_record temp_rec;
    bool hit_anything = false;

    for (const auto& object: objects) {
      if (object->hit(r, ray_t, temp_rec)) {
        hit_anything = true;
        ray_t.max = temp_rec.t;
        rec = temp_rec;
      }
    }

    return hit_anything;
  }
};

#endif //HITTABLE_LIST_HPP