#include "scalar.hpp"

/**
 * ScalarConverter: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
ScalarConverter::ScalarConverter() {}

/**
 * ScalarConverter: a copy constructor to create an instance from another
 **/
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

/**
 * ScalarConverter: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return (*this);
}

void ScalarConverter::convert(std::string type) {
  double value = std::strtod(type.c_str(), NULL);

  try {
    if (isnan(value) || isinf(value))
      throw std::string("impossible");
    if (value < 0 || value > 127)
        throw std::string("impossible");
    char c = static_cast<char>(value);
    if (!std::isprint(c)) 
      throw std::string("Non displayable");
    std::cout << "char: "<< "'" << c << "'" << std::endl;
  }
  catch (std::string& e) {
    std::cout << "char: "<< e << std::endl;
  }

  try {
    if (isnan(value) || isinf(value) || value > INT_MAX || value < INT_MIN)
      throw std::string("impossible");
    int num = static_cast<int>(value);
    std::cout << "int: "<< num << std::endl;
  }
  catch (std::string &e) {
    std::cout << "int: " << e << std::endl;
  }

  try {
    if (isnan(value) || isinf(value) || value > INT_MAX || value < INT_MIN) 
      throw std::string("impossible");
    int num = static_cast<int>(value);
    std::cout << "float: "<< num << std::endl;
  }
  catch (std::string &e) {
    std::cout << "float: " << e << std::endl;
  }
}

/**
 * ~ScalarConverter:: The destructor responsible for cleaning the memory
 **/
ScalarConverter::~ScalarConverter() {}
