#include "BitcoinExchange.hpp"

void checkYear(int year) {
  if (year < 2008 || year > 2026) {
    throw std::string("Invalid year");
  }
};

void checkMonth(int month) {
  if (month < 1 || month > 12) {
    throw std::string("Invalid month");
  }
};

void checkDay(int day, int month) {
  if (day < 1 || day > 31) {
    throw std::string("Invalid day");
  }
  if (month == 2) {
    if (day < 1 || day > 29)
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

void fillMap(std::map<std::string, double> &Map) {
  std::ifstream readFile;
  std::string fileCsv = "data.csv";
  readFile.open(fileCsv.c_str());

  if (!readFile.is_open()) {
    std::cerr << "Fail to open file" << std::endl;
    return;
  }
  std::string date;
  std::string price;
  std::string header;
  if (std::getline(readFile, header)) {
    if (header.find("date") != std::string::npos) {};
  }
  while (std::getline(readFile, date, ',')) {
    if (std::getline(readFile, price)) {
      double value = std::atof(price.c_str());
      Map[date] = value;
    }
  }
}

bool validateCurrency(std::string& line) {
  int year = 0;
  int month = 0;
  int day = 0;
  char Hyphen1 = 0;
  char Hyphen2 = 0;
  char pipe = 0;
  double value = 0.0;
  std::stringstream ss(line);
  std::string date = line.substr(0,10);
  std::map<std::string, double> Map;
  fillMap(Map);
  std::map<std::string, double>::iterator it = Map.lower_bound(date);

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
    checkDay(day, month);
    if (pipe != '|') {
      throw std::string("Invalid format");
    }
    checkValue(value);
    if (it == Map.begin())
      throw std::string("Date too old");
    if (it != Map.end() && it->first == date) {
      std::cout << year << Hyphen1 << month << Hyphen2 << day << " => " << value << " = " << value * it->second << std::endl;
    } else {
      --it;
      std::cout << year << Hyphen1 << month << Hyphen2 << day << " => " << value << " = " << value * it->second << std::endl;
    }
  } catch (std::string& e) {
      std::cout << "Error: " << e << std::endl;
  }
  return true;
}
