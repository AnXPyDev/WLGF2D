#include "main.hpp"
#include <iostream>

wgf::C2 testCoord(200,200);

int main() {
  std::cout << testCoord.x << " " << testCoord.y << std::endl;
  testCoord += wgf::C2(200);
  std::cout << testCoord.x << " " << testCoord.y << std::endl;
}
