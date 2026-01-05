#pragma once

#include <iostream>

class AForm;
class Bureaucrat;

/**
 * ShrubberyCreationForm: A concret class that apply abstraction AForm roles to hire a ShrubberyCreationForm
 *    - ROLE:
 *        This class Implement execute method to let Bureaucrat chose the right AForm
 *        to hire in the work.
 * */
class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm & other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;
};
