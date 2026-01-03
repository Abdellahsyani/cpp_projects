#pragma once

class AForm;

class PresidentialPardonForm : public AForm {
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm & other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
};
