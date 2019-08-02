#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "../main.hpp"

wgf::Window window(wgf::C2d(640, 640), "test");


class Player : public wgf::Actor {
public:
	Player() : wgf::Actor("player") {
		this->pos = wgf::C2d(20);
		this->size = wgf::C2d(20);
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
