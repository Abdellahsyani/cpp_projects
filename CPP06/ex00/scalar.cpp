#include "scalar.hpp"


/***/
void ScalarConverter::convert(std::string type) {
  char* end = NULL;
  double value;

  if (type.length() == 1 && !std::isdigit(type[0]))
    value = static_cast<double>(type[0]);
  else
    value = std::strtod(type.c_str(), &end);

  std::string remainder = (end != NULL) ? std::string(end) : "";
  bool isGarbage = false;
  if (end != NULL && *end != '\0' && remainder != "f") {
      if (type.length() != 1)
        isGarbage = true;
    }

  try {
    if (isGarbage || isnan(value) || isinf(value) || (value < 0 || value > 127))
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
    if (isGarbage || isnan(value) || isinf(value) || value > std::numeric_limits<int>::max() || value < -std::numeric_limits<int>::max())
      throw std::string("impossible");
    int num = static_cast<int>(value);
    std::cout << "int: "<< num << std::endl;
  }
  catch (std::string &e) {
    std::cout << "int: " << e << std::endl;
  }

  try {
    if (isGarbage || value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) 
      throw std::string("impossible");
    std::cout << "float: ";
    if (isnan(value))
      std::cout << "nanf" << std::endl;
    else if (isinf(value))
        std::cout << (value < 1 ? "-inff" : "+inff");
    else
      std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
  }
  catch (std::string &e) {
    std::cout << "float: " << e << std::endl;
  }

  try {
    if (isGarbage || value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::min()) 
      throw std::string("impossible");
    std::cout << "double: ";
    if (isnan(value))
      std::cout << "nan" << std::endl;
    else if (isinf(value))
        std::cout << (value < 0 ? "-inf" : "+inf");
    else 
      std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
        
  }
  catch (std::string &e) {
    std::cout << "double: " << e << std::endl;
  }
}
