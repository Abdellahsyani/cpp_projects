#include "Bureaucrat.hpp"

/**
 * Bureaucrat: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
Bureaucrat::Bureaucrat() : _name("Bureau"), _grade(0) {};

/**
 * Bureaucrat: This is a parametrize constructor to init the attributes
 *        without need for setters
 *    - ROLE:
 *          we use exception here to check if Bureaucrat enter's some high or low Grade
 *          and throw an error.
 **/
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
    if (grade > 150)
      throw Bureaucrat::GradeLowException();
    if (grade < 1)
      throw Bureaucrat::GradeHighException(); 
};

/**
 * Bureaucrat: a copy constructor to create an instance from another
 **/
Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
  this->_grade = other._grade; 
}

/**
 * Bureaucrat: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other)
    this->_grade = other._grade;
  return (*this);
}

/**
 * getGrade: a getter function to get the grade attribute
 */
int Bureaucrat::getGrade() const
{
  return _grade;
}

/**
 * getName: A getter memeber function to get the name 
 */
std::string const Bureaucrat::getName() const 
{
  return _name;
}

/**
 * increment: This is a memeber function to increment the grade
 **/
void Bureaucrat::increment()
{
  this->_grade--;
  if (this->_grade < 1)
    throw Bureaucrat::GradeHighException(); 
}

/**
 * decrement: This is a memeber function to decrement the grade
 **/
void Bureaucrat::decrement()
{
  this->_grade++;
  if (this->_grade > 150)
    throw Bureaucrat::GradeLowException(); 
}

/**
 * operator<<: Overloads the ostream operator to print Bureaucrat objects.
 * We use std::ostream because we are only OUTPUTTING data.
 */
std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return os;
}

/**
 * ~Bureaucrat:: The destructor responsible for cleaning the memory
 **/
Bureaucrat::~Bureaucrat() {};
