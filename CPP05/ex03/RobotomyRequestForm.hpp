#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

/**
 * RobotomyRequestForm: A concret class that implement roles from abstraction class AForm
 *      ROLE:
 *        This is a class to define the RobotomyRequestForm form to let the Bureaucrat hire
 *        these forms to do some tasks
 **/
class RobotomyRequestForm : public AForm {
  private:
    std::string _target;
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm & other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};
