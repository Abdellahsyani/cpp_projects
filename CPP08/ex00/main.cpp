#include <iostream>
#include "easyfind.hpp"


int main() {

  std::vector<int> v;
  v.push_back(10);
  v.push_back(13);
  v.push_back(11);

  std::list<int> l; 
  l.push_back(2);
  l.push_back(6);
  l.push_back(4);

  try {
    std::vector<int>::iterator itV = easyfind(v, 13);
    std::cout << "Found in Vector: " << *itV << std::endl;

    std::list<int>::iterator itL = easyfind(l, 4);
    std::cout << "Found in List: " << *itL << std::endl;
  }


  return 0;
}
