#include <math.h>
#include "../main.hpp"

namespace wgf::util {
  float clamp(float x, float min, float max) {
    if(x < min) {
      return min;
    } else if(x > max) {


      return max;
    } else {
      return x;
    }
  }
  int clamp(int x, int min, int max) {
    if(x < min) {
      return min;
    } else if(x > max) {
      return max;
    } else {
      return x;
    }
  }
  double clamp(double x, double min, double max) {
    if(x < min) {
      return min;
    } else if(x > max) {
      return max;
    } else {
      return x;
    }
  }
  float approach(float x, float y, float amt) {
    if(x < y) {
      return util::clamp(x - std::abs(amt), y, x);
    } else {
      return util::clamp(x + std::abs(amt), x, y);
    }
  }
  int approach(int x, int y, int amt) {
    if(x < y) {
      return util::clamp(x - std::abs(amt), y, x);
    } else {
      return util::clamp(x + std::abs(amt), x, y);
    }
  }
  double approach(double x, double y, double amt) {
    if(x < y) {
      return util::clamp(x - std::abs(amt), y, x);
    } else {
      return util::clamp(x + std::abs(amt), x, y);
    }
  }
  bool collides(Actor* a0, Actor* a1) {
    if((a0->pos.x + a0->size.x / 2 < a1->pos.x - a1->size.x / 2) ||
       (a1->pos.x + a1->size.x / 2 < a0->pos.x - a0->size.x / 2) ||
       (a0->pos.y + a0->size.y / 2 < a1->pos.y - a1->size.y / 2) ||
       (a1->pos.y + a1->size.y / 2 < a0->pos.y - a0->size.y / 2)) {
      return false;
    }
    return true;
  }
}
