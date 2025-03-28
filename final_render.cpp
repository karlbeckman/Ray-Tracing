#include <iostream>

#include "rt_weekend.hpp"

#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

int main() {
  hittable_list world;

  auto ground_material = std::make_shared<lambertian>(color(0.5, 0.5, 0.5));
  world.add(std::make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

  for (int a = -11; a < 11; a++) {
    auto choose_mat = random_double();
  }

  camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 1200;
  cam.samples_per_pixel = 500;
  cam.max_depth = 50;

  cam.vfov = 20;
  cam.lookfrom = point3(13, 2, 3);
  cam.lookat = point3(0, 0, 0);
  cam.vup = vec3(0, 1, 0);

  cam.defocus_angle = 0.6;
  cam.focus_distance = 10.0;

  cam.render(world);

  return 0;
}