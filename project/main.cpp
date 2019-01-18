#include "../main.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

wgf::C2d testCoord(200,200);

class Scene0 : public wgf::Scene {
public:
  Scene0() : wgf::Scene(wgf::C2d(800,600), 60) {};
};

int main() {
  wgf::engine::init(wgf::Config(wgf::C2d(800,600), "test"));
  Scene0 x;
  x.load();
  wgf::bck::spawnBackground(new wgf::SolidBackground(sf::Color::Magenta));
  wgf::engine::mainLoop();
}
