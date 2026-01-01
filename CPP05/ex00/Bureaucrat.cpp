#include "Bureaucrat.hpp"
#include <ios>
#include <istream>

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
  try {
    if (grade > 150)
      throw "Grade is to low";
    if (grade < 1)
      throw "Grade is to high";
  }
  catch (const char* str) {
    std::cout << "Error: " << str;
  }
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
int Bureaucrat::getGrade()
{
  return _grade;
}

/**
 * getNmae: A getter memeber function to get the name 
 */
std::string const Bureaucrat::getNmae()
{
  return _name;
}

/**
 * increment: This is a memeber function to increment the grade
 **/
void Bureaucrat::increment()
{
  this->_grade--;
  try {
    if (this->_grade < 1)
      throw "The grade cannot be high than 1";
  }
  catch (const char* str)
  {
    std::cout << "Error: " << str;
  }
}

/**
 * decrement: This is a memeber function to decrement the grade
 **/
void Bureaucrat::decrement()
{
  this->_grade++;
  try {
    if (this->_grade > 150)
      throw "This grade cannot be low than 150";
  }
  catch (const char* str)
  {
    std::cout << "Error: " << str;
  }
}

/***/
std::iostream& operator<<(std::iostream& os, Bureaucrat& obj)
{
  os << obj.getNmae();
  os << obj.getGrade();
  return os;
}

/**
 * ~Bureaucrat:: The destructor responsible for cleaning the memory
 **/
Bureaucrat::~Bureaucrat() {};
