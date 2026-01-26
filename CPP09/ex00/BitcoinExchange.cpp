#include "BitcoinExchange.hpp"

void validateCurrency(std::string& line) {
  std::cout << "=> : " << line << std::endl;
  int year;
  int month;
  int day;
  char Hyphen1;
  char Hyphen2;
  char pipe;
  int value;

  try {
    std::stringstream ss(line);
    if (ss >> year, ss >> Hyphen1, ss >> month, ss >> Hyphen2, ss >> pipe, ss >> value) {
      if (year < 1 || year > 2026) {
        throw std::string "Invalid year";
      } else if (Hyphen1 != '-') {
        throw std::string "Invalid hyphen";
      } else if (month < 1 || month > 12) {
        throw std::string "Invalid month";
      } else if (Hyphen2 != '-') {
        throw std::string "Invalid hyphen";
      } else if (day < 1 || day > 31) {
        throw std::string "Invalid day";
      } else if (pipe != '|') {
        throw std::string "Invalid format";
      } else if (value < 1 || value > 1000) {
        throw std::string "too large number";
      } else if (year < 0 || month < 0 || day < 0 || value < 0) {
        throw std::string "not a positive number";
      }
    }
  }
}


