#include "BitcoinExchange.hpp"

void checkYear(int year) {
  if (year < 1 || year > 2026) {
    throw std::string("Invalid year");
  }
};

void checkMonth(int month) {
  if (month < 1 || month > 12) {
    throw std::string("Invalid month");
  }
};

void checkDay(int day) {
  if (day < 1 || day > 31) {
    throw std::string("Invalid day");
  }
};

void checkValue(double value) {
  if (value > 1000) {
    throw std::string("too large a number");
  }
  if (value < 0)
    throw std::string("not a positive number");
};

bool validateCurrency(std::string& line) {
  int year = 0;
  int month = 0;
  int day = 0;
  char Hyphen1 = 0;
  char Hyphen2 = 0;
  char pipe = 0;
  double value = 0.0;
  std::stringstream ss(line);

  if (line.empty())
    return false;
  if (!(ss >> year >> Hyphen1 >> month >> Hyphen2 >> day >> pipe >> value)) {
    std::cout << "Error: bad input => " << line << std::endl;
    return false;
  }
  char extra;
  if (ss >> extra) {
    std::cout << "Error: bad input => " << extra << std::endl;
    return false;
  }
  try {
    checkYear(year);
    if (Hyphen1 != '-' || Hyphen2 != '-') {
      throw std::string("Invalid hyphen");
    }
    checkMonth(month);
    checkDay(day);
    if (pipe != '|') {
      throw std::string("Invalid format");
    }
    checkValue(value);
    std::cout << year << Hyphen1 << month << Hyphen2 << day << " => " << value << std::endl;
  } catch (std::string& e) {
      std::cout << "Error: " << e << std::endl;
  }
  return true;
}
