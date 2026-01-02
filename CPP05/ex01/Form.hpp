#pragma once

#include <string>

class Bureaucrat;

/***/
class Form {
  private:
    std::string const _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;
  public:
    Form();
    Form(const Form& other);
    Form& perator=(const Form& other);
    ~Form();

  // Getters
  std::string const getName();
  bool getFlag();
  const int getSignGrade();
  const int getExecGrade();

  void beSigned(const Bureaucrat& sign);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "Grade is To High!";
    } 
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "Grade is To Low!";
    }
  };
};

std::ostream& operator<<(std::ostream& os, Form& obj);
