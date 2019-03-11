#include "../main.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace wgf;

class Scene0 : public Scene {
public:
  Scene0() : Scene(wgf::C2d(800,600), 60) {};
  void onLoad();
};

Scene0 s0;

class Player : public Actor {
public:
  Player() : Actor("player") {
    this->pos.x = 0;
    this->pos.y = 0;
    this->size = C2d(50);
    this->speed = C2d(5);
  };
  virtual void tick();
  virtual void draw();
  C2d speed;
};

void Player::tick() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->pos.y -= this->speed.y;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    this->pos.y += this->speed.y;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->pos.x -= this->speed.x;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->pos.x += this->speed.x;
  }
}

void Player::draw() {
  cx.drawRect(this->pos, this->size, sf::Color::White);
}

void Scene0::onLoad() {
  bck::spawnBackground(new SolidBackground(sf::Color::Black));
  act::spawn("player", new Player());
}

int main() {
  engine::init(Config(C2d(800,600), "breakout"));
  act::define("player", std::vector<std::string>({"solid"}));
  s0.load();
  engine::mainLoop();
}
