#include "PmergeMe.hpp"


void BinarySearch(std::vector<int>& MainChain, int loser, int winner) {
  std::vector<int>::iterator limit;

  limit = std::find(MainChain.begin(), MainChain.end(), winner);
  std::vector<int>::iterator pos = std::lower_bound(MainChain.begin(), limit, loser);
  MainChain.insert(pos, loser);
}

std::vector<Node> SortNumbers(std::vector<Node>& sortedNodes, std::vector<Node>& pairs) {
  std::vector<int> MainChain;

  for (size_t i = 0; i < sortedNodes.size(); i++) {
    MainChain.push_back(sortedNodes[i].winner)
  }

  if (!pairs.empty()) {

  }
}

std::vector<Node> makePair(std::vector<Node>& pairs) {
  std::vector<Node> paired;

  for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
    Node node;
    node.rem = 0;
    if (pairs[i].winner > pairs[i+1].winner) {
      node.winner = pairs[i].winner;
      node.losers = pairs[i].losers;
      node.losers.push_back(pairs[i+1].winner);
    } else {
      node.winner = pairs[i+1].winner;
      node.losers = pairs[i+1].losers;
      node.losers.push_back(pairs[i].winner);
    }
    paired.push_back(node);
  }
  if (pairs.size() % 2 != 0)
    node.rem = pairs[pairs.size() - 1].winner;
  else {
    node.rem = -1;
  }
  return paired;
}

std::vector<Node> sortRecursion(std::vector<Node>& pairs) {
  if (pairs.size() <= 1) {
      return pairs;
  }

  std::vector<Node> nextRound = makePair(pairs);
  std::vector<Node> sortedWinners = sortRecursion(nextRound);

  return SortNumbers(mainChain, pairs);
}

void VectorTest(std::vector<Node>& pairs) {
  std::vector<Node> sortList = sortRecursion(pairs);
}
