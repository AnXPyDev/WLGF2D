#include "../main.hpp"
#include <SFML/Graphics.hpp>

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

wgf::C2d::C2d(sf::Vector2f sfVector) {
  this->x = sfVector.x;
  this->y = sfVector.y;
}

wgf::C2d::C2d(const wgf::C2d& original) {
  this->x = original.x;
  this->y = original.y;
}

sf::Vector2f wgf::C2d::toSfVector() {
  return sf::Vector2f(this->x, this->y);
}

void wgf::C2d::operator=  (C2d other) {
  this->x = other.x;
  this->y = other.y;
}

void wgf::C2d::operator+= (C2d other) {
  this->x += other.x;
  this->y += other.y;
}

void wgf::C2d::operator+= (float x) {
  this->x += x;
  this->y += x;
}

void wgf::C2d::operator-= (C2d other) {
  this->x -= other.x;
  this->y -= other.y;
}

void wgf::C2d::operator-= (float x) {
  this->x -= x;
  this->y -= x;
}

void wgf::C2d::operator*= (C2d other) {
  this->x *= other.x;
  this->y *= other.y;
}

void wgf::C2d::operator*= (float x) {
  this->x *= x;
  this->y *= x;
}

wgf::C2d wgf::C2d::operator*(C2d other) {
  return C2d(this->x * other.x, this->y * other.y);
}

wgf::C2d wgf::C2d::operator*(float x) {
  return C2d(this->x * x, this->y * x);
}

wgf::C2d wgf::C2d::operator/(C2d other) {
  return C2d(this->x / other.x, this->y / other.y);
}

wgf::C2d wgf::C2d::operator/(float x) {
  return C2d(this->x / x, this->y / x);
}

wgf::C2d wgf::C2d::operator+(C2d other) {
  return C2d(this->x + other.x, this->y + other.y);
}

wgf::C2d wgf::C2d::operator+(float x) {
  return C2d(this->x + x, this->y + x);
}

wgf::C2d wgf::C2d::operator-(C2d other) {
  return C2d(this->x - other.x, this->y - other.y);
}

wgf::C2d wgf::C2d::operator-(float x) {
  return C2d(this->x - x, this->y - x);
}
