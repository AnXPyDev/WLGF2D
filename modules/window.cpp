#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "../main.hpp"

wgf::Window::Window(wgf::C2d size, std::string name) {
  this->size = size;
  this->window.create(sf::VideoMode(this->size.x, this->size.y), name);
  this->view = sf::View(sf::Vector2f(0,0), sf::Vector2f(this->size.x / 2, this->size.y / 2));
  this->window.setView(this->view);
  this->view.setViewport(sf::FloatRect(0.10f,0.10f,0.80f,0.80f));
}

void wgf::Window::updateSize() {
  auto winSize = this->window.getSize();
  float ratio;
  if (this->size.x / this->size.y >= winSize.x / winSize.y) {
    ratio = winSize.x / this->size.x;
  } else {
    ratio = winSize.y / this->size.y;
  }

  wgf::C2d newSize(this->size.x * ratio, this->size.y * ratio);
  wgf::C2d newRatio = newSize / wgf::C2d(winSize.x, winSize.y);
  this->window.clear();
  this->view.setViewport(sf::FloatRect((1 - newRatio.x) / 2, (1 - newRatio.y) / 2, newRatio.x, newRatio.y));
  

}

void wgf::Window::tickUpdate() {
  this->window.setView(this->view);
}
