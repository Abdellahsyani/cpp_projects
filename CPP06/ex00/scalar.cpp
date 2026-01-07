#include "scalar.hpp"

/**
 * ScalarConverter: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
ScalarConverter::ScalarConverter() {}

/**
 * ScalarConverter: a copy constructor to create an instance from another
 **/
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

/**
 * ScalarConverter: A copy assignement operator
 *   - USAGE:
 *        This override an existing instance with another one
 **/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  return (*this);
}

/**
 * ~ScalarConverter:: The destructor responsible for cleaning the memory
 **/
ScalarConverter::~ScalarConverter() {}
