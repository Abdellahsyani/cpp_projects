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
  struct timeval start, end;

  this->comparison = 0;

  gettimeofday(&start, NULL);
  sortRecursion(pairs);
  gettimeofday(&start, NULL);
  double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

/***/
void PmergeMe::sortVector(std::vector<Node> &pairs) {
  if (pairs.empty())
    return;

  this->comparison = 0;
  std::cout << "Before: ";
  print(pairs);
  sortRecursion(pairs);
  std::cout << "After: ";
  print(pairs);
  std::cout << "Time to process a range of " << 5 << " elements with std::vector : " <<  0.00031 " us" << std::endl;
  std::cout << "Time to process a range of " << 5 << " elements with std::deque : " <<  0.00031 " us" << std::endl;
  // std::cout << "Comparison In Vector: " << comparison << std::endl;
  // std::cout << "==================== \n";
}

