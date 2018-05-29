#include "circle.hpp"
#include "window.hpp"
#include <iostream>

namespace s5loo {
  Circle::Circle(double x, double y, double sx, double sy, double radius, Color color):
    Shape{x,y,sx,sy,color},
    radius_{radius}
    {}

  void
  Circle::move(const Window &win, double dt)
  {
    Shape::move(win,dt);
  }

  double Circle::boundingSphere() {
    return radius();
  }

  void Circle::do_click(sf::RenderWindow& win, int x, int y){
    std::cout << "Circle::do_click" << '\n';
  }

  double
  Circle::area()
  {
    return 3.14*radius_*radius_;
  }

  void Circle::draw(sf::RenderWindow &rw) const
  {
    sf::CircleShape s{float(radius())};
    auto c=color();
    s.setFillColor(sf::Color{c[0],c[1], c[2]});
    auto [x,y]=position();
    s.setPosition(float(x-radius()),float(y-radius()));
    rw.draw(s);
  }
}
