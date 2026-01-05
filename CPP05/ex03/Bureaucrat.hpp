#pragma once


#include <exception>
#include <iostream>
#include "AForm.hpp"


/**
 * Bureaucrat: The class to apply exceptions
 *  - ROLE:
 *      Implement two nested calsses that inherit from exception class 
 *      to make sure that we catch the error in the right way by overriding what() member function in exception class
 *  - INSTRUCTION:
 *      A Bureaucrat is a class that grade all Bureaucrat's by increment or decrement the Bureaucrat
 *      between rank 1 to 150.
 *      if there is some rank above 150 or under 1 we will catch the error and throw it.
 *      - consider that the high rank is 1 and low rank is 150
 *        so if we want to increment we should sutract from grade
 * */
class Bureaucrat {
  private:
    std::string const _name;
    int _grade;
  public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // nested class to throw error
    class GradeHighException : public std::exception {
      public:
        virtual const char* what() const throw() {
          return "Grade is to high";
      } 
    };

    // nested class to throw error
    class GradeLowException : public std::exception {
      public:
        virtual const char* what() const throw() {
          return "Grade is to low";
      }
    };

    std::string const getName() const;
    int getGrade() const;
    void increment();
    void decrement();
    void signForm(AForm& form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);
