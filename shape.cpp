#include "shape.hpp"
#include "window.hpp"
#include <iostream>

namespace s5loo {
  Shape::Shape(double x, double y, double sx, double sy, Color color):
    x_{x},
    y_{y},
    sx_{sx},
    sy_{sy},
    color_{color}
    {}

  void
  Shape::move(const Window &win, double dt)
  {
    double r=boundingSphere();
    x_+=dt*sx_;
    y_+=dt*sy_;

    auto [winx,winy]=win.size();
    if (x_>winx-r) {
      sx_=-sx_;
      x_=winx-r;
    }
    else if (x_<=r)    {
      sx_=-sx_;
      x_=r;
    }
    if (y_>winy-r) {
      sy_=-sy_;
      y_=winy-r;
    }
    else if (y_<=r)    {
      sy_=-sy_;
      y_=r;
    }
    // std::cout << "x=" << x_ << ",y=" << y_ << ",radius=" << radius_<< '\n';
  }
  
  double Shape::boundingSphere() {
    return 1.1;
  }
  void Shape::click(sf::RenderWindow& win, int x, int y){
    const double r=boundingSphere();
    const double dx=x-x_, dy=y-y_;
    if(dx*dx+dy*dy<=r*r) {
      std::cout << "click on a shape" << '\n';
      sx_=-sx_;
      sy_=-sy_;
      do_click(win,x,y);
    }
  }
  void Shape::do_click(sf::RenderWindow& win,int x, int y){}
}
