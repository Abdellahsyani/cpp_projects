#include "Bureaucrat.hpp"

/**
 * Bureaucrat: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(0) {};

/**
 * Bureaucrat: This is a parametrize constructor to init the attributes
 *        without need for setters
 **/
Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade) {};

/***/
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
  this->grade = other.grade; 
}
