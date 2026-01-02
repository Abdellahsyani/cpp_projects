#include "Form.hpp" 

/**
 * Form: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
Form::Form() : _name("Form"), _isSigned(false), _signGrade(0), _execGrade(0) {};

/**
 * Form: This is a parametrize constructor to init the attributes
 *        without need for setters
 *    - ROLE:
 *          we use exception here to check if Form enter's some high or low Grade
 *          and throw an error.
 **/
Form::Form(std::string const name, const int signGrade, const int execGrade) :
  _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
      throw Form::GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
      throw Form::GradeTooLowException(); 
};

/**
 * Form: a copy constructor to create an instance from another
 **/
Form::Form(const Form& other)
{
  this->_isSigned = other._isSigned; 
}

/**
 * Form: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
Form& Form::operator=(const Form& other) {
  if (this != &other)
    this->_isSigned = other._isSigned;
  return (*this);
}

/**
 * getFlag: A setter function for bool _isSigned
 **/
bool Form::getFlag()
{
  return this->_isSigned;
}

/**
 * getSignGrade: A getter method for _signGrade
 **/
const int Form::getSignGrade()
{
  return this->_signGrade;
}

/**
 * getExecGrade: A getter method for _execGrade
 **/
void getExecGrade()
{
  return this->_execGrade;
}

/**
 * getNmae: A getter memeber function to get the name 
 */
std::string const Form::getNmae() const 
{
  return this->_name;
}

/***/
void Form::beSigned(const Bureaucrat& sign)
{
  if (sign.getGrade() > this->getSignGrade())
    throw Form::GradeTooLowException();
  if (this->_isSigned == true)
  {
    std::cout << "Form is already signed!" << std::endl;
    return;
  }
  this->_isSigned = true;
}

/**
 * operator<<: Overloads the ostream operator to print Form objects.
 * We use std::ostream because we are only OUTPUTTING data.
 */
std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form: " << obj.getName() 
       << " | Signed: " << (obj.getFlag() ? "Yes" : "No")
       << " | Grade to Sign: " << obj.getSignGrade()
       << " | Grade to Execute: " << obj.getExecGrade();
    return os;
}

/**
 * ~Form:: The destructor responsible for cleaning the memory
 **/
Form::~Form() {};
