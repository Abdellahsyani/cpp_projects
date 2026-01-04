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
 *    - ROLE:
 *          we use exception here to check if RobotomyRequestForm enter's some high or low Grade
 *          and throw an error.
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
 * ~Form:: The destructor responsible for cleaning the memory
 **/
RobotomyRequestForm::~RobotomyRequestForm() {};
