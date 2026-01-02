#pragma once

#include <string>
#include "Bureaucrat.hpp"

/***/
class Form {
  private:
    std::string const _name;
    bool _flag;
    const int _signGrade;
    const int _execGrade;
  public:
    Form();
    Form(const Form& other);
    Form& perator=(const Form& other);
    ~Form();

  // Getters
  void getName();
  void getFlag();
  void getSignGrade();
  void getExecGrade();

  void beSigned(Bureaucrat& sign);

  class GradeTooHighException {};
  class GradeTooLowException {};

};

std::ostream& operator<<(std::ostream& os, Form& obj);
