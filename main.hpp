#pragma once

//  _    _ _     _____ ______ _____ ______ 
// | |  | | |   |  __ \|  ___/ __  \|  _  \
// | |  | | |   | |  \/| |_  `' / /'| | | |
// | |/\| | |   | | __ |  _|   / /  | | | |
// \  /\  / |___| |_\ \| |   ./ /___| |/ / 
//  \/  \/\_____/\____/\_|   \_____/|___/

// Created by AnXPyDev at https://github.com/anxpydev under the GPL2 license

// Feel free to modify and redistribute or do whatever you want with this
// After all you are free ...
                                        
// This is the main header file used by WLGF2D
// In this file is included the global namespace containing every component of the engine

// This game engine/framework (i dont care) uses the SFML2 library for rendering graphics, and doing stuff with audio (possibly in the future)
#include <SFML/Graphics.hpp>
#include <string>

// This namespace contains every component of the engine, as mentioned before
namespace wgf {
  using namespace wgf;

  // This class is used for storing coordinates in a two dimensional space (x and y axis)
  class C2 {
  public:
    float x, y; // These store the position
    void operator+= (C2 other); // Increments x and y value of this instance by the other instances values
    void operator=  (C2 other); // Copies x and y values of other to this
    C2(float x, float y);
    C2(float x);
    C2();
  private:
  };

  // Class used for configuring initialization of game engine
  class Config {
  public:
    C2 viewsize;
    std::string name;
    Config(C2 viewsize, std::string name);
  };

  // This namespace includes functions needed to initialize and run a project
  namespace engine {
    void mainLoop();
    void draw();
    void tick();
    void init(Config config);
  }

}
