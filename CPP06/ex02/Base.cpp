#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>


/**
 * Base: Default constructor
 **/
Base::~Base() {};

/**
 * generate: A global function that generate objects randomly
 *  @Objects:
 *        A(): Empty class
 *        B(): Empty class
 *        C(): Empty class
 *    - These classes just to test that the DownCast is working by using dynamic_cast
 **/
Base * generate(void) {
  int random = (rand() % 3);

  if (random == 0)
    return new A();
  if (random == 1)
    return new B();
  return new C();
}

/**
 * identify: The function that check the type of the object that generate() function return,
 *            This function check the objects by using pointers.
 *
 * @param p: An Object that the generate() function create
 *            - cast the object and check if cast is NULL Error.
 *            - other wise print the name of object.
 **/
void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "'A'" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "'B'" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "'C'" << std::endl;
  else {
    std::cout << "None" << std::endl;
  }
}

/**
 * identify: A function that check the type of objects that generate() function create,
 *            This function check by using reference. and try catch
 *
 * @param p: An Object that the generate() function create
 *            - cast the object and check if cast is throw and error.
 *            - other wise print the name of object.
 *            */
void identify(Base& p) {
  try { 
    (void)dynamic_cast<A&>(p);
    std::cout << "'A'" << std::endl;
  } catch (...) {
  }

  try { 
    (void)dynamic_cast<B&>(p);
    std::cout << "'B'" << std::endl;
  } catch (...) {
  }

  try { 
    (void)dynamic_cast<C&>(p);
      std::cout << "'C'" << std::endl;
  } catch (...) {
  }
}
