#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <sys/time.h>

/**
 * Node: a struct to make pairs without using make_pair() function
 * @param winner: The winner pair 
 * @param losers: a vector of the losers that lose against winner
 * @param stray: the strugle number from pairs
 **/
struct Node {
  int winner;
  std::vector<int> index;
  bool has_stray;

  Node() : winner(0), has_stray(false) {}
  Node(int n) : winner(n), has_stray(false) {}

  bool operator<(const Node& other) const {
    return this->winner < other.winner;
  }
};

/**
 * ComparisonCounter: A struct to count comparisons
 *  count: reference to the count variable in PmergeMe class 
  *  operator(): overload the function call operator to compare two Node objects and increment the count 
  *  This struct allows you to keep track of the number of comparisons made during sorting by incrementing the count variable each time a comparison is made.
  *  You can use this struct as a comparison function in sorting algorithms, and it will automatically update the count variable with the number of comparisons performed.
  *  */
struct ComparisonCounter {
  size_t& count;
  ComparisonCounter(size_t& c) : count(c) {}

  bool operator()(const Node& a, const Node& b) const {
    count++; // Increment your class variable
    return a < b;
  }
};

/***/
class PmergeMe {
  private:
    double vectorTime;
    double dequeTime;
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();


    size_t comparison;

    std::vector<int> getInsertionOrder(int totalpending);
    int getNextJacobsthal(int prev, int curr);
    void sortVector(std::vector<Node>& pairs);
    void sortDeque(std::deque<Node>& pairs);
    double getTime();

    // ==========================================
    // ||        TEMPLATE DECLARATIONS         ||
    // ==========================================
    template <typename Container>
      void makePair(Container& pairs, Container& losers);

    template <typename Container>
    void print(Container &winner);

    template <typename Container>
      void FordJohnson(Container& winners, Container& losers);

    template <typename Container>
      void sortRecursion(Container& winners);

};

#include "PmergeMe.tpp"

#endif // !PMERGEME_HPP
