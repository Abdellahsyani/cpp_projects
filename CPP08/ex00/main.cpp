#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>


/**
 * main: Testing the easyfind function to make sure all work perfectly
 *  This can be tested only by using a sequence containers (list, vector, deque..)
 **/
int main() {

  std::vector<int> v;
  v.push_back(10);
  v.push_back(13);
  v.push_back(11);

  std::list<int> l; 
  l.push_back(2);
  l.push_back(6);
  l.push_back(4);

  std::deque<int> d;
  d.push_back(45);
  d.push_back(32);
  d.push_front(4);
  d.push_back(1);

  try {
    std::vector<int>::iterator itV = easyfind(v, 13);
    std::cout << "Found in Vector: " << *itV << std::endl;

    std::list<int>::iterator itl = easyfind(l, 4);
    std::cout << "found in list: " << *itl << std::endl;

    std::deque<int>::iterator itD = easyfind(d, 1);
    std::cout << "Found in Deque: " << *itD << std::endl;

  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
