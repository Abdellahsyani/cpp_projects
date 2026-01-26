#include "BitcoinExchange.hpp"

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
    if (line.find("data") != std::string::npos) {};
  }
  while (std::getline(file, line))
  {
    if (validateCurrency(line) == false)
      continue;
  }

  return 0;
}
