#include "../main.hpp"

// Constructs C2 with x and y
wgf::C2::C2(float x, float y) {
  this->x = x;
  this->y = y;
}

// Constructs C2 with x and y, where y = x
wgf::C2::C2(float x) {
  this->x = x;
  this->y = x;
}

// Constructs C2 with x and y, where both x and y = 0
wgf::C2::C2() {
  this->x = 0;
  this->y = 0;
}

void wgf::C2::operator+= (C2 other) {
  this->x += other.x;
  this->y += other.y;
}

void wgf::C2::operator=  (C2 other) {
  this->x = other.x;
  this->y = other.y;
}
