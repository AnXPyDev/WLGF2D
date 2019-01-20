#include "../main.hpp"

void wgf::Scene::onLoad() {};
void wgf::Scene::afterLoad() {};
void wgf::Scene::beforeLoad() {};

// Scene Constructor
wgf::Scene::Scene(C2d size, int tps) {
  this->size = size;
  this->tps = tps;
}

// Scene loading
void wgf::Scene::load() {
  for(int x = act::instances.size() - 1; x > -1; x--) {
    for(int y = act::instances[x].size() - 1; y > -1; y--) {
      if(!act::instances[x][y]->persistent) {
	act::kill(act::instances[x][y]->name, y);
      }
    }
  }
  this->beforeLoad();
  wgf::game::scene = this;
  this->onLoad();
  this->afterLoad();
  
};
