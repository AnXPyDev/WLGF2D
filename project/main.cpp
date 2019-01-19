#include "../main.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace wgf;

class Scene0 : public wgf::Scene {
public:
  Scene0() : Scene(wgf::C2d(800,600), 60) {};
  void onLoad();
};

class Paddle : public wgf::Actor {
public:
  Paddle(float ypos) : Actor(wgf::C2d(0, ypos), wgf::C2d(50, 10), "paddle") {
    this->speed = 10;
  };
  void tick();
  void draw();
  float speed;
};

void Paddle::tick() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    this->pos.x -= this->speed;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    this->pos.x += this->speed;
  }
  this->pos.x = util::clamp(this->pos.x, (float)-400, (float)400);
  
}

void Paddle::draw() {
  cx.drawRect(this->pos, this->size, sf::Color::White);
}

void Scene0::onLoad() {
  bck::spawnBackground(new SolidBackground(sf::Color::Black));
  act::spawn("paddle", new Paddle(250));
}

int main() {
  engine::init(Config(C2d(800,600), "breakout"));
  act::define("paddle", std::vector<std::string>({"solid"}));
  Scene0 x;
  x.load();
  engine::mainLoop();
}
