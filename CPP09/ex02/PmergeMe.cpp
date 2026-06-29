#include "PmergeMe.hpp"

/**
 * Default constructor initializes the comparison count to 0.
 * This constructor is called when an object of PmergeMe is created without any arguments.
 * */
PmergeMe::PmergeMe() : comparison(0) {}

/**
 * Copy constructor creates a new object as a copy of an existing object.
 * It takes a reference to another PmergeMe object and copies its data members.
 * In this implementation, it simply assigns the current object to the other object using the assignment operator.
 * */
PmergeMe::PmergeMe(const PmergeMe &other) {
  *this = other;
}

/**
 * Assignment operator allows you to assign one object to another.
 * It takes a reference to another PmergeMe object and copies its data members.
 * In this implementation, it simply returns the current object without performing any actual copying, as there are no dynamic resources to manage.
 * */
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return *this;
}

/** Destructor is called when an object of PmergeMe is destroyed.
 * It is responsible for cleaning up any resources that the object may have acquired during its lifetime.
 * In this implementation, there are no dynamic resources to clean up, so the destructor is empty.
 * */
PmergeMe::~PmergeMe() {}

/** getNextJacobsthal calculates the next Jacobsthal number based on the previous two Jacobsthal numbers.
 * It takes two integers, prev and curr, which represent the previous and current Jacobsthal numbers, respectively.
 * The function returns the next Jacobsthal number by adding the current Jacobsthal number to twice the previous Jacobsthal number.
 * This is based on the recursive definition of Jacobsthal numbers, where J(n) = J(n-1) + 2 * J(n-2).
 * */
int PmergeMe::getNextJacobsthal(int prev, int curr) { return curr + 2 * prev; }

/** getInsertionOrder generates a vector of integers representing the order of insertion based on Jacobsthal numbers.
 * It takes an integer totalpending, which represents the total number of pending elements to be inserted.
 * The function initializes an empty vector order to store the insertion order.
 * It uses a while loop to generate Jacobsthal numbers until it reaches or exceeds totalpending.
 * Inside the loop, it calculates the limitJacob, which is the minimum of the current Jacobsthal number and totalpending.
 * It then pushes back integers from limitJacob down to lastReach + 1 into the order vector.
 * Finally, it updates lastReach to limitJacob and calculates the next Jacobsthal number for the next iteration.
 * The function returns the generated insertion order as a vector of integers.
 * */
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
  std::cout << "Comparison In Vector: " << comparison << std::endl;
  std::cout << "==================== \n";
}

