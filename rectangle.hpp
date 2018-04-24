#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP 1
#include <vector>
#include <tuple>
#include "color.hpp"
// #include "window.hpp"
#include "SFML/Graphics.hpp"
namespace s5loo {
  class Window;
  class Rectangle {
    private:
      double x_;
      double y_;
      double sx_;
      double sy_;
      double height_;
      double width_;
      double angularSpeed_;
      Color color_;
      double angle_;

    public:
      Rectangle(double x, double y, double sx, double sy, double height, double width, double angularSpeed, Color color);

      std::tuple<double,double> position() const{
        return {x_,y_};
      }
      std::tuple<double,double> speed() const{
        return {sx_,sy_};
      }
      std::tuple<double,double> size() const{
        return {width_,height_};
      }
      double angularSpeed() const{
        return angularSpeed_;
      }
      Color color() const{
        return color_;
      }
      void move(const Window &win, double dt);
      void angle(double a);
      double angle() const{
        return angle_;
      }
    };
  void draw(const Rectangle &c, sf::RenderWindow &rw);

}
#endif
