#include "../main.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace wgf;

class Scene0 : public wgf::Scene {
public:
  Scene0() : Scene(wgf::C2d(800,600), 60) {};
  void onLoad();
};

Scene0 s0;

class Paddle : public wgf::Actor {
public:
  Paddle(float ypos) : Actor("paddle") {
    this->pos = C2d(0, (game::scene->size.y / 2) * 0.75);
    this->size = C2d(75,10);
    this->speed = 10;
  };
  void tick();
  void draw();
  float speed;
};

void Paddle::tick() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && isWinFocused) {
    this->pos.x -= this->speed;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && isWinFocused) {
    this->pos.x += this->speed;
  }
  this->pos.x = util::clamp(this->pos.x, (float)-400, (float)400);
  
}

void Paddle::draw() {
  cx.drawRect(this->pos, this->size, sf::Color::White);
}

class Ball : public Actor {
public:
  C2d velocity;
  void tick();
  void draw();
  Ball();
};

void Ball::tick() {
  this->pos.x += this->velocity.x;
  this->pos.y += this->velocity.y;
  if(this->pos.y - this->size.y / 2 <= -game::scene->size.y / 2 || this->pos.y + this->size.y / 2 >= game::scene->size.y / 2) {
    this->velocity.y *= -1;
  }
  auto toCheck = act::getByTrait(std::vector<std::string>({"solid"}));
  for(int i = 0; i < toCheck.size(); i++) {
    if(util::collides(this, toCheck[i])) {
      if(toCheck[i]->name == "brick") {
	act::kill("brick", toCheck[i]->id);
	if(act::instances[act::keys["brick"]].size() == 0) {
	  s0.load();
	}
      }

      float overlapX = (this->size.x / 2 + toCheck[i]->size.x / 2) - std::abs(this->pos.x - toCheck[i]->pos.x);
      float overlapY = (this->size.y / 2 + toCheck[i]->size.y / 2) - std::abs(this->pos.y - toCheck[i]->pos.y);
      if(overlapX < overlapY) {
	this->velocity.x *= -1;
      } else if (overlapY < overlapX) {
	this->velocity.y *= -1;
      } else {
	this->velocity.x *= -1;
	this->velocity.y *= -1;
      }


	
    }
  }
  
  if(this->pos.x - this->size.x / 2 <= -game::scene->size.x / 2 || this->pos.x + this->size.x / 2 >= game::scene->size.x / 2) {
      this->velocity.x *= -1;
  }
}

void Ball::draw() {
  cx.drawRect(this->pos, this->size, sf::Color::White);
}

Ball::Ball() : Actor("ball") {
  this->velocity.x = (rand() % 3 + 4) * (rand() % 100 < 50 ? -1:1);
  this->velocity.y = (rand() % 3 + 4) * (rand() % 100 < 50 ? -1:1);
  this->pos = C2d();
  this->size = C2d(10);
  this->persistent = true;
}

class Brick : public Actor {
public:
  void draw();
  Brick(C2d _pos) : Actor("brick") {
    this->pos = _pos;
    this->size = C2d(60,20);
  };
};

void Brick::draw() {
  cx.drawRect(this->pos, this->size, sf::Color::White);
}

void Scene0::onLoad() {
  bck::spawnBackground(new SolidBackground(sf::Color::Black));
  act::spawn("paddle", new Paddle(250));
  act::spawn("ball", new Ball());
  for(int x = -game::scene->size.x / 2 + 40; x < game::scene->size.x / 2; x += 80) {
    for(int y = -game::scene->size.y / 2 + 20; y < -120; y += 40) {
      act::spawn("brick", new Brick(C2d(x,y)));
    }
  }
}

int main() {
  engine::init(Config(C2d(800,600), "breakout"));
  act::define("paddle", std::vector<std::string>({"solid"}));
  act::define("ball", std::vector<std::string>());
  act::define("brick", std::vector<std::string>({"solid"}));
  s0.load();
  engine::mainLoop();
}
