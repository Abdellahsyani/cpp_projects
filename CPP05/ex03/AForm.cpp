#include "AForm.hpp" 
#include "Bureaucrat.hpp"

/**
 * AForm: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
AForm::AForm() : _name("AForm"), _isSigned(false), _signGrade(0), _execGrade(0) {};

/**
 * AForm: This is a parametrize constructor to init the attributes
 *        without need for setters
 *    - ROLE:
 *          we use exception here to check if AForm enter's some high or low Grade
 *          and throw an error.
 **/
AForm::AForm(std::string const name, const int signGrade, const int execGrade) :
  _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
      throw AForm::GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
      throw AForm::GradeTooLowException(); 
};

/**
 * AForm: a copy constructor to create an instance from another
 **/
AForm::AForm(const AForm& other) :
  _name(other._name),
  _isSigned(other._isSigned),
  _signGrade(other._signGrade),
  _execGrade(other._execGrade)
{
  this->_isSigned = other._isSigned; 
}

/**
 * AForm: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
AForm& AForm::operator=(const AForm& other) {
  if (this != &other)
    this->_isSigned = other._isSigned;
  return (*this);
}

/**
 * getFlag: A setter function for bool _isSigned
 **/
bool AForm::getFlag() const
{
  return _isSigned;
}

/**
 * getSignGrade: A getter method for _signGrade
 **/
int AForm::getSignGrade() const
{
  return _signGrade;
}

/**
 * getExecGrade: A getter method for _execGrade
 **/ 
int AForm::getExecGrade() const 
{
  return _execGrade;
}

/**
 * getNmae: A getter memeber function to get the name 
 */
std::string const AForm::getName() const 
{
  return _name;
}

/**
 * beSigned: This beSigned  function check if the Grade in AForm
 *          is accepted from the Bureaucrat
 *          - if yes _isSigned = true
 *          - if no throw an exception
 **/
void AForm::beSigned(const Bureaucrat& sign)
{
  if (sign.getGrade() > this->getSignGrade())
    throw AForm::GradeTooLowException();
  if (this->_isSigned == true)
  {
    std::cout << "AForm is already signed!" << std::endl;
    return;
  }
  this->_isSigned = true;
}

/**
 * operator<<: Overloads the ostream operator to print AForm objects.
 * We use std::ostream because we are only OUTPUTTING data.
 */
std::ostream& operator<<(std::ostream& os, AForm& obj)
{
    os << "AForm: " << obj.getName() 
       << " | Signed: " << (obj.getFlag() ? "Yes" : "No")
       << " | Grade to Sign: " << obj.getSignGrade()
       << " | Grade to Execute: " << obj.getExecGrade();
    return os;
}

/**
 * checkRequirements: A function to check the requirements for AForm to hire some form
 *      - ROLE:
 *          check an validate all requirements if any is not valid throw an error
 **/
void AForm::checkRequirements(Bureaucrat const & executor) const {
  if (this->getFlag() == false)
    throw AForm::AFormNotSignedException();
  if (executor.getGrade() > this->getExecGrade())
    throw AForm::GradeTooLowException();
}

/**
 * ~AForm:: The destructor responsible for cleaning the memory
 **/
AForm::~AForm() {};
