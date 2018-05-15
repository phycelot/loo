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
    // x_+=dt*sx_;
    // y_+=dt*sy_;
    //
    // auto [winx,winy]=win.size();
    // if (x_>winx-radius_) {
    //   sx_=-sx_;
    //   x_=winx-radius_;
    // }
    // else if (x_<=radius_)    {
    //   sx_=-sx_;
    //   x_=radius_;
    // }
    // if (y_>winy-radius_) {
    //   sy_=-sy_;
    //   y_=winy-radius_;
    // }
    // else if (y_<=radius_)    {
    //   sy_=-sy_;
    //   y_=radius_;
    // }
    // std::cout << "x=" << x_ << ",y=" << y_ << ",radius=" << radius_<< '\n';
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
