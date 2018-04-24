#include "circle.hpp"
#include "window.hpp"
#include <iostream>

namespace s5loo {
  Circle::Circle(double x, double y, double sx, double sy, double radius, Color color):
    x_{x},
    y_{y},
    sx_{sx},
    sy_{sy},
    radius_{radius},
    color_{color}
    {}

  void
  Circle::move(const Window &win, double dt)
  {
    x_+=dt*sx_;
    y_+=dt*sy_;

    auto [winx,winy]=win.size();
    if (x_>winx-radius_*2) {
      sx_=-sx_;
      x_=winx-radius_*2;
    }
    else if (x_<radius_)    {
      sx_=-sx_;
      x_=0;
    }
    if (y_>winy-radius_*2) {
      sy_=-sy_;
      y_=winy-radius_*2;
    }
    else if (y_<radius_)    {
      sy_=-sy_;
      y_=0;
    }
    // std::cout << "x=" << x_ << ",y=" << y_ << ",radius=" << radius_<< '\n';
  }


  void draw(const Circle &c, sf::RenderWindow &rw)
  {
    sf::CircleShape s{float(c.radius())};
    auto color=c.color();
    s.setFillColor(sf::Color{color[0],color[1], color[2]});
    auto [x,y]=c.position();
    s.setPosition(float(x),float(y));
    rw.draw(s);
  }
}
