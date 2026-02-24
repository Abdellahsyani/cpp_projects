#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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
  std::vector<int> losers;
  int stray;
  bool has_stray;

  Node() : winner(0), stray(0), has_stray(false) {}
};

struct ComparisonCounter {
    size_t& count;
    ComparisonCounter(size_t& c) : count(c) {}

    bool operator()(int a, int b) const {
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
  std::vector<int> pendingList;
  std::vector<int> MainChain;
  int BinarySearch(std::vector<int>& MainChain, int loser, int winner);
  std::vector<Node> SortNumbers(std::vector<Node>& sortedNodes, std::vector<Node>& pairs);
  std::vector<Node> makePair(std::vector<Node>& pairs);
  std::vector<Node> sortRecursion(std::vector<Node>& pairs);
  void FordJohnson(std::vector<Node>& sortList);
  void eraseNumber(int num);
  std::vector<int> getInsertionOrder(int totalpending);
  int getNextJacobsthal(int prev, int curr);
  void VectorTest(std::vector<Node>& pairs);
  
};

#endif // !PMERGEME_HPP
