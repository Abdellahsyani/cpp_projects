#pragma once

#include <iostream>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
  private:
    std::string _target;
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm & other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};
