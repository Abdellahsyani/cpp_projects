#include "BitcoinExchange.hpp"
#include <sstream>

int main(int ac, char *av[]) {

  if (ac != 2) {
    std::cerr << "Error: enter one argument" << std::endl;
    return 1;
  }
  std::string input = av[1];
  std::ifstream file;
  file.open(input.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: Could not open the file!" << std::endl;
    return 1;
  }

  std::string line;
  if (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string data;
    ss >> data;
    std::string pipe; 
    ss >> pipe;
    std::string value;
    ss >> value;
    if (data != "date" || pipe != "|" || value != "value") {
      std::cerr << "Missing header!" << std::endl;
      return 1;
    }
  }
  while (std::getline(file, line))
  {
    if (validateCurrency(line) == false)
      continue;
  }

  return 0;
}
