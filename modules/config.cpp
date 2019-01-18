#include "../main.hpp"
#include <string>

wgf::Config::Config(wgf::C2d viewsize, std::string name) {
  this->name = name;
  this->viewsize = viewsize;
}
