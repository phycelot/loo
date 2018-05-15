#include <iostream>
#include <chrono>
#include "window.hpp"

namespace s5loo {

/* global functions définition */

double getTime() {
  const auto now{std::chrono::system_clock::now().time_since_epoch()};
  return 1e-3*double(std::chrono::duration_cast
                   <std::chrono::milliseconds>(now).count());
}

/* member functions définition */

Window::Window(std::string n, double w, double h) : name_{n}, width_{w}, height_{h},
                                         win_{sf::VideoMode{(unsigned int)width_, (unsigned int)height_}, name_.data()}
{ }

void Window::addShape(std::unique_ptr<Shape> shape)
{
  shapes_.emplace_back(std::move(shape));
}
void Window::moveAll_(double dt){
  for (auto &elem: shapes_) {
    elem->move(*this,dt);
  }
}
void Window::drawAll_(){
  for (auto &elem: shapes_) {
    // elem->draw(*this);
    elem->draw(win_);
  }
}

void Window::display() {
  double t=getTime();
  while (win_.isOpen())
  {
    win_.clear(sf::Color(100, 100, 100));
    double dt = getTime()-t;
    const double step=1.0/30.0;
     // target 30 FPS
    if(dt<step) {
      sf::sleep(sf::seconds(float(step-dt)));
    }
    t+=dt;
    this->moveAll_(dt);
    this->drawAll_();
    win_.display();

    sf::Event event;
    while(win_.pollEvent(event))
    {
      switch (event.type)
      {
        case sf::Event::Closed :
             win_.close();
             break;
        case sf::Event::MouseButtonPressed:
             if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
               std::cout<< "left_button on (" << event.mouseButton.x << "," << event.mouseButton.y << ")\n";
             }
             break;
        case sf::Event::KeyPressed:
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                std::cout<< "LEFT\n";
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                std::cout<< "RIGHT\n";
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                std::cout<< "UP\n";
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                std::cout<< "DOWN\n";
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                std::cout<< "A\n";
	     }
             break;
        default:
          break;
      }
    }
  }
}

}  // namespace s5loo
