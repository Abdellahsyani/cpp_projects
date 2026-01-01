#include "Bureaucrat.hpp"
#include <exception>

int main()
{
  try {
    Bureaucrat bero("abdo", 149);
    std::cout << bero << std::endl;
    bero.decrement();
    bero.decrement();
    std::cout << bero << std::endl;
  }
  catch (std::exception& error)
  {
    std::cout << error.what() << std::endl;
  }

  try {
    Bureaucrat bero1("syani", 1);
    std::cout << bero1 << std::endl;
    bero1.increment();
    std::cout << bero1 << std::endl;
  }
  catch (std::exception& error)
  {
    std::cout << error.what();
  }

  return 0;
}
