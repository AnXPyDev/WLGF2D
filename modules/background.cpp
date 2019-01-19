#include "../main.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

wgf::Background::Background() {};
void wgf::Background::draw() {};
void wgf::Background::update() {};
void wgf::Background::tick() {};

wgf::SolidBackground::SolidBackground(sf::Color color) : Background() {
  this->color = color;
}

void wgf::SolidBackground::draw() {
  wgf::cx.drawRect(wgf::C2d(), wgf::game::viewport.size, this->color);
}

namespace wgf::bck {
  std::vector<Background*> instances;
  void spawnBackground(Background* background) {
    bck::instances.push_back(background);
  }
}
