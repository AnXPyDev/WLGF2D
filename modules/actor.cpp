#include "../main.hpp"
#include <string>
#include <map>


// Constructor for actor class
wgf::Actor::Actor(std::string name) {
  this->id = 0;
  this->pos = wgf::C2d();
  this->size = wgf::C2d();
  this->name = name;
  this->persistent = false;
}

void wgf::Actor::update() {
  this->tick();
};

void wgf::Actor::tick() {};
void wgf::Actor::draw() {};


namespace wgf::act {
  // Vector of pointers to Actor instances
  std::vector<std::vector<Actor*>> instances;
  // Map of keys and indexes, the keys are names of actors and indexes are the indexes of instances of actors in act::instances
  std::map<std::string, int> keys;
  // Map of traits and vectors, which contain names of actors which have this trait
  std::map<std::string, std::vector<std::string>> traits;

  // Spawns an actor by placing a pointer to it inside act::instances
  Actor* spawn(std::string name, Actor* instance) {
    instance->id = wgf::act::instances[keys[name]].size();
    wgf::act::instances[wgf::act::keys[name]].push_back(instance);
    return instance;
  }
  // Kills an actor by removing it from the act::instances vector
  // Also lowers ids of instances after it by one
  void kill(std::string name, int id) {
    int index = wgf::act::keys[name];
    wgf::act::instances[index].erase(wgf::act::instances[index].begin() + id);
    for(int n = id; n < wgf::act::instances[index].size(); n++) {
      wgf::act::instances[index][n]->id--;
    }
  }
  // Returns a pointer to the instance with the id
  Actor* get(std::string name, int id) {
    return wgf::act::instances[wgf::act::keys[name]][id];
  }
  // Returns a map of char*(names) and vectors of pointers to actors
  std::map<std::string, std::vector<Actor*>> getByTraitByName(std::vector<std::string> traits) {
    std::map<std::string, int> counts;
    std::map<std::string, std::vector<Actor*>> result;
    for(int i = 0; i < traits.size(); i++) {
      for(int n = 0; n < wgf::act::traits[traits[i]].size(); n++) {
	if(counts.find(wgf::act::traits[traits[i]][n]) == counts.end()) {
	  counts[wgf::act::traits[traits[i]][n]] = 0;
	}
	counts[wgf::act::traits[traits[i]][n]]++;
	if(counts[wgf::act::traits[traits[i]][n]] == traits.size()) {
	  if(result.find(wgf::act::traits[traits[i]][n]) == result.end()) {
	    result[wgf::act::traits[traits[i]][n]] = wgf::act::instances[wgf::act::keys[wgf::act::traits[traits[i]][n]]];
	  }
	}
      }
    }
    return result;
  }
  // Returns all instances that have the traits but not
  std::vector<Actor*> getByTrait(std::vector<std::string> traits) {
    std::vector<Actor*> result;
    std::map<std::string, std::vector<Actor*>> names = wgf::act::getByTraitByName(traits);
    for(std::map<std::string, std::vector<Actor*>>::iterator i = names.begin(); i != names.end(); i++) {
      result.insert(result.end(), i->second.begin(), i->second.end());
    }
    return result;
    
  }
  // Defines actor
  int define(std::string name, std::vector<std::string> traits) {
    int index = act::instances.size();
    wgf::act::keys[name] = index;
    wgf::act::instances.push_back(std::vector<Actor*>());
    for(int i = 0; i < traits.size(); i++) {
      if(wgf::act::traits.find(traits[i]) == wgf::act::traits.end()) {
	wgf::act::traits[traits[i]] = std::vector<std::string>();
      }
      wgf::act::traits[traits[i]].push_back(name);
    }
    return index;
  }
}
