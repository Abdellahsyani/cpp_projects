#pragma once

#include <iostream>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm & other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
};
