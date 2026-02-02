#include "PmergeMe.hpp"


int BinarySearch(std::vector<int>& MainChain, int loser, int winner) {
}

std::vector<Node> SortNumbers(std::vector<Node>& pairs) {
  if (pairs.size() <= 1)
    return pairs;
  for (size_t i = 0; i < pairs.size(); i += 2) {
    if (pairs[i].first > pairs[i].losers[i])
  }
  return SortNumbers();
}

std::vector<Node> sortRecursion(std::vector<Node>& pairs) {
  if (pairs.size() <= 1) {
    return pairs;
  }

  std::vector<Node> nextRound = makePair(pairs);
  std::vector<Node> mainChain = sortRecursion(nextRound);

  std::vector<Node> result = SortNumbers(mainChain);
  return result;
}

void VectorTest(std::vector<Node>& pairs) {
  if (pairs.size() <= 1)
      return pairs;

}
