#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../main.hpp"

wgf::Canvas::Canvas(wgf::Viewport* view) {
  this->view = view;
  this->scale = C2d(1);
  this->base_offset = view->size / 2;
}

wgf::Canvas::Canvas() {}

void wgf::Canvas::set(wgf::Viewport* view) {
  this->view = view;
  this->scale = C2d(1);
  this->base_offset = view->size / 2;
  std::cout << this->base_offset.x << " " << this->base_offset.y << std::endl;
}

void wgf::Canvas::save() {
  this->save_translate.push_back(this->translate);
  this->save_scale.push_back(this->scale);
  this->save_rotation_origin.push_back(this->rotation_origin);
  this->save_rotation.push_back(this->rotate);
}

void wgf::Canvas::restore() {
  this->translate = this->save_translate[this->save_translate.size() - 1];
  this->scale = this->save_scale[this->save_scale.size() - 1];
  this->rotation_origin = this->save_rotation_origin[this->save_rotation_origin.size() - 1];
  this->rotate = (this->save_rotation[this->save_rotation.size()]);
  this->save_translate.pop_back();
  this->save_scale.pop_back();
  this->save_rotation_origin.pop_back();
  this->save_rotation.pop_back();
}

void wgf::Canvas::drawRect(wgf::C2d pos, wgf::C2d size, sf::Color color = sf::Color::Green) {
  sf::RectangleShape rect;
  wgf::C2d r_pos = (pos - this->translate) * this->scale;
  wgf::C2d r_size = size * this->scale;
  rect.setPosition((int)(r_pos.x - r_size.x / 2 + this->base_offset.x), (int)(r_pos.y - r_size.y / 2 + this->base_offset.y));
  rect.setSize(sf::Vector2f(r_size.x, r_size.y));
  rect.setFillColor(color);
  this->view->window.draw(rect);
}
