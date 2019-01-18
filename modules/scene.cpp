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
  this->beforeLoad();
  wgf::game::scene = this;
  this->onLoad();
  this->afterLoad();
  
};
