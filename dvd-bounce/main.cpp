#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../main.hpp"

using namespace wgf;

sf::Sprite sprite;
sf::Color colors[] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue};

class Scene0 : public Scene {
public:
  Scene0() : Scene(C2d(800,600), 60) {};
  void onLoad();
};

class Logo : public Actor {
public:
  Logo() : Actor("Logo") {
    this->pos = C2d();
    this->size = C2d(200,130);
    this->speed = C2d(5);
    this->spr_index = 0;
    this->clr_index = 0;

  }
  C2d speed;
  void tick();
  void draw();
  int spr_index;
  int clr_index;
  
};

void Logo::tick() {
  this->pos += this->speed;
  C2d bounds = game::scene->size / 2;
  C2d leftCorner = this->pos - (this->size / 2);
  C2d rightCorner = this->pos + (this->size / 2);
  if(leftCorner.x < -bounds.x || rightCorner.x > bounds.x) {
    this->speed.x *= -1;
    this->clr_index = util::wrap(this->clr_index + 1, 0, 2);
    sprite.setColor(colors[this->clr_index]);
  }
  if(leftCorner.y < -bounds.y || rightCorner.y > bounds.y) {
    this->speed.y *= -1;
    this->clr_index = util::wrap(this->clr_index + 1, 0, 2);
    sprite.setColor(colors[this->clr_index]);
  }
}

void Logo::draw() {
  cx.drawSprite(sprite, this->pos, this->size);
}

void Scene0::onLoad() {
  bck::spawnBackground(new SolidBackground(sf::Color::Black));
  act::spawn("Logo", new Logo());
}

int main(int argc, char **argv) {
  engine::init(Config(C2d(800,600), "dvd-bounce"));
  sf::Texture texture;
  texture.loadFromFile("./dvd-bounce/sprites/1.png");
  sprite.setTexture(texture);
  act::define("Logo", std::vector<std::string>({}));
  Scene0 s0;
  s0.load();

  engine::mainLoop();


  return 0;
}
