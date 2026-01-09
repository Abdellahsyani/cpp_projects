#pragma once


#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <iomanip>

/**
 * ScalarConverter: A non instiation class that define a static method convert
 */
class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(std::string types);
};
