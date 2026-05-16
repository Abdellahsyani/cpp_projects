#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <climits>

/**
 * Node: a struct to make pairs without using make_pair() function
 * @param winner: The winner pair 
 * @param losers: a vector of the losers that lose against winner
 * @param stray: the strugle number from pairs
 * @param has_stray:  a boolean to check if a level of pairs has a stray
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

struct ComparisonCounter {
  size_t& count;
  ComparisonCounter(size_t& c) : count(c) {}

  bool operator()(const Node& a, const Node& b) const {
    count++; // Increment your class variable
    return a < b;
  }
};

class PmergeMe {
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

    // ==========================================
    // TEMPLATE DECLARATIONS
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
