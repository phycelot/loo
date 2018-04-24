#include "rectangle.hpp"
#include "window.hpp"
#include <iostream>
#include <cmath>

namespace s5loo {
  Rectangle::Rectangle(double x, double y, double sx, double sy, double height, double width, double angularSpeed, Color color):
    x_{x},
    y_{y},
    sx_{sx},
    sy_{sy},
    height_{height},
    width_{width},
    angularSpeed_{angularSpeed},
    color_{color},
    angle_{0.0}
    {}

  void
  Rectangle::move(const Window &win, double dt)
  {
    const double radius=std::sqrt(width_*width_+height_*height_);
    x_+=dt*sx_;
    y_+=dt*sy_;

    auto [winx,winy]=win.size();
    if (x_>winx-radius) {
      sx_=-sx_;
      x_=winx-radius;
    }
    else if (x_<=radius)    {
      sx_=-sx_;
      x_=radius;
    }
    if (y_>winy-radius) {
      sy_=-sy_;
      y_=winy-radius;
    }
    else if (y_<=radius)    {
      sy_=-sy_;
      y_=radius;
    }
    // std::cout << "x=" << x_ << ",y=" << y_ << '\n';
  }


  void
  draw(const Rectangle &c, sf::RenderWindow &rw)
  {
    // sf::RectangleShape s{float(c.radius())};
    // auto color=c.color();
    // s.setFillColor(sf::Color{color[0],color[1], color[2]});
    // auto [x,y]=c.position();
    // s.setPosition(float(x-c.radius()),float(y-c.radius()));
    // rw.draw(s);
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
