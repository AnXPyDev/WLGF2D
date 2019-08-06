#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../main.hpp"

wgf::Window window(wgf::C2d(640, 640), "test");

wgf::C2d boardSize(20,20);

wgf::C2d cellSize(window.size / boardSize);


class Snake : public wgf::Actor {
public:
	wgf::C2d boardPos(0,0);
	
	
}

class Player : public wgf::Actor {
public:
	Player() : wgf::Actor("player") {
	}

	void tick() {
		
	}
	
	void draw() {
		wgf::draw::rect(this->pos, this->size, sf::Color::Green);
	}
};

class TestScene : public wgf::Scene {
public:
	TestScene() : wgf::Scene(wgf::C2d(640, 640), 60) {};
	void onLoad() {
		wgf::bck::spawn(new wgf::SolidBackground(sf::Color::White));
		wgf::act::spawn("player", new Player());
	}
};

TestScene testscene;

int main(int argc, char** argv) {
	wgf::engine::init(&window);
	wgf::act::define("player", std::vector<std::string>({}));
	testscene.load();
	wgf::engine::mainLoop();
}
