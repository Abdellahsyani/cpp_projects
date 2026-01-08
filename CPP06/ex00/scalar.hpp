#pragma once


#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cctype>

/***/
class ScalarConverter {
  public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static void convert(std::string types);
};
