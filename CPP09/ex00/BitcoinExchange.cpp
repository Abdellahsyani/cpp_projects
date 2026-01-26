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

void checkValue(int value) {
  if (value > 1000 || value == INT_MAX || value > INT_MAX) {
    throw std::string("too large a number");
  }
  if (value < 0)
    throw std::string("not a positive number");
};

void validateCurrency(std::string& line) {
  int year;
  int month;
  int day;
  char Hyphen1;
  char Hyphen2;
  char pipe;
  int value;
  std::stringstream ss(line);

  try {
    if (ss >> year, ss >> Hyphen1, ss >> month, ss >> Hyphen2, ss >> day, ss >> pipe, ss >> value) {
      checkYear(year);
      if (Hyphen1 != '-') {
        throw std::string("Invalid hyphen");
      }
      checkMonth(month);
      if (Hyphen2 != '-') {
        throw std::string("Invalid hyphen");
      }
      checkDay(day);
      if (pipe != '|') {
        throw std::string("Invalid format");
      }
      checkValue(value);
    }
    std::cout << year << Hyphen1 << month << Hyphen2 << day << " => " << value << std::endl;
  } catch (std::string& e) {
    std::cout << "Error: " << e << std::endl;
  }
}


