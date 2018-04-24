#include "window.hpp"
#include "circle.hpp"
#include <random>

int main(void) {
  s5loo::Window win{"Rectangles and Circles", 1000,1000};
  auto [width, height] = win.size();

  std::default_random_engine rndGen{std::random_device{}()};
  std::uniform_int_distribution<short> colorDistr{0, 255};
  std::uniform_real_distribution<double> speedDistr{-50, 50};
  std::uniform_real_distribution<double> dimDistr{10, 60};
  std::uniform_real_distribution<double> xposDistr{0, width};
  std::uniform_real_distribution<double> yposDistr{0, height};
  std::uniform_real_distribution<double> angularDistr{-15, 15};

  auto makeCircle=[&]()
  {
    return s5loo::Circle{xposDistr(rndGen),yposDistr(rndGen),
                        speedDistr(rndGen),speedDistr(rndGen),
                        dimDistr(rndGen),
                        s5loo::Color{
                          s5loo::uchar(colorDistr(rndGen)),
                          s5loo::uchar(colorDistr(rndGen)),
                          s5loo::uchar(colorDistr(rndGen))
                        }};
  };
  auto c1=makeCircle();
  auto c2=makeCircle();
  auto c3=makeCircle();

  win.addCircle(c1);
  win.addCircle(c2);
  win.addCircle(c3);
  win.display();
  return 0;
}
