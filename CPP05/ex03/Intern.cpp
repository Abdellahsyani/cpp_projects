#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

/**
 * Intern: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
Intern::Intern() {};

/**
 * Intern: a copy constructor to create an instance from another
 **/
Intern::Intern(const Intern& other) { (void)other; }

/**
 * Intern: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return (*this);
}

/**
 * makeForm: Acts as a Factory to instantiate specific AForm objects.
 *  * ROLE:
 *      - Validates the requested form name against a predefined list.
 *      - Dynamically allocates the requested form (Shrubbery, Robotomy, or Pardon).
 *      - Returns an AForm* to the caller, who becomes responsible for its deletion.
 *  * DESIGN:
 *      - Uses a loop and index-based switch to avoid long if-else chains.
 *      - Enhances scalability: new forms can be added by updating the 'names' array.
 */
AForm* Intern::makeForm(std::string form, std::string target)
{
  std::string names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
  AForm* result = NULL;

  for (int i = 0; i < 3; i++)
  {
    if (form == names[i])
    {
       switch (i) {
        case 0:
          result = new PresidentialPardonForm(target);
          break;
        case 1:
          result = new RobotomyRequestForm(target);
          break;
        case 2:
          result = new ShrubberyCreationForm(target);
          break;
       }
      std::cout << "Intern creates " << form << std::endl;
      return result;
    }
  }
  throw AForm::AFormNotFoundException();
  return NULL;
}

/**
 * ~Intern:: The destructor responsible for cleaning the memory
 **/
Intern::~Intern() {};
