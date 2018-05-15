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
    x_+=dt*sx_;
    y_+=dt*sy_;

    auto [winx,winy]=win.size();
    if (x_>winx) {
      sx_=-sx_;
      x_=winx;
    }
    else if (x_<=0)    {
      sx_=-sx_;
      x_=0;
    }
    if (y_>winy) {
      sy_=-sy_;
      y_=winy;
    }
    else if (y_<=0)    {
      sy_=-sy_;
      y_=0;
    }
    // std::cout << "x=" << x_ << ",y=" << y_ << ",radius=" << radius_<< '\n';
  }
}
