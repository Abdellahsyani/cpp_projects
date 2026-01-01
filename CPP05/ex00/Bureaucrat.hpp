#pragma once


#include <exception>
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

    // nested class to throw error
    class GradeHighException : public std::exception {
      virtual const char* what() const throw() {
        return "Grade is to high";
      } 
    };

    // nested class to throw error
    class GradeLowException : public std::exception {
      virtual const char* what() {
        return "Grade is to low";
      }
    };

    std::string const getNmae();
    int getGrade();
    void increment(int grade);
    void decrement(int grade);
};
