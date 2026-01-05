#include "Intern.hpp"

/**
 * Intern: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
Intern::Intern() {};

/**
 * Intern: a copy constructor to create an instance from another
 **/
Intern::Intern(const Intern& other) {}

/**
 * Intern: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
Intern& Intern::operator=(const Intern& other) {
  return (*this);
}

/***/
AForm* Intern::makeForm(std::string form, std::string target)
{
  std::string vectorOfForms[] = {}
}

/**
 * ~Intern:: The destructor responsible for cleaning the memory
 **/
Intern::~Intern() {};
