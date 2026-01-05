#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <cstdlib>

int main()
{
  srand(time(NULL));

  try {
    Bureaucrat b("abdo", 10);
    PresidentialPardonForm pres("bob");
    RobotomyRequestForm robo("robo");
    ShrubberyCreationForm shru("shru");
  }
  catch (std::exception& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
