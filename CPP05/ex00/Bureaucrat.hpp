#pragma once


#include <exception>
#include <ios>
#include <iostream>
#include <istream>


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

    std::string const getNmae() const;
    int getGrade() const;
    void increment();
    void decrement();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);
