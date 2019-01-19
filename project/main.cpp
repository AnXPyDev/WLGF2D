#include "../main.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace wgf;

C2d testCoord(200,200);

class Scene0 : public wgf::Scene {
public:
  Scene0() : Scene(wgf::C2d(800,600), 60) {};
};

class Test0 : public wgf::Actor {
public:
  Test0() : Actor(wgf::C2d(), wgf::C2d(50), "test") {};
  void draw() {
    std::cout << "skrrrt" << std::endl;
    cx.save();
    cx.drawRect(this->pos, this->size, sf::Color::White);
    cx.restore();
  }
  void tick() {
    this->pos += 0.5;
  }
};

int main() {
  engine::init(Config(C2d(800,600), "test"));
  act::define("test", std::vector<std::string>());
  Scene0 x;
  x.load();
  bck::spawnBackground(new SolidBackground(sf::Color::Magenta));
  act::spawn("test", new Test0());
  engine::mainLoop();
}
