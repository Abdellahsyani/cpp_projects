#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : comparison(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
  *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe() {}

/***/
int PmergeMe::getNextJacobsthal(int prev, int curr) { return curr + 2 * prev; }

/***/
std::vector<int> PmergeMe::getInsertionOrder(int totalpending) {
  std::vector<int> order;
  if (totalpending <= 0)
    return order;

  int prevJacob = 1;
  int currJacob = 3;
  int lastReach = 0; 

  while (lastReach < totalpending) {
    int limitJacob = (currJacob > totalpending) ? totalpending : currJacob;
    for (int i = limitJacob; i > lastReach; --i)
      order.push_back(i);
    lastReach     = limitJacob;
    int nextJacob = getNextJacobsthal(prevJacob, currJacob);
    prevJacob     = currJacob;
    currJacob     = nextJacob;
  }
   return order;
}

/***/
void PmergeMe::sortDeque(std::deque<Node> &pairs) {
  if (pairs.empty())
    return;

  this->comparison = 0;
  std::cout << "===========Input In Deque ========= \n";
  print(pairs);
  std::cout << "==================== \n";
  sortRecursion(pairs);
  std::cout << "=========Result In Deque=========== \n";
  print(pairs);
  std::cout << "Comparison In Deque: " << comparison << std::endl;
  std::cout << "==================== \n";
}

/***/
void PmergeMe::sortVector(std::vector<Node> &pairs) {
  if (pairs.empty())
    return;

  this->comparison = 0;
  std::cout << "===========Input In Vector ========= \n";
  print(pairs);
  std::cout << "==================== \n";
  sortRecursion(pairs);
  std::cout << "=========Result In Vector =========== \n";
  print(pairs);
  std::cout << "Comparison In Vector: " << comparison << std::endl;
  std::cout << "==================== \n";
}

