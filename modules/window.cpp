#include "../main.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

wgf::Window::Window(wgf::C2d size, std::string name) {
  this->size = size;
  this->window.create(sf::VideoMode(this->size.x, this->size.y), name);
  this->view = sf::View(sf::Vector2f(0, 0),
                        sf::Vector2f(this->size.x, this->size.y));
  this->window.setView(this->view);
  this->view.setViewport(sf::FloatRect(0.10f, 0.10f, 0.80f, 0.80f));
}

void wgf::Window::updateSize() {
  auto winSize = this->window.getSize();
  C2d ratio(1);
  if ((float)winSize.x / (float)winSize.y >= this->size.x / this->size.y) {
    ratio.x = (this->size.x * (winSize.y / this->size.y)) / winSize.x;
  } else {
    ratio.y = (this->size.y * (winSize.x / this->size.x)) / winSize.y;
  }
  this->view.setViewport(
      sf::FloatRect(wgf::C2d((1 - ratio.x) / 2, (1 - ratio.y) / 2).toSfVector(),
                    ratio.toSfVector()));
}

void wgf::Window::tickUpdate() { this->window.setView(this->view); }
