#ifndef CIRCLE_HPP
#define CIRCLE_HPP 1
#include <vector>
#include <tuple>
#include "color.hpp"
#include "shape.hpp"
// #include "window.hpp"
#include "SFML/Graphics.hpp"
namespace s5loo {
  class Window; // declaration avance car reference croisee
  class Circle : public Shape
  {
    private:
      double radius_;

    public:
      Circle(double x, double y,
             double sx, double sy,
             double radius,
             Color color);

      double radius() const{
        return radius_;
      }
      void move(const Window &win, double dt) override;
      void draw(sf::RenderWindow &rw) const override;
      double boundingSphere() override;
    };


}
#endif
