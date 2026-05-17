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
void checkSort(std::vector<Node> numbers) {
  for (size_t i = 0; i < numbers.size() - 1; i++) {
    if (numbers[i] < numbers[i+1] || numbers[i].winner == numbers[i+1].winner)
      continue;
    else {
      std::cout << "Numbers aren't sorted: " << numbers[i].winner << std::endl;
      exit(0);
    }
  }
}

/***/
void PmergeMe::sortDeque(std::deque<Node> &pairs) {
  if (pairs.empty())
    return;
  struct timeval start, end;

  this->comparison = 0;

  gettimeofday(&start, NULL);
  sortRecursion(pairs);
  gettimeofday(&end, NULL);
  this->dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
  std::cout << "Time to process a range of " << pairs.size() << " elements with std::deque : " <<  this->dequeTime << " us" << std::endl;
}

/***/
void PmergeMe::sortVector(std::vector<Node> &pairs) {
  if (pairs.empty())
    return;

  struct timeval start, end;
  this->comparison = 0;

  std::cout << "Before: ";
  print(pairs);

  gettimeofday(&start, NULL);
  sortRecursion(pairs);
  gettimeofday(&end, NULL);
  this->vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

  std::cout << "After: ";
  print(pairs);
  checkSort(pairs);
  std::cout << "Time to process a range of " << pairs.size() << " elements with std::vector : " <<  this->vectorTime << " us" << std::endl;
  // std::cout << "Comparison In Vector: " << comparison << std::endl;
  // std::cout << "==================== \n";
}

