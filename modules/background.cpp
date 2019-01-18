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
  sf::RectangleShape rect;
  rect.setFillColor(this->color);
  rect.setPosition(0, 0);
  rect.setSize(sf::Vector2f(wgf::game::viewport.size.x, wgf::game::viewport.size.y));
  wgf::game::viewport.window.draw(rect);
}

namespace wgf::bck {
  std::vector<Background*> instances;
  void spawnBackground(Background* background) {
    bck::instances.push_back(background);
  }
}
