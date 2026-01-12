#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


/**
 * @main: Test the dynamic_cast to see if all work as expected
 *
 * @srand: to make the rand() function work and generate the different objects
 **/
int main() {
  std::srand(std::time(NULL));

  std::cout << "====== Testing =====" << std::endl;
  for (int i = 0; i < 5; i++)
  {
    Base* base;
    base = generate();
    identify(base);
    identify(*base);
    delete base;
    std::cout << "---------" << std::endl;
  }
}
