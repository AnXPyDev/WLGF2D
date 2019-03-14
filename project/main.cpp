#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "../main.hpp"

wgf::Window window(wgf::C2d(1280, 720), "test");
sf::RenderWindow* cx;

class Player : public wgf::Actor {
public:
  Player() : wgf::Actor("player") {
    this->size = wgf::C2d(50);
    this->speed = wgf::C2d(8);
  }
  wgf::C2d speed;
  wgf::A2d angle;
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
    wgf::C2d currentPos(window.view.getCenter());
    float perc = 0.05;
    window.view.setCenter(wgf::util::lerp(currentPos.x, this->pos.x, perc), wgf::util::lerp(currentPos.y, this->pos.y, perc));

  }
  void draw() {
    wgf::draw::rect(this->pos, this->size, sf::Color::White);
  }
  
	  
};

class TestScene : public wgf::Scene {
public:
  TestScene() : wgf::Scene(wgf::C2d(1280,720), 60) {};
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
