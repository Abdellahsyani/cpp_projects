#include "RNP.hpp"


int main(int ac, char *av[]) {
  if (ac != 2) {
    std::cerr << "Error: One argument accepted" << std::endl;
    return 1;
  }

  std::string operation = av[1];
  std::stack<int> container;
  try {
    std::for_each(operation.begin(), operation.end(), ProcessOperation(container));
    if (container.size() > 1) {
      throw std::runtime_error("More than number in stack");
    }
    std::cout << container.top() << std::endl;
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
