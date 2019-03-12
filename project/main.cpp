#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "../main.hpp"

wgf::Window window(wgf::C2d(800, 600), "test");
sf::RenderWindow* cx;

class Player : public wgf::Actor {
public:
  Player() : wgf::Actor("player") {
    this->size = wgf::C2d(50);
    this->speed = wgf::C2d(5);
  }
  wgf::C2d speed;
  sf::RectangleShape drawRect;
  void tick() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      this->pos.x += -this->speed.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      this->pos.x += this->speed.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      this->pos.y += -this->speed.y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      this->pos.y += this->speed.y;
    }
    window.view.setCenter(this->pos.x, this->pos.y);

  }
  void draw() {
    this->drawRect.setSize(sf::Vector2f(this->size.x, this->size.y));
    this->drawRect.setOrigin(this->size.x / 2, this->size.y / 2);
    this->drawRect.setPosition(this->pos.x, this->pos.y);
    cx->draw(this->drawRect);
  }
  
	  
};

class TestScene : public wgf::Scene {
public:
  TestScene() : wgf::Scene(wgf::C2d(800,600), 60) {};
  void onLoad() {
    wgf::bck::spawn(new wgf::SolidBackground(sf::Color::Red));
    wgf::act::spawn("player", new Player());
  }
};

TestScene scene0;

int main(int argc, char** argv) {
  cx = &window.window;
  wgf::engine::init(&window);
  wgf::act::define("player", std::vector<std::string>({}));
  scene0.load();
  wgf::engine::mainLoop();
}
