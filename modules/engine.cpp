#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include "../main.hpp"

// Definition of tick function
void wgf::engine::tick() {
  for(int x = 0; x < wgf::bck::instances.size(); x++) {
    wgf::bck::instances[x]->update();
  }
  for(int x = 0; x < wgf::act::instances.size(); x++) {
    for(int y = 0; y < wgf::act::instances[x].size(); y++) {
      wgf::act::instances[x][y]->update();
    }
  }
  wgf::game::window->tickUpdate();
}

// Definition of draw function
void wgf::engine::draw() {
  wgf::game::window->window.clear();
  for(int x = 0; x < wgf::bck::instances.size(); x++) {
    wgf::bck::instances[x]->draw();
  }
  for(int x = 0; x < wgf::act::instances.size(); x++) {
    for(int y = 0; y < wgf::act::instances[x].size(); y++) {
      wgf::act::instances[x][y]->draw();
    }
  }
  
}

// Definition of mainLoop
void wgf::engine::mainLoop() {
  auto t0 = std::chrono::system_clock::now();
  while(wgf::game::window->window.isOpen()) {
    auto delta = std::chrono::system_clock::now() - t0;
    if(std::chrono::duration_cast<std::chrono::milliseconds>(delta).count() >= 1000 / wgf::game::scene->tps) {
      wgf::engine::tick();
      wgf::engine::draw();
      wgf::game::window->window.display();
      t0 = std::chrono::system_clock::now();
    }
    sf::Event event;
    while (wgf::game::window->window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	wgf::game::window->window.close();
      }
      if(event.type == sf::Event::LostFocus) wgf::game::window->isFocused = false;
      if(event.type == sf::Event::GainedFocus) wgf::game::window->isFocused = true;
      if (event.type == sf::Event::Resized) {
	// update the view to the new size of the game::viewport.window
	wgf::game::window->updateSize();
      }
    }
  }
  std::cout << "\n";
}

void wgf::engine::init(wgf::Window* window) {
  srand(time(NULL));
  wgf::game::window = window;
}
