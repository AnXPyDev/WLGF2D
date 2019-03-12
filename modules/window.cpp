#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "../main.hpp"

wgf::Window::Window(wgf::C2d size, std::string name) {
  this->size = size;
  this->window.create(sf::VideoMode(this->size.x, this->size.y), name);
  this->view = sf::View(sf::Vector2f(0,0), sf::Vector2f(this->size.x / 2, this->size.y / 2));
  this->window.setView(this->view);
}

void wgf::Window::updateSize() {}
