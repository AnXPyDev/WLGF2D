#include "../main.hpp"
#include <string>

void wgf::Viewport::set(wgf::C2 size, std::string name) {
  this->size = size;
  this->window.create(sf::VideoMode(this->size.x, this->size.y), name);
}

wgf::Viewport::Viewport() {
  this->size = wgf::C2();
}
