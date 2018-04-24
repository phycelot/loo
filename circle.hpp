#ifndef CIRCLE_HPP
#define CIRCLE_HPP 1
#include <vector>
#include <tuple>
#include "color.hpp"
// #include "window.hpp"
#include "SFML/Graphics.hpp"
namespace s5loo {
  class Window;
  class Circle {
    private:
      double x_;
      double y_;
      double sx_;
      double sy_;
      double radius_;
      Color color_;

    public:
      Circle(double x, double y, double sx, double sy, double radius, Color color);

      // Circle(const Circle &) = default;
      // Circle & operator=(const Circle &) = default;
      //
      // Circle(const Circle &&) = default;
      // Circle & operator=(const Circle &&) = default;
      //
      // ~Circle() = default;

      std::tuple<double,double> position() const{
        return {x_,y_};
      }
      std::tuple<double,double> speed() const{
        return {sx_,sy_};
      }
      double radius() const{
        return radius_;
      }
      Color color() const{
        return color_;
      }
      void move(const Window &win, double dt);
    };
  void draw(const Circle &c, sf::RenderWindow &rw);

}
#endif
