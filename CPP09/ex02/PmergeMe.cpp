#include "PmergeMe.hpp"


// int BinarySearch(std::vector<int>& MainChain, int loser, int winner) {
// }

std::vector<Node> SortNumbers(std::vector<Node>& mainChain, std::vector<Node>& pairs) {
  (void)mainChain;
  for (size_t i = 0; i < pairs.size(); i++) {
    std::cout << "Winner: " << pairs[i].winner;

    // Print ALL losers in this suitcase to see the history
    std::cout << " | Losers: [";
    for (size_t j = 0; j < pairs[i].losers.size(); j++) {
      std::cout << pairs[i].losers[j] << (j == pairs[i].losers.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
  }
  return pairs;
}

std::vector<Node> makePair(std::vector<Node>& pairs) {
  Node node;
  std::vector<Node> paired;

  node.rem = 0;
  for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
    if (pairs[i].winner > pairs[i+1].winner) {
      node.winner = pairs[i].winner;
      node.losers = pairs[i].losers;
      node.losers.push_back(pairs[i+1].winner);
    } else {
      node.winner = pairs[i+1].winner;
      node.losers = pairs[i].losers;
      node.losers.push_back(pairs[i].winner);
    }
    paired.push_back(node);
  }
  if (pairs.size() % 2 != 0)
    node.rem = pairs[pairs.size() - 1].winner;
  return paired;
}

std::vector<Node> sortRecursion(std::vector<Node>& pairs) {
  if (pairs.size() <= 1) {
    return pairs;
  }

  std::vector<Node> nextRound = makePair(pairs);
  std::vector<Node> mainChain = sortRecursion(nextRound);

  std::vector<Node> result = SortNumbers(mainChain, pairs);
  return result;
}

void VectorTest(std::vector<Node>& pairs) {
  std::vector<Node> sortList = sortRecursion(pairs);
  for (size_t i = 0; i < pairs.size(); i++) {
    std::cout << "Winner=>: " << pairs[i].winner;

    // Print ALL losers in this suitcase to see the history
    std::cout << " | Losers=>: [";
    for (size_t j = 0; j < pairs[i].losers.size(); j++) {
      std::cout << pairs[i].losers[j] << (j == pairs[i].losers.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
  }
}
