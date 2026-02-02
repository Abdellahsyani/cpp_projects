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
  int rem;
};

void VectorTest(std::vector<Node>& pairs);

#endif // !PMERGEME_HPP
