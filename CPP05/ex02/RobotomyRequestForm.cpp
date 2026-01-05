#include "RobotomyRequestForm.hpp"

/**
 * RobotomyRequestForm: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
RobotomyRequestForm::RobotomyRequestForm() :
  AForm("RobotomyRequestForm", false, 72, 45) {}

/**
 * RobotomyRequestForm: This is a parametrize constructor to init the attributes
 *        without need for setters
 **/
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
  AForm("RobotomyRequestForm", 72, 45) {}

/**
 * RobotomyRequestForm: a copy constructor to create an instance from another
 **/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
  AForm(other), _target(other._target) {}

/**
 * RobotomyRequestForm: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other)
  {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return (*this);
}

/**
 * RobotomyRequestForm: A method that execute a form if all requirements are valid
 *    - ROLE:
 *        In this method we make some noises by printing a message to stdout
 *        pick a random number by using rand() to make this form success 50% and fail 50%
 *    - MEAN:
 *        This acts as a form that Bureaucrat wants to execute this form should
 *        pass all requirements like an interview then you will be hired
 *        if doesn't pass throw an error that tell us the reason that make this form failed
 **/
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
  this->checkRequirements(executor);
  std::cout << "* DRILL NOISES *" << std::endl;
  int chance = rand() % 2;
  if (chance == 1) {
    std::cout << _target << " has been robotomized successfully 50% of the time!" << std::endl;
  }
  else {
    std::cout << "The robotomy failed" << std::endl;
  }
}

/**
 * ~Form:: The destructor responsible for cleaning the memory
 **/
RobotomyRequestForm::~RobotomyRequestForm() {};
