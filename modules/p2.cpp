#include "../main.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

wgf::P2d::P2d() {
  this->pointCount = 0;
  this->points = std::vector<C2d>({});
}

wgf::P2d::P2d(std::vector<C2d> points) {
  this->pointCount = points.size();
  this->points = points;
}

void wgf::P2d::setPoints(std::vector<C2d> points) {
  this->pointCount = points.size();
  this->points = points;
}

sf::ConvexShape wgf::P2d::sfShape() {
  sf::ConvexShape result;
  result.setPointCount(this->pointCount);
  for(int i = 0; i < this->pointCount; i++) {
    result.setPoint(i, this->points[i].toSfVector());
  }
  return result;
}

sf::VertexArray wgf::P2d::sfArray() {
  sf::VertexArray result(sf::TriangleFan, this->pointCount);
  for(int i = 0; i < this->pointCount; i++) {
    result[i].position = this->points[i].toSfVector();
  }
  return result;
}
