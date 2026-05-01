#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : comparison(0) {}
 
PmergeMe::PmergeMe(const PmergeMe &other) {
  this->comparison  = other.comparison;
  this->pendingList = other.pendingList;
  this->MainChain   = other.MainChain;
}
 
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    this->comparison  = other.comparison;
    this->pendingList = other.pendingList;
    this->MainChain   = other.MainChain;
  }
  return *this;
}
 
PmergeMe::~PmergeMe() {}
 
/***/
int PmergeMe::BinarySearch(std::vector<int> &MainChain, int winner, int loser) {
  std::vector<int>::iterator WinnerIt =
      std::find(MainChain.begin(), MainChain.end(), winner);
  std::vector<int>::iterator end =
      (WinnerIt != MainChain.end()) ? WinnerIt : MainChain.end();
  ComparisonCounter spy(this->comparison);
  std::vector<int>::iterator it =
      std::lower_bound(MainChain.begin(), end, loser, spy);
  return std::distance(MainChain.begin(), it);
}
 
/***/
std::vector<Node> PmergeMe::SortNumbers(std::vector<Node> &sortedNodes,
                                        std::vector<Node> &pairs) {
 
  // std::cout << " ---------------- level -----------------" << std::endl;
  // std::cout << " sortedNodes: ";
  // for (size_t i = 0; i < sortedNodes.size(); ++i)
  //   std::cout << sortedNodes[i].winner << " ";
  // std::cout << std::endl;
  // std::cout << " ---------------------------------" << std::endl;
  // std::cout << " pairs: ";
  // for (size_t i = 0; i < pairs.size(); ++i)
  //   std::cout << pairs[i].winner << " ";
  // std::cout << std::endl;
  // std::cout << " ---------------------------------" << std::endl;
  // std::cout << " MainChain: ";
  // for (size_t i = 0; i < MainChain.size(); ++i)
  //   std::cout << MainChain[i] << " ";
  // std::cout << std::endl;
  for (size_t i = 0; i < sortedNodes.size(); ++i) {
    Node &node = sortedNodes[i];
    if (node.losers.empty())
      continue;
    int loserValue = node.losers.back();
    int upperBound = node.winner;
    int pos = BinarySearch(MainChain, upperBound, loserValue);
    MainChain.insert(MainChain.begin() + pos, loserValue);
  }
 
  for (size_t i = 0; i < sortedNodes.size(); ++i) {
    if (sortedNodes[i].has_stray) {
      int strayValue = sortedNodes[i].stray;
      ComparisonCounter spy(this->comparison);
      std::vector<int>::iterator it =
          std::lower_bound(MainChain.begin(), MainChain.end(), strayValue, spy);
      MainChain.insert(it, strayValue);
      break;
    }
  }
 
  return pairs;
}
 
/***/
std::vector<Node> PmergeMe::makePair(std::vector<Node> &pairs) {
  std::vector<Node> paired;
 
  for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
    Node node;
    this->comparison++;
    if (pairs[i].winner > pairs[i + 1].winner) {
      node.winner = pairs[i].winner;
      node.losers = pairs[i].losers;
      node.losers.push_back(pairs[i + 1].winner);
    } else {
      node.winner = pairs[i + 1].winner;
      node.losers = pairs[i + 1].losers;
      node.losers.push_back(pairs[i].winner);
    }
    paired.push_back(node);
  }
 
  if (pairs.size() % 2 != 0 && !paired.empty()) {
    paired.back().has_stray = true;
    paired.back().stray     = pairs[pairs.size() - 1].winner;
  }
 
  return paired;
}
 
/***/
std::vector<Node> PmergeMe::sortRecursion(std::vector<Node> &pairs) {
  if (pairs.size() == 1) {
    MainChain.clear();
    MainChain.push_back(pairs[0].winner);
    return pairs;
  }
 
  std::vector<Node> nextRound     = makePair(pairs);
  std::vector<Node> sortedWinners = sortRecursion(nextRound);
 
  return SortNumbers(sortedWinners, pairs);
}
 
// void PmergeMe::eraseNumber(int num) {
//   std::vector<int>::iterator iv =
//       std::find(pendingList.begin(), pendingList.end(), num);
//   if (iv != pendingList.end())
//     pendingList.erase(iv);
// }
 
int PmergeMe::getNextJacobsthal(int prev, int curr) { return curr + 2 * prev; }
 
/***/
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
void PmergeMe::FordJohnson(std::vector<Node> &sortList) {
  if (MainChain.empty() || sortList.empty())
    return;
 
  int freeInsert = MainChain[0];
  int freeOne    = -1;
  for (size_t i = 0; i < sortList.size(); i++) {
    if (sortList[i].winner == freeInsert && !sortList[i].losers.empty()) {
      freeOne = sortList[i].losers.back(); // FIX: was losers[0]
      break;
    }
  }
 
  if (freeOne != -1) {
    MainChain.insert(MainChain.begin(), freeOne);
    // eraseNumber(freeOne);
  }
  if (pendingList.empty())
    return;
 
  std::vector<int> order = getInsertionOrder((int)pendingList.size());
 
  for (size_t j = 0; j < order.size(); j++) {
    int idx = order[j] - 1;
    if (idx < 0 || idx >= (int)pendingList.size())
      continue;
 
    int loser  = pendingList[idx];
    int winner = -1;
 
    for (size_t i = 0; i < sortList.size(); i++) {
      if (!sortList[i].losers.empty() && sortList[i].losers.back() == loser) {
        winner = sortList[i].winner;
        break;
      }
    }
 
    if (winner == -1) {
      ComparisonCounter spy(this->comparison);
      std::vector<int>::iterator it =
          std::lower_bound(MainChain.begin(), MainChain.end(), loser, spy);
      MainChain.insert(it, loser);
    } else {
      int pos = BinarySearch(MainChain, winner, loser);
      MainChain.insert(MainChain.begin() + pos, loser);
    }
  }
}
 
void PmergeMe::VectorTest(std::vector<Node> &pairs) {
  if (pairs.empty())
    return;
 
  std::vector<Node> sortList = sortRecursion(pairs);
  FordJohnson(sortList);
  std::cout << "sortList: ";
  for (size_t i = 0; i < sortList.size(); i++)
    std::cout << sortList[i].winner << " ";
  std::cout << std::endl;
 
  std::cout << "After: ";
  for (size_t i = 0; i < MainChain.size(); i++)
    std::cout << MainChain[i] << " ";
  std::cout << std::endl;
}
