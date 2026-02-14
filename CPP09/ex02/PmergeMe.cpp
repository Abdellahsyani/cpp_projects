#include "PmergeMe.hpp"

/***/
PmergeMe::PmergeMe() : comparison(0) {};

/***/
PmergeMe::PmergeMe(const PmergeMe& other) {
  this->comparison = other.comparison;
}

/***/
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other)
    this->comparison = other.comparison;
  return *this;
}

/***/
PmergeMe::~PmergeMe() {};

/***/
int PmergeMe::BinarySearch(std::vector<int>& MainChain, int winner, int loser) {
  std::vector<int>::iterator it;

  std::vector<int>::iterator WinnerIt = std::find(MainChain.begin(), MainChain.end(), winner);
  if (WinnerIt == MainChain.end())
    return 0;

  ComparisonCounter spy(this->comparison);
  it = std::lower_bound(MainChain.begin(), WinnerIt, loser, spy);
  int pos = std::distance(MainChain.begin(), it);

  return pos;
}

/***/
std::vector<Node> PmergeMe::SortNumbers(std::vector<Node>& sortedNodes, std::vector<Node>& pairs) {
  MainChain.clear();

  for (size_t i = 0; i < sortedNodes.size(); ++i) {
    MainChain.push_back(sortedNodes[i].winner);
  }

  for (size_t i = 0; i < sortedNodes.size(); ++i) {
    Node& node = sortedNodes[i];
    if (sortedNodes[i].has_stray == true)
      std::cout << "stray: " << sortedNodes[i].stray << std::endl;

    for (size_t j = node.losers.size() - 1; j > 0; --j) {
      int loserValue = node.losers[j];
      int upperBound = node.winner;

      int pos = BinarySearch(MainChain, upperBound, loserValue);
      MainChain.insert(MainChain.begin() + pos, loserValue);
    }
  }
  for (size_t i = 0; i < sortedNodes.size(); i++) {
    if (sortedNodes[i].has_stray == true) {
      int strayValue = sortedNodes[i].stray;
      std::vector<int>::iterator it;

      std::vector<int>::iterator WinnerIt = std::find(MainChain.begin(), MainChain.end(), strayValue);
      it = std::lower_bound(MainChain.begin(), WinnerIt, strayValue);
      int pos = std::distance(MainChain.begin(), it);
      MainChain.insert(MainChain.begin() + pos, strayValue);
      break;
    }
  }

  return pairs;
}

/***/
std::vector<Node> PmergeMe::makePair(std::vector<Node>& pairs) {
  std::vector<Node> paired;

  for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
    Node node;
    if (pairs[i].winner > pairs[i+1].winner) {
      this->comparison++;
      node.winner = pairs[i].winner;
      node.losers = pairs[i].losers;
      node.losers.push_back(pairs[i+1].winner);
    } else {
      this->comparison++;
      node.winner = pairs[i+1].winner;
      node.losers = pairs[i+1].losers;
      node.losers.push_back(pairs[i].winner);
    }
    paired.push_back(node);
  }
  if (pairs.size() % 2 != 0 && !paired.empty())
  {
    paired.back().stray = pairs[pairs.size() - 1].winner;
    paired.back().has_stray = true;
  }
  return paired;
}


/***/
std::vector<Node> PmergeMe::sortRecursion(std::vector<Node>& pairs) {
  if (pairs.size() <= 1) {
    return pairs;
  }

  std::vector<Node> nextRound = makePair(pairs);
  std::vector<Node> sortedWinners = sortRecursion(nextRound);

  return SortNumbers(sortedWinners, pairs);
}

/***/
void PmergeMe::eraseNumber(int num) {
  std::vector<int>::iterator iv = std::find(pendingList.begin(), pendingList.end(), num);
  if (iv != pendingList.end())
    pendingList.erase(iv);
}

/***/ 
int PmergeMe::getNextJacobsthal(int prev, int curr) {
  return curr + 2 * prev;
}

/***/
std::vector<int> PmergeMe::getInsertionOrder(int totalpending) {
  std::vector<int> order;
  int prevJacob = 1;
  int currJacob = 3;
  int lastReach = 1;

  order.push_back(1);
  while (lastReach < totalpending) {
    int limitJacob = (currJacob > totalpending) ? totalpending : currJacob;

    for (int i = limitJacob; i > lastReach; --i) {
      order.push_back(i);
    }

    lastReach = limitJacob;
    int nextJacob = getNextJacobsthal(prevJacob, currJacob);
    prevJacob = currJacob;
    currJacob = nextJacob;
  }

  std::cout << "Jacobsthal: ";
  for (size_t o = 0; o < order.size(); o++)
    std::cout << order[o] << " ";
  std::cout << "\n";
  return order;
}

/***/
void PmergeMe::FordJohnson(std::vector<Node>& sortList) {

  int freeInsert = MainChain[0];
  int freeOne;
  std::vector<Node>::iterator it = sortList.begin();
  while (it != sortList.end()) {
    if (it->winner == freeInsert)
    {
      freeOne = it->losers[0];
      break;
    }
    ++it;
  }
  MainChain.insert(MainChain.begin(), freeOne);
  eraseNumber(freeOne);
  std::vector<int> order = getInsertionOrder(pendingList.size());

  for (size_t j = 0; j < order.size(); j++) {
    int idx = order[j] - 1;
    if (idx >= (int)pendingList.size())
      continue;

    int loser = pendingList[idx];

    int winner = -1;
    for (size_t i = 0; i < sortList.size(); i++) {
      if (sortList[i].losers[0] == loser) {
        winner = sortList[i].winner;
        break;
      }
    }
    if (winner == -1)
      continue;

    int pos = BinarySearch(MainChain, winner, loser);
    MainChain.insert(MainChain.begin() + pos, loser);
  }

  for (size_t i = 0; i < MainChain.size(); i++)
    std::cout << MainChain[i] << " ";
  std::cout << "\n";
}

/***/
void PmergeMe::VectorTest(std::vector<Node>& pairs) {
  // std::cout << "before" << std::endl;

  std::vector<Node> sortList = sortRecursion(pairs);
  FordJohnson(sortList);

  // for (size_t i = 0; i < sortList.size(); i++) {
  //   std::cout << "Winner[ " << sortList[i].winner << " ]=> (";
  //   for (size_t j = 0; j < sortList[i].losers.size(); j++) {
  //     std::cout << sortList[i].losers[j] << " ";
  //   }
  //   std::cout << ")" << std::endl;
  // }
}
