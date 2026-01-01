#pragma once

#include <string>

class Form {
  private:
    std::string const _name;
    bool _flag;
    const int _signGrade;
    const int _execGrade;
  public:
    Form();
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
};
