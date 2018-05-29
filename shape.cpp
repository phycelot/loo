#include "shape.hpp"
#include "window.hpp"
#include <iostream>
#include <stdlib.h>

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

    //vitesse
    x_+=dt*sx_;
    y_+=dt*sy_;


    //collison limite window
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
      this->invertSpeed();
      this->do_click(win,x,y);
    }
  }

  bool Shape::collide(std::unique_ptr<Shape> &s)
  {
    const double r1=boundingSphere();
    const double r2=s->boundingSphere();
    const auto [x1,y1]=position();
    const auto [x2,y2]=s->position();

    // double ssx2=sx2/abs(sx2);
    // double ssy2=sy2/abs(sy2);
    // double ssx1=sx1/abs(sx1);
    // double ssy1=sy1/abs(sy1);
    // double s_x1=x1/abs(x1);
    // double s_y1=y1/abs(y1);



    const double distance = sqrt(((x1 - x2) * (x1 - x2))+ ((y1 - y2) * (y1 - y2)));

    if (distance < r1 + r2)
    {
      std::cout << "collide detected" << '\n';
      const auto [sx1,sy1]=speed();
      const double a1=area();
      const double a2=s->area();
      std::cout << "before sx :" << sx1 << " & sy : " << sy1<< '\n';
      // const auto [sx2,sy2]=s->speed();
      double v1px = (x1 * (a1 - a2) + (2 * a2 * x2)) / (a1 + a2);
      double v1py = (y1 * (a1 - a2) + (2 * a2 * y2)) / (a1 + a2);

      setSpeed(v1px,v1py);
      setPosition(x1+v1px,y1+v1py);

      return 1;
    }

    return 0;
  }


  // void Shape::do_click(sf::RenderWindow& win,int x, int y){}
}
