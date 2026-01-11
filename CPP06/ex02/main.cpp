#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

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
