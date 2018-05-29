#include "rectangle.hpp"
#include "window.hpp"
#include <iostream>
#include <cmath>

namespace s5loo {
  Rectangle::Rectangle(double x, double y, double sx, double sy, double height, double width, double angularSpeed, Color color):
    Shape{x,y,sx,sy,color},
    height_{height},
    width_{width},
    angularSpeed_{angularSpeed},
    angle_{0.0}
    {}

  double Rectangle::boundingSphere() {
    // const double radius=std::sqrt(width_*width_+height_*height_);
    return std::sqrt(width_*width_+height_*height_);
  }

  void
  Rectangle::move(const Window &win, double dt)
  {
    // angle(angle_+angularSpeed_*dt);
    Shape::move(win,dt);
  }

  void
  Rectangle::do_click(sf::RenderWindow& win, int x, int y){
  }

  void
  Rectangle::draw(sf::RenderWindow &rw) const
  {
    auto [w,h]=size();
    sf::RectangleShape s{sf::Vector2f{float(w),float(h)}};
    auto c=color();
    s.setFillColor(sf::Color{c[0],c[1], c[2]});
    auto [x,y]=position();
    s.setPosition(float(x-w/2),float(y-h/2));
    s.setRotation(float(angle()));
    rw.draw(s);
  }
  void
  Rectangle::angle(double a)
  {
    while (a<-180.0) {
      a+=360.0;
    }
    while (a>180.0) {
      a-=360.0;
    }
    angle_=a;
  }
}
