#include <SFML/Graphics.hpp>
#include <chrono>
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
}

// Definition of draw function
void wgf::engine::draw() {
  wgf::game::viewport.window.clear();
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
  while(wgf::game::viewport.window.isOpen()) {
    auto delta = std::chrono::system_clock::now() - t0;
    if(std::chrono::duration_cast<std::chrono::milliseconds>(delta).count() >= 1000 / wgf::game::scene->tps) {
      wgf::engine::tick();
      wgf::engine::draw();
      wgf::game::viewport.window.display();
      t0 = std::chrono::system_clock::now();
    }
    sf::Event event;
    while (wgf::game::viewport.window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	wgf::game::viewport.window.close();
      }
      if(event.type == sf::Event::LostFocus) wgf::isWinFocused = false;
      if(event.type == sf::Event::GainedFocus) wgf::isWinFocused = true;
      if (event.type == sf::Event::Resized) {
	// update the view to the new size of the game::viewport.window
	sf::FloatRect visibleArea(0, 0, wgf::game::viewport.size.x, wgf::game::viewport.size.y);
	wgf::game::viewport.window.setView(sf::View(visibleArea));
      }
    }
  }
}

void wgf::engine::init(wgf::Config config) {
  srand(time(NULL));
  wgf::game::viewport.set(config.viewsize, config.name);
  wgf::cx.set(&wgf::game::viewport);
}

bool wgf::isWinFocused = true;
