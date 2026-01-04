#include "PresidentialPardonForm.hpp"

/**
 * PresidentialPardonForm: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
PresidentialPardonForm::PresidentialPardonForm() :
  AForm("PresidentialPardonForm", false, 25, 5) {}

/**
 * PresidentialPardonForm: This is a parametrize constructor to init the attributes
 *        without need for setters
 *    - ROLE:
 *          we use exception here to check if PresidentialPardonForm enter's some high or low Grade
 *          and throw an error.
 **/
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
  AForm("PresidentialPardonForm", 25, 5) {}

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
 * ~Form:: The destructor responsible for cleaning the memory
 **/
PresidentialPardonForm::~PresidentialPardonForm() {};
