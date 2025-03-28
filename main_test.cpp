#include <iostream>

#include "rt_weekend.hpp"

int main() {

  auto v = random_in_unit_sphere();
  std::cout << v << std::endl;

  std::cout << v.length() << std::endl;
  std::cout << unit_vector(v) << std::endl;

  return 0;
}