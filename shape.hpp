#ifndef SHAPE_HPP
#define SHAPE_HPP 1
#include <vector>
#include <tuple>
#include "color.hpp"
// #include "window.hpp"
// #include "SFML/Graphics.hpp"
namespace s5loo {
  class Window;
  class Shape {
    private:
      double x_;
      double y_;
      double sx_;
      double sy_;
      Color color_;

    public:
      Shape(double x, double y, double sx, double sy, Color color);

      std::tuple<double,double> position() const{
        return {x_,y_};
      }
      std::tuple<double,double> speed() const{
        return {sx_,sy_};
      }
      Color color() const{
        return color_;
      }
      void move(const Window &win, double dt);
    };

}
#endif