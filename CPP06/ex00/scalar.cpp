#include "scalar.hpp"



/***/
void ScalarConverter::convert(std::string type) {
  char* end;
  double value = std::strtod(type.c_str(), &end);

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
    if (isnan(value) || isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
      throw std::string("impossible");
    int num = static_cast<int>(value);
    std::cout << "int: "<< num << std::endl;
  }
  catch (std::string &e) {
    std::cout << "int: " << e << std::endl;
  }

  try {
    if (isnan(value) || isinf(value) || value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::min()) 
      throw std::string("impossible");
    float num = static_cast<float>(value);
    std::cout << "float: "<< std::fixed << std::setprecision(1) << num << "f" << std::endl;
  }
  catch (std::string &e) {
    std::cout << "float: " << e << std::endl;
  }

  try {
    if (isnan(value) || isinf(value) || value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::min()) 
      throw std::string("impossible");
    std::cout << "double: "<< value << std::endl;
  }
  catch (std::string &e) {
    std::cout << "double: " << e << std::endl;
  }
}
