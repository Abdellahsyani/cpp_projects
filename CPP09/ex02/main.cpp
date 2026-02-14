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

  std::vector<Node> pairs;
  std::vector<int> input;
  PmergeMe merge;
  try {
    int n = 0;
    for (int i = 1; i < ac; i++) {
      n = StringToInt(av[i]);
      input.push_back(n);
    }
    pairs.reserve(input.size() / 2);
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
      Node node;
      if (input[i] < input[i+1]) {
        merge.comparison++;
        node.winner = input[i+1];
        node.losers.push_back(input[i]);
        merge.pendingList.push_back(input[i]);
      } else {
        merge.comparison++;
        node.winner = input[i];
        node.losers.push_back(input[i+1]);
        merge.pendingList.push_back(input[i+1]);
      }
      pairs.push_back(node);
    }
    if (input.size() % 2 != 0)
    {
      pairs.back().stray = input[input.size() - 1];
      pairs.back().has_stray = true;
    }

  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  merge.VectorTest(pairs);
  std::cout << "comparison: " << merge.comparison << std::endl;
  // DequeTest();

  return 0;
}
