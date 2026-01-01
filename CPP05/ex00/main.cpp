#include "Bureaucrat.hpp"

int main()
{
  Bureaucrat bero("abdo", 2);
  Bureaucrat bero1("allo", 15);

  bero.increment();
  std::cout << bero.getNmae() << " bureaucrat grade " << bero.getGrade() << std::endl;

  return 0;
}
