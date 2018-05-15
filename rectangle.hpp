#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP 1
#include <vector>
#include <tuple>
#include "color.hpp"
#include "shape.hpp"
// #include "window.hpp"
#include "SFML/Graphics.hpp"
namespace s5loo {
  class Window;
  class Shape;
  class Rectangle : public Shape {
    private:
      double height_;
      double width_;
      double angularSpeed_;
      double angle_;

    public:
      Rectangle(double x, double y, double sx, double sy, double height, double width, double angularSpeed, Color color);
      std::tuple<double,double> size() const{
        return {width_,height_};
      }
      double angularSpeed() const{
        return angularSpeed_;
      }
      void move(const Window &win, double dt) override;
      void angle(double a);
      double angle() const{
        return angle_;
      }
      void draw(sf::RenderWindow &rw) const override;

    };

}
#endif
