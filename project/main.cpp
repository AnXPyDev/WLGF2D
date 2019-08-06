
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../main.hpp"

using namespace std;
using namespace wgf;

Window window(C2d(640, 640), "snake");

C2d boardSize(20,20);
C2d cellSize(window.size / boardSize);

class Snake : public Actor {
public:
  vector<C2d> chain;
  C2d velocity;
  C2d boardPos;
  Snake() : Actor("snake") {
    this->boardPos = C2d(0);
    this->chain.push_back(this->boardPos);
    this->velocity = C2d(1,0);
  }

  void tick() {
    this->boardPos = this->boardPos + this->velocity;
    this->chain.push_back(this->boardPos);
    this->chain.erase(this->chain.begin());
  }

  void draw() {
    for (int i = 0; i < this->chain.size(); i++) {
      draw::rect(this->chain[i] * cellSize, cellSize, sf::Color::Green);
    }
  }
};

class MainScene : public Scene {
public:
	MainScene() : Scene(window.size, 5) {};
	void onLoad() {
		bck::spawn(new SolidBackground(sf::Color::White));
		act::spawn("snake", new Snake());
	}
};

MainScene mainscene;

int main(int argc, char** argv) {
	engine::init(&window);
	act::define("player", std::vector<std::string>({}));
	mainscene.load();
	engine::mainLoop();
}
