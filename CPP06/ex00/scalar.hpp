#pragma once


#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <iomanip>

/***/
class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(std::string types);
};
