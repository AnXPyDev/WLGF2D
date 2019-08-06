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
    sf::Vector2f toSfVector();
    C2d(sf::Vector2f sfVector);
    C2d(C2d original);
    C2d(float x, float y);
    C2d(float x);
    C2d();
  };

  class A2d {
  public:
    float value;
    void operator+= (A2d other);
    void operator+= (float x);
    void operator-= (A2d other);
    void operator-= (float x);
    void operator=  (A2d other);
    void operator*= (A2d other);
    void operator*= (float x);
    void operator/= (A2d other);
    void operator/= (float x);
    A2d operator/ (A2d other);
    A2d operator/ (float x);
    A2d operator* (A2d other);
    A2d operator* (float x);
    A2d operator+ (A2d other);
    A2d operator+ (float x);
    A2d operator- (A2d other);
    A2d operator- (float x);
    float getDeg();
    float getRad();
    A2d();
    A2d(float val);
    A2d(float val, bool rad);
  };

  class P2d {
  public:
    P2d();
    P2d(std::vector<C2d> points);
    int pointCount;
    std::vector<C2d> points;
    void setPoints(std::vector<C2d> points);
    sf::ConvexShape sfShape();
    sf::VertexArray sfArray();
  };

  class Window {
  public:
    Window(C2d size, std::string name);
    C2d size;
    sf::RenderWindow window;
    sf::View view;
    bool isFocused;
    void updateSize();
    void tickUpdate();
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
    sf::RectangleShape rect;
    void draw();
    SolidBackground(sf::Color color);
  };

  // Functions related to backgrounds
  namespace bck {
    extern std::vector<Background*> instances;
    void spawn(Background* background);
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
    // Wraps value around min and max
    float wrap(float x, float min, float max);
    int wrap(int x, int min, int max);
    double wrap(double x, double min, double max);
    // Wraps value around min and max precisely
    float wrap(float x, float min, float max, bool precise);
    int wrap(int x, int min, int max, bool precise);
    double wrap(double x, double min, double max, bool precise);
    // Linearly interpolates a value
    float lerp(float x, float y, float perc);
    int lerp(int x, int y, float perc);
    double lerp(double x, double y, float perc);
    // Returns true if the actors' rectangle bounds collide
    bool collides(Actor* a0, Actor* a1);
    float distanceBetween(C2d v1, C2d v2);
    A2d angleBetween(C2d v1, C2d v2);
  }
  
  // Holds information about project
  namespace game {
    extern Scene* scene;
    extern Window* window;
  }

  namespace draw {
    extern sf::RectangleShape draw_rect;
    void rect(C2d pos, C2d size, sf::Color color = sf::Color::Black, A2d angle = A2d());
    void line(C2d v1, C2d v2, float width = 1, sf::Color color = sf::Color::Black);
    void sprite(sf::Sprite sprite, C2d pos, C2d size, A2d angle = A2d());
  }
  
  // This namespace includes functions needed to initialize and run a project
  namespace engine {
    void mainLoop();
    void draw();
    void tick();
    void init(Window* window);
  }
}
