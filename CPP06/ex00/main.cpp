#include "scalar.hpp"

int main(int ac, char *av[])
{
  if (ac != 2)
  {
    if (!av[1])
    {
      std::cout << "Enter one argument" << std::endl;
      return 1;
    }
    std::cout << "Just one argument please" << std::endl;
    return 1;
  }
  ScalarConverter::convert(av[1]);

  return 0;
}
