#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../main.hpp"

wgf::Window window(wgf::C2d(1280, 1280), "test");
sf::RenderWindow* cx;

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
  TestScene() : wgf::Scene(wgf::C2d(1280,1280), 60) {};
  void onLoad() {
    wgf::bck::spawn(new wgf::SolidBackground(sf::Color::White));
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
