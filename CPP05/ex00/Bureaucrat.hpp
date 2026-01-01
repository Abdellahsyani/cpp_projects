#pragma once


#include <iostream>


class Bureaucrat {
  private:
    std::string const name;
    int grade;
  public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string const getNmae();
    int getGrade();
    void increment(int grade);
    void decrement(int grade);
};
