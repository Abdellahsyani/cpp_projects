#include "PmergeMe.hpp"


int StringToInt(const char *str) {
  char *endPtr;
  long val = std::strtol(str, &endPtr, 10);

  if (*endPtr != '\0') {
    throw std::runtime_error("Invalid Character");
  }

  if (val > INT_MAX || val < 0) {
    throw std::runtime_error("Invalid Number");
  }

  return static_cast<int>(val);
}


int main(int ac, char *av[]) {

  if (ac < 2) {
    std::cout << "Error: Enter some number" << std::endl;
    return 1;
  }

  std::vector<std::pair<int, int>> pairs;
  std::vector<int> input;
  try {
    int n = 0;
    for (int i = 1; i < ac; i++) {
      n = StringToInt(av[i]);
      input.push_back(n);
    }
    int reminder = 0;
    for (int i = 0; i + 1 < input.size(); i += 2) {
      if (input[i] < input[i+1]) {
        pairs.push_back(std::make_pair(input[i+1], input[i]));
      } else {
        pairs.push_back(std::make_pair(input[i], input[i+1]));
      }
      if (input.size() % 2 != 0)
        reminder = input[input.size() - 1];
    }

    // for (const auto&p : pairs) {
    //   std::cout << "first: " << p.first << " second: " << p.second << std::endl;
    // }
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  // VectorTest();
  // DequeTest();

  return 0;
}
