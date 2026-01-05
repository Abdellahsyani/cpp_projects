#include "PresidentialPardonForm.hpp"

/**
 * PresidentialPardonForm: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
PresidentialPardonForm::PresidentialPardonForm() :
  AForm("PresidentialPardonForm", 25, 5), _target("Pres") {}

/**
 * PresidentialPardonForm: This is a parametrize constructor to init the attributes
 *        without need for setters
 *    - ROLE:
 *          we use exception here to check if PresidentialPardonForm enter's some high or low Grade
 *          and throw an error.
 **/
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
  AForm("PresidentialPardonForm", 25, 5), _target(target) {}

/**
 * PresidentialPardonForm: a copy constructor to create an instance from another
 **/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
  AForm(other), _target(other._target) {}

/**
 * PresidentialPardonForm: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  if (this != &other)
  {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return (*this);
}

/**
 * PresidentialPardonForm: A method that execute a form if all requirements are valid
 *    - ROLE:
 *        In this method we make some noises by printing a message to stdout
 *        pick a random number by using rand() to make this form success 50% and fail 50%
 *    - MEAN:
 *        This acts as a form that Bureaucrat wants to execute this form should
 *        pass all requirements like an interview then you will be hired
 *        if doesn't pass throw an error that tell us the reason that make this form failed
 **/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
  this->checkRequirements(executor);
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/**
 * ~Form:: The destructor responsible for cleaning the memory
 **/
PresidentialPardonForm::~PresidentialPardonForm() {};
