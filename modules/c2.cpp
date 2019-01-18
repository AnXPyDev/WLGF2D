#include "../main.hpp"

// Constructs C2d with x and y
wgf::C2d::C2d(float x, float y) {
  this->x = x;
  this->y = y;
}

// Constructs C2d with x and y, where y = x
wgf::C2d::C2d(float x) {
  this->x = x;
  this->y = x;
}

// Constructs C2d with x and y, where both x and y = 0
wgf::C2d::C2d() {
  this->x = 0;
  this->y = 0;
}

void wgf::C2d::operator+= (C2d other) {
  this->x += other.x;
  this->y += other.y;
}

void wgf::C2d::operator=  (C2d other) {
  this->x = other.x;
  this->y = other.y;
}
