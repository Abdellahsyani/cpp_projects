#include "Base.hpp"

Base * generate(void) {
  int rand = (rand() % 3);

  if (rand == 1)
    return new A();
  if (rand == 2)
    return new B();
  if (rand == 3)
    return new C();
}

void identify(Base* p);

void identify(Base& p);
