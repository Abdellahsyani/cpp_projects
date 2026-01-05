#pragma once

#include <iostream>

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm {
  private:
    std::string _target;
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm & other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};
