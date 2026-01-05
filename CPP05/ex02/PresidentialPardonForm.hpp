#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

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
