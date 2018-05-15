#ifndef S5LOO_WINDOW_HPP
#define S5LOO_WINDOW_HPP 1

#include <vector>
#include <tuple>
#include "SFML/Graphics.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

namespace s5loo {

  class Window {
    public:
      Window(std::string n="Window", double w=700, double h=500);

      /* Special functions -- copy constructor and copy assignement are deleted */
      Window(const Window&) = delete;
      Window(Window&&) = default;
      Window& operator=(const Window&) = delete;
      Window& operator=(Window&&) = default;
      virtual ~Window() = default;

      std::tuple<double,double> size() const;

      void display(void);

      void addShape(std::unique_ptr<Shape> shape);

    private:
      void drawAll_();

      void moveAll_(double dt);
      std::string name_;
      double width_, height_;
      sf::RenderWindow win_;
      std::vector<std::unique_ptr<Shape>> shapes_;
  };  // class Window

  /* inline member functions */

  inline
  std::tuple<double,double> Window::size() const { return {width_, height_}; }

  /* global functions déclaration */

  double // seconds since 1970/01/01 00:00:00 UTC (avec des décimales allant jusqu'aux microsecondes)
  getTime();


}  // namespace s5loo

#endif
