#include "../main.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace wgf::draw {
  sf::RectangleShape draw_rect;
  void rect(wgf::C2d pos, wgf::C2d size, sf::Color color, wgf::A2d angle) {
    wgf::draw::draw_rect.setPosition(pos.x, pos.y);
    wgf::draw::draw_rect.setSize(size.toSfVector());
    wgf::draw::draw_rect.setOrigin((size / 2).toSfVector());
    wgf::draw::draw_rect.setFillColor(color);
    wgf::draw::draw_rect.setRotation(-angle.getDeg());
    wgf::game::window->window.draw(wgf::draw::draw_rect);
  }
  void line(wgf::C2d v1, wgf::C2d v2, float width, sf::Color color) {
    auto size = sf::Vector2f(wgf::util::distanceBetween(v1, v2), width);
    wgf::draw::draw_rect.setPosition(v1.toSfVector());
    wgf::draw::draw_rect.setSize(size);
    wgf::draw::draw_rect.setOrigin(sf::Vector2f(0, width / 2));
    wgf::draw::draw_rect.setFillColor(color);
    wgf::draw::draw_rect.setRotation(-wgf::util::angleBetween(v1, v2).getDeg());
    wgf::game::window->window.draw(wgf::draw::draw_rect);
  }
  void sprite(sf::Sprite sprite, wgf::C2d pos, wgf::C2d size, wgf::A2d angle) {
    auto spriteSize = sprite.getTexture()->getSize();
    wgf::C2d scale = wgf::C2d(spriteSize.x, spriteSize.y) / size;
    sprite.setPosition(pos.toSfVector());
    sprite.setScale(scale.toSfVector());
    sprite.setOrigin((size / 2).toSfVector());
    sprite.setRotation(-angle.getDeg());
    wgf::game::window->window.draw(sprite);
  }
}
