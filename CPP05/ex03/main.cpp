#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <cstdlib>
#include <ctime>

int main()
{
  std::srand(std::time(NULL));

  {
    std::cout << "===================== RobotomyRequestForm ========================" << std::endl;

    AForm* form = NULL;
    try {
      Intern Inter;

      form = Inter.makeForm("robotomy request", "Robot");
      Bureaucrat b("abdo", 40);

      b.signForm(*form);
      form->execute(b);
      delete(form);
    }
    catch (std::exception& e)
    {
      delete(form);
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  std::cout << "====================== PresidentialPardonForm =======================" << std::endl;

  {
    AForm* form = NULL;
    try {
      Intern intern;

      form = intern.makeForm("presidential pardon", "Bob");
      Bureaucrat b("bob", 40);

      b.signForm(*form);
      form->execute(b);
      delete(form);
    }
    catch (std::exception& e)
    {
      delete(form);
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  std::cout << "====================== ShrubberyCreationForm =======================" << std::endl;

  {
    AForm* form = NULL;
    try {
      Intern inter;

      form = inter.makeForm("shrubbery creation", "Jhon");
      Bureaucrat b("bob", 40);

      b.signForm(*form);
      form->execute(b);
      delete(form);
    }
    catch (std::exception& e)
    {
      delete(form);
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  return 0;
}
