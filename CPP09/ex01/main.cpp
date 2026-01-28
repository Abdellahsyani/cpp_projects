#include "RNP.hpp"


int main(int ac, char *av[]) {
  if (ac != 2) {
    std::cerr << "Error: One argument accepted" << std::endl;
    return 1;
  }

  std::string operation = av[1];
  ParseOperation(operation);

  return 0;
}
