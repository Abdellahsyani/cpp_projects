#include "ShrubberyCreationForm.hpp"

/**
 * ShrubberyCreationForm: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
ShrubberyCreationForm::ShrubberyCreationForm() :
  AForm("ShrubberyCreationForm", false, 145, 137) {}

/**
 * ShrubberyCreationForm: This is a parametrize constructor to init the attributes
 *        without need for setters
 *    - ROLE:
 *          we use exception here to check if ShrubberyCreationForm enter's some high or low Grade
 *          and throw an error.
 **/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
  AForm("ShrubberyCreationForm", 145, 137) {}

/**
 * ShrubberyCreationForm: a copy constructor to create an instance from another
 **/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
  AForm(other), _target(other._target) {}

/**
 * ShrubberyCreationForm: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
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
ShrubberyCreationForm::~ShrubberyCreationForm() {};
