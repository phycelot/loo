#include "circle.hpp"
#include "window.hpp"
#include <iostream>

namespace s5loo {
  Circle::Circle(double x, double y, double sx, double sy, double radius, Color color):
    Shape{x,y,sx,sy,color},
    radius_{radius}
    {}

  // void
  // Circle::move(const Window &win, double dt)
  // {
  //   x_+=dt*sx_;
  //   y_+=dt*sy_;
  //
  //   auto [winx,winy]=win.size();
  //   if (x_>winx-radius_) {
  //     sx_=-sx_;
  //     x_=winx-radius_;
  //   }
  //   else if (x_<=radius_)    {
  //     sx_=-sx_;
  //     x_=radius_;
  //   }
  //   if (y_>winy-radius_) {
  //     sy_=-sy_;
  //     y_=winy-radius_;
  //   }
  //   else if (y_<=radius_)    {
  //     sy_=-sy_;
  //     y_=radius_;
  //   }
  //   // std::cout << "x=" << x_ << ",y=" << y_ << ",radius=" << radius_<< '\n';
  // }


  void draw(const Circle &c, sf::RenderWindow &rw)
  {
    sf::CircleShape s{float(c.radius())};
    auto color=c.color();
    s.setFillColor(sf::Color{color[0],color[1], color[2]});
    auto [x,y]=c.position();
    s.setPosition(float(x-c.radius()),float(y-c.radius()));
    rw.draw(s);
  }
}
