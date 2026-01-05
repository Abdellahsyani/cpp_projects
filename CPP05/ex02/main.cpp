#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <cstdlib>
#include <ctime>

int main()
{
  std::srand(std::time(NULL));

  std::cout << "===================== RobotomyRequestForm ========================" << std::endl;

  try {
    Bureaucrat b("abdo", 40);
    RobotomyRequestForm robo("robot");

    b.signForm(robo);
    robo.execute(b);
  }
  catch (std::exception& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
  
  std::cout << "====================== PresidentialPardonForm =======================" << std::endl;

  try {
    Bureaucrat b("bob", 10);
    PresidentialPardonForm pres("president");

    b.signForm(pres);
    b.executeForm(pres);
    pres.execute(b);
  }
  catch (std::exception& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::cout << "====================== ShrubberyCreationForm =======================" << std::endl;

  try {
    Bureaucrat b("bob", 40);
    ShrubberyCreationForm shrubby("Shrubby");

    b.signForm(shrubby);
    shrubby.execute(b);
  }
  catch (std::exception& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
