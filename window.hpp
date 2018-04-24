#ifndef S5LOO_WINDOW_HPP
#define S5LOO_WINDOW_HPP 1

#include <vector>
#include <tuple>
#include "SFML/Graphics.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

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
      void addCircle(Circle &c){
        circles_.emplace_back(std::move(c));
      }
      void addRectangle(Rectangle &c){
        rectangles_.emplace_back(std::move(c));
      }
    private:
      void drawAll_(){
        for (const auto &elem: circles_) {
          draw(elem,win_);
        }
        for (const auto &elem: rectangles_) {
          draw(elem,win_);
        }
      }

      void moveAll_(double dt){
        for (auto &elem: circles_) {
          elem.move(*this,dt);
        }
        for (auto &elem: rectangles_) {
          elem.move(*this,dt);
        }
      }
      std::string name_;
      double width_, height_;
      sf::RenderWindow win_;
      std::vector<Circle> circles_;
      std::vector<Rectangle> rectangles_;
  };  // class Window

  /* inline member functions */

  inline
  std::tuple<double,double> Window::size() const { return {width_, height_}; }

  /* global functions déclaration */

  double // seconds since 1970/01/01 00:00:00 UTC (avec des décimales allant jusqu'aux microsecondes)
  getTime();


}  // namespace s5loo

#endif
