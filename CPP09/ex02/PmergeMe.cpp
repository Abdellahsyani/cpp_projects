#include "PmergeMe.hpp"


/***/
void BinarySearch(std::vector<int>& MainChain, int loser, int winner) {
  std::vector<int>::iterator limit;

  limit = std::find(MainChain.begin(), MainChain.end(), winner);
  std::vector<int>::iterator pos = std::lower_bound(MainChain.begin(), limit, loser);
  std::cout << "pos: " << *pos << std::endl;
  std::cout << "loser: " << loser << std::endl;
  std::cout << "winner: " << *limit << std::endl;
  MainChain.insert(pos, loser);
}

/***/
std::vector<Node> SortNumbers(std::vector<Node>& sortedNodes, std::vector<Node>& pairs) {
  std::vector<int> MainChain;

  // for (size_t i = 0; i < sortedNodes.size(); i++) {
  //   std::cout << "winner: " << sortedNodes[i].winner << std::endl;
  //   for (size_t j = 0; j < sortedNodes[i].losers.size(); j++)
  //     std::cout << "[losers: " << sortedNodes[i].losers[j] << " ]"<< std::endl;
  // }

  for (size_t i = 0; i < sortedNodes.size(); ++i) {
    MainChain.push_back(sortedNodes[i].winner);
  }

  if (!pairs.empty()) {
    int firstWinner = MainChain[0];
    for (size_t i = 0; i < pairs.size(); ++i) {
      if (pairs[i].winner == firstWinner) {
        MainChain.insert(MainChain.begin(), pairs[i].losers.back());
        break;

      }
    }
  }

  for (size_t i = 0; i < pairs.size(); ++i) {
    int currentLoser = pairs[i].losers.back();
    int currentWinner = pairs[i].winner;
    if (std::find(MainChain.begin(), MainChain.end(), currentLoser) == MainChain.end()) {
      BinarySearch(MainChain, currentLoser, currentWinner);
    }
  }

  if (!pairs.empty() && pairs.back().rem != -1) {
    int stray = pairs.back().rem;
    std::vector<int>::iterator pos = std::lower_bound(MainChain.begin(), MainChain.end(), stray);
    MainChain.insert(pos, stray);
  }


  std::vector<Node> result;
  for (size_t i = 0; i < MainChain.size(); ++i) {
    Node n;
    n.winner = MainChain[i];
    n.rem = -1;
    result.push_back(n);
  }
  return result;
}

std::vector<Node> makePair(std::vector<Node>& pairs) {
  std::vector<Node> paired;

  for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
    Node node;
    node.rem = -1;
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
  if (pairs.size() % 2 != 0 && !paired.empty())
    paired.back().rem = pairs[pairs.size() - 1].winner;
  return paired;
}


/***/
std::vector<Node> sortRecursion(std::vector<Node>& pairs) {
  if (pairs.size() <= 1) {
    return pairs;
  }

  std::vector<Node> nextRound = makePair(pairs);
  std::vector<Node> sortedWinners = sortRecursion(nextRound);

  return SortNumbers(sortedWinners, pairs);
}


/***/
void VectorTest(std::vector<Node>& pairs) {
  // std::cout << "before" << std::endl;
  // for (size_t i = 0; i + 1 < pairs.size(); ++i) {
  //     std::cout << pairs[i].winner << std::endl;
  //   }

  std::vector<Node> sortList = sortRecursion(pairs);
  // std::cout << "after" << std::endl;
  // for (size_t i = 0; i < sortList.size(); i++) {
  //     std::cout << sortList[i].winner << std::endl;
  // }
}
