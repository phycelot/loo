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

void Window::display() {

  while (win_.isOpen())
  {
    win_.clear(sf::Color(100, 100, 100));
    this->moveAll(0.5);
    this->drawAll();
    win_.display();

    sf::Event event;
    if(win_.pollEvent(event))
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
