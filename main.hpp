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
#include <vector>
#include <map>

// This namespace contains every component of the engine, as mentioned before
namespace wgf {
  using namespace wgf;

  // This class is used for storing coordinates in a two dimensional space (x and y axis)
  class C2d {
  public:
    float x, y; // These store the position
    void operator+= (C2d other); // Increments x and y value of this instance by the other instances values
    void operator+= (float x); // Increments x and y value of this instance by the other instances values
    void operator-= (C2d other); // Increments x and y value of this instance by the other instances values
    void operator-= (float x); // Increments x and y value of this instance by the other instances values
    void operator=  (C2d other); // Copies x and y values of other to this
    void operator*= (C2d other); // Multiplies x and y values of this by other's values
    void operator*= (float x); // Multiplies x and y values of this by other's values
    void operator/= (C2d other); // Divides x and y values of this by other's values
    void operator/= (float x); // Divides x and y values of this by other's values
    C2d operator/ (C2d other); // Divides x and y values of this by other's values and returns new C2d
    C2d operator/ (float x); // Divides x and y values of this by other's values and returns new C2d
    C2d operator* (C2d other); // Divides x and y values of this by other's values and returns new C2d
    C2d operator* (float x); // Divides x and y values of this by other's values and returns new C2d
    C2d operator+ (C2d other); // Divides x and y values of this by other's values and returns new C2d
    C2d operator+ (float x); // Divides x and y values of this by other's values and returns new C2d
    C2d operator- (C2d other); // Divides x and y values of this by other's values and returns new C2d
    C2d operator- (float x); // Divides x and y values of this by other's values and returns new C2d
    C2d(float x, float y);
    C2d(float x);
    C2d();
  };

  // Class used for configuring initialization of game engine
  struct Config {
    C2d viewsize;
    std::string name;
    Config(C2d viewsize, std::string name);
  };

  // Viewport class stores SFML window instances
  class Viewport {
  public:
    C2d size;
    sf::RenderWindow window;
    void set(C2d size, std::string name);
    Viewport();
  };

  class Canvas {
  public:
    sf::RectangleShape draw_rect;
    Viewport* view;
    std::vector<C2d> save_translate;
    std::vector<C2d> save_scale;
    std::vector<C2d> save_rotation_origin;
    std::vector<float> save_rotation;
    C2d translate;
    C2d scale;
    C2d rotation_origin;
    C2d base_offset;
    float rotate;
    void save();
    void restore();
    void drawRect(C2d pos, C2d size, sf::Color color);
    Canvas(Viewport* view);
    Canvas();
    void set(Viewport* view);
  };

  // Basic prototype for ingame object (actor)
  class Actor {
  public:
    int id;
    std::string name;
    bool persistent;
    C2d pos;
    C2d size;
    void update();
    virtual void tick();
    virtual void draw();
    Actor(std::string name = "default");
  };

  // Class for a room like object
  class Scene {
  public:
    C2d size;
    int tps;
    void load();
    virtual void beforeLoad();
    virtual void onLoad();
    virtual void afterLoad();
    Scene(C2d size, int tps);
  };

  // Background class
  class Background {
  public:
    void update();
    virtual void draw();
    virtual void tick();
    Background();
  };

  // Background with solid color
  class SolidBackground : public Background {
  public:
    sf::Color color;
    void draw();
    SolidBackground(sf::Color color);
  };

  // Functions related to backgrounds
  namespace bck {
    extern std::vector<Background*> instances;
    void spawnBackground(Background* background);
  }

  // Functions related to actors
  namespace act {
    // Holds currently existing instances of actors
    extern std::vector<std::vector<Actor*>> instances;
    // Keys to index of actor name in act::instances
    extern std::map<std::string, int> keys;
    // Map of traits and their Actors
    extern std::map<std::string, std::vector<std::string>> traits;
    // Defines actors
    int define(std::string name, std::vector<std::string> traits);
    // Spawns actor
    Actor* spawn(std::string name, Actor* instance);
    // Kills actor
    void kill(std::string name, int id);
    // Returns pointer to actor
    Actor* get(std::string name, int id);
    // Returns actors by traits sorted by name
    std::map<std::string, std::vector<Actor*>> getByTraitByName(std::vector<std::string> traits);
    // Returns actors in a single vector
    std::vector<Actor*> getByTrait(std::vector<std::string> traits);
  }

  extern Canvas cx;

  // Utility functions
  namespace util { 
    // Clamps a value between a min and max value
    float clamp(float x, float min, float max);
    int clamp(int x, int min, int max);
    double clamp(double x, double min, double max);
    // Aproaches to value by ammount
    float approach(float x, float y, float amt);
    int approach(int x, int y, int amt);
    double approach(double x, double y, double amt);
    // Returns true if the actors' rectangle bounds collide
    bool collides(Actor* a0, Actor* a1);
  }
  
  // Holds information about project
  namespace game {
    extern Viewport viewport;
    extern Scene* scene;
  }
  
  // This namespace includes functions needed to initialize and run a project
  namespace engine {
    void mainLoop();
    void draw();
    void tick();
    void init(Config config);
  }

  extern bool isWinFocused;


}
