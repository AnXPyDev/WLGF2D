#include "../main.hpp"
#include <cmath>
#include <string>

wgf::A2d::A2d() {
  this->value = 0;
}

wgf::A2d::A2d(float val) {
  this->value = (val / 180) * M_PIf32;
}

wgf::A2d::A2d(float val, bool rad) {
  this->value = val;
}

float wgf::A2d::getDeg() {
  return (this->value / M_PIf32) * 180;
}

float wgf::A2d::getRad() {
  return this->value;
}

void wgf::A2d::operator+= (wgf::A2d other) {this->value += other.value;};
void wgf::A2d::operator+= (float x) {this->value += x;};
void wgf::A2d::operator-= (wgf::A2d other) {this->value -= other.value;};
void wgf::A2d::operator-= (float x) {this->value -= x;};
void wgf::A2d::operator=  (wgf::A2d other) {this->value = other.value;};
void wgf::A2d::operator*= (wgf::A2d other) {this->value *= other.value;};
void wgf::A2d::operator*= (float x) {this->value *= x;};
void wgf::A2d::operator/= (wgf::A2d other) {this->value /= other.value;};
void wgf::A2d::operator/= (float x) {this->value /= x;};
wgf::A2d wgf::A2d::operator/ (wgf::A2d other) {return wgf::A2d(this->value / other.value, true);};
wgf::A2d wgf::A2d::operator/ (float x) {return wgf::A2d(this->value / x, true);};
wgf::A2d wgf::A2d::operator* (wgf::A2d other) {return wgf::A2d(this->value * other.value, true);};
wgf::A2d wgf::A2d::operator* (float x) {return wgf::A2d(this->value * x, true);};
wgf::A2d wgf::A2d::operator+ (wgf::A2d other) {return wgf::A2d(this->value + other.value, true);};
wgf::A2d wgf::A2d::operator+ (float x) {return wgf::A2d(this->value + x, true);};
wgf::A2d wgf::A2d::operator- (wgf::A2d other) {return wgf::A2d(this->value - other.value, true);};
wgf::A2d wgf::A2d::operator- (float x) {return wgf::A2d(this->value - x, true);};
