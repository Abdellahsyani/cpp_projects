#pragma once


#include <iostream>

/***/
class ScalarConverter {
  public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static void convert(std::string types);
};
