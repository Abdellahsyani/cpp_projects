#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

struct Node {
  int winner;
  std::vector<int> losers;
  int stray;
  bool has_stray;

  Node() : winner(0), stray(0), has_stray(false) {}
};


class PmergeMe {
private:
  size_t comparison;

public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  // std::vector<int> pendinglist;
  int BinarySearch(std::vector<int>& MainChain, int loser, int winner);
  std::vector<Node> SortNumbers(std::vector<Node>& sortedNodes, std::vector<Node>& pairs);
  std::vector<Node> makePair(std::vector<Node>& pairs);
  std::vector<Node> sortRecursion(std::vector<Node>& pairs);
  void VectorTest(std::vector<Node>& pairs);
  
};

#endif // !PMERGEME_HPP
