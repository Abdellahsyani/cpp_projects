#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

/**
 * Form: A class for signing the forms job for Bureaucrat
 *    - ROLE:
 *        this class send a form to Bureaucrat and check if the form has
 *        all required skills then Bureaucrat sign the forms
 *        if no Bureaucrat throw an exception 
 **/
class AForm {
  protected:
    std::string const _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;
  public:
    AForm();
    AForm(const AForm& other);
    AForm(std::string const name, const int isSigned, const int execGrade);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

  // Getters
  std::string const getName() const;
  bool getFlag() const;
  int getSignGrade() const;
  int getExecGrade() const;
  virtual void execute(Bureaucrat const & executor) const = 0;
  void checkRequirements(Bureaucrat const & executor) const;

  void beSigned(const Bureaucrat& sign);

  // nested class
  class GradeTooHighException : public std::exception {
    public:
      virtual const char* what() const throw() {
        return "Grade is To High!";
    } 
  };

  // nested class
  class GradeTooLowException : public std::exception {
    public:
      virtual const char* what() const throw() {
        return "Grade is To Low!";
    }
  };

  // nested class
  class AFormNotSignedException : public std::exception {
    public:
      virtual const char* what() const throw() {
        return "AForm is not Signed!";
      }
  };

  // nested class
  class AFormNotFoundException : public std::exception {
    public:
      virtual const char* what() const throw() {
        return "Form not found!";
      }
  };
};

std::ostream& operator<<(std::ostream& os, AForm& obj);
