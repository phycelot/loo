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

  void
  Rectangle::move(const Window &win, double dt)
  {
    angle(angle_+angularSpeed_*dt);
    Shape::move(win,dt);
  }


  void
  draw(const Rectangle &c, sf::RenderWindow &rw)
  {
    auto [w,h]=c.size();
    sf::RectangleShape s{sf::Vector2f{float(w),float(h)}};
    auto color=c.color();
    s.setFillColor(sf::Color{color[0],color[1], color[2]});
    auto [x,y]=c.position();
    s.setPosition(float(x),float(y));
    s.setRotation(float(c.angle()));
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
