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
  float wrap(float x, float min, float max) {
    if(x < min) {
      return max;
    } else if (x > max) {
      return min;
    }
    return x;
  }
  int wrap(int x, int min, int max) {
    if(x < min) {
      return max;
    } else if (x > max) {
      return min;
    }
    return x;
  }
  double wrap(double x, double min, double max) {
    if(x < min) {
      return max;
    } else if (x > max) {
      return min;
    }
    return x;
  }
  float wrap(float x, float min, float max, bool precise) {
    if(x < min) {
      return max + (min - x);
    } else if (x > max) {
      return min + (x - max);
    }
    return x;
  }
  int wrap(int x, int min, int max, bool precise) {
    if(x < min) {
      return max + (min - x);
    } else if (x > max) {
      return min + (x - max);
    }
    return x;
  }
  double wrap(double x, double min, double max, bool precise) {
    if(x < min) {
      return max + (min - x);
    } else if (x > max) {
      return min + (x - max);
    }
    return x;
  }
  float lerp(float x, float y, float perc) {
    return (float) x + (y-x) * perc;
  }
  int lerp(int x, int y, int perc) {
    return (int) x + (y-x) * perc;
  }
  double lerp(double x, double y, double perc) {
    return (double) x + (y-x) * perc;
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
  float distanceBetween(wgf::C2d v1, wgf::C2d v2) {
    return std::sqrt(std::pow(v1.x - v2.x, 2) + std::pow(v1.y - v2.y, 2));
  }
  wgf::A2d angleBetween(wgf::C2d v1, wgf::C2d v2) {
    return wgf::A2d(M_PIf32 + std::atan2(v1.y - v2.y, v1.x - v2.x), true);
  }
}
