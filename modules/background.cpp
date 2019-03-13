#include "../main.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

wgf::Background::Background() {};
void wgf::Background::draw() {};
void wgf::Background::update() {};
void wgf::Background::tick() {};

wgf::SolidBackground::SolidBackground(sf::Color color) : Background() {
  this->color = color;
}

void wgf::SolidBackground::draw() {
  auto size = wgf::game::window->view.getSize();
  auto pos = wgf::game::window->view.getCenter();
  this->rect.setFillColor(this->color);
  this->rect.setSize(wgf::C2d(std::max(size.x, size.y) * 2).toSfVector());
  this->rect.setOrigin(std::max(size.x, size.y), std::max(size.x, size.y));
  this->rect.setPosition(pos);
  game::window->window.draw(this->rect);
}

namespace wgf::bck {
  std::vector<Background*> instances;
  void spawn(Background* background) {
    bck::instances.push_back(background);
  }
}
