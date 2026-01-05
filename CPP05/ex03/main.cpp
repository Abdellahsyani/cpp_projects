#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <cstdlib>
#include <ctime>

void test_intern(std::string name, std::string target)
{
  std::cout << "\n============ Testing ============" << std::endl;
  Intern intern;
  Bureaucrat b("Bob", 5);
  AForm* form;

  form = NULL;

  try {
    form = intern.makeForm(name, target);

    if (form != NULL) {
      b.signForm(*form);
      b.executeForm(*form);
      delete(form);
    }
  }
  catch (std::exception& e) {
      delete(form);
      std::cout << "Error: " << e.what() << std::endl;
  } 
}

int main()
{
  std::srand(std::time(NULL));

  std::string forms[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation",
        "invalid form name" 
    };

  for (int i = 0; i < 4; i++) {
    test_intern(forms[i], "Abdo");
  }

  return 0;
}
