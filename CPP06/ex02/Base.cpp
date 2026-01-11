#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::~Base() {};

Base * generate(void) {
  int random = (rand() % 3);

  if (random == 0)
    return new A();
  if (random == 1)
    return new B();
  return new C();
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
  else {
    std::cout << "None" << std::endl;
  }
}

void identify(Base& p) {
  try { 
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch (...) {
  }

  try { 
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
  } catch (...) {
  }

  try { 
    (void)dynamic_cast<C&>(p);
      std::cout << "C" << std::endl;
  } catch (...) {
  }
}
