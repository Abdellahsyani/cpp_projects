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
 
  std::vector<Node> pairs1;
  std::deque<Node> pairs2;
  std::vector<int> input;
  PmergeMe merge;
  try {
    int n = 0;
    for (int i = 1; i < ac; i++) {
      n = StringToInt(av[i]);
      pairs1.push_back(Node(n));
      pairs2.push_back(Node(n));
    }
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
    return 1;
  }
 
  merge.sortVector(pairs1);
  merge.sortDeque(pairs2);
 
  return 0;
}
