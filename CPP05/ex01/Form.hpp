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
class Form {
  private:
    std::string const _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;
  public:
    Form();
    Form(const Form& other);
    Form(std::string const name, const int isSigned, const int execGrade);
    Form& operator=(const Form& other);
    ~Form();

  // Getters
  std::string const getName() const;
  bool getFlag();
  int getSignGrade();
  int getExecGrade();

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
};

std::ostream& operator<<(std::ostream& os, Form& obj);
