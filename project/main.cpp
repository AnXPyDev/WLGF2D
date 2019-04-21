#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../main.hpp"

wgf::Window window(wgf::C2d(400,400), "test");
sf::RenderWindow* cx;
wgf::C2d boardSize(20,20);
wgf::C2d cellSize(window.size.x / boardSize.x, window.size.y / boardSize.y);

int randint(int min, int max) {
  return random() % (max - min) + min;
}

class Apple : public wgf::Actor {
public:
  wgf::C2d boardPos;
  Apple() : wgf::Actor("apple") {
    this->boardPos = wgf::C2d(randint(0, boardSize.x - 1), randint(0, boardSize.y - 1));
  }
  void draw() {
    wgf::draw::rect(this->boardPos * cellSize, cellSize, sf::Color::Red);
  }
};

class Snake : public wgf::Actor {
public:
  wgf::C2d dir;
  std::vector<wgf::C2d> chain;
  wgf::C2d boardPos;
  Snake() : wgf::Actor("snake") {
    this->dir = wgf::C2d(1,0);
    this->boardPos = wgf::C2d(std::round(boardSize.x / 2), std::round(boardSize.y / 2));
    this->chain.push_back(this->boardPos);
  }
  void tick() {
    this->boardPos += this->dir;
    this->chain.pop_back();
    std::vector<wgf::C2d> front({this->boardPos});
    this->chain.insert(this->chain.begin(), front.begin(), front.end());
  }
  void draw() {
    for(int i = 0; i < this->chain.size(); i++) {
      wgf::draw::rect(this->chain[i] * cellSize, cellSize, sf::Color::Green);
    }
  }
};


  


class Player : public wgf::Actor {
public:
  float baseLen;
  float bend;
  Player() : wgf::Actor("player") {
    this->baseLen = 500;
    this->bend = 0;
  }
  void tick() {
    this->bend += 1;
  }
  void draw() {
    int height = std::sin(std::acos(this->baseLen / ( this->baseLen + this->bend ))) * (this->baseLen + this->bend);
    wgf::draw::line(wgf::C2d(-this->baseLen / 2, 0), wgf::C2d(this->baseLen / 2, 0), 5, sf::Color::Black);
    wgf::draw::line(wgf::C2d(this->baseLen / 2, 0), wgf::C2d(this->baseLen / 2, height), 5, sf::Color::Black);
    wgf::draw::line(wgf::C2d(-this->baseLen / 2, 0), wgf::C2d(this->baseLen / 2, height), 5, sf::Color::Black);
    std::cout << this->bend << " " << height << "\n";
  }
};

class TestScene : public wgf::Scene {
public:
  TestScene() : wgf::Scene(wgf::C2d(1280,1280), 5) {};
  void onLoad() {
    wgf::bck::spawn(new wgf::SolidBackground(sf::Color::White));
    wgf::act::spawn("snake", new Snake());
    wgf::act::spawn("apple", new Apple());    
  }
};

TestScene scene0;

int main(int argc, char** argv) {
  cx = &window.window;
  wgf::engine::init(&window);
  wgf::act::define("snake", std::vector<std::string>({}));
  wgf::act::define("apple", std::vector<std::string>({}));  
  scene0.load();
  wgf::engine::mainLoop();
}
