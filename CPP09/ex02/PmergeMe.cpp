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
void PmergeMe::sortRecursion(std::vector<Node> &pairs) {
  std::vector<int> values;
  for (size_t i = 0; i < pairs.size(); ++i) {
    values.push_back(pairs[i].winner);
    for (size_t j = 0; j < pairs[i].losers.size(); ++j)
      values.push_back(pairs[i].losers[j]);
  }
  MainChain = fordJohnsonSort(values);
}

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

std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int>& values) {
  if (values.size() <= 1)
    return values;

  std::vector<int> winners;
  std::vector<std::pair<int, int> > pending;
  bool hasStray = false;
  int stray = 0;

  for (size_t i = 0; i + 1 < values.size(); i += 2) {
    int first = values[i];
    int second = values[i + 1];
    this->comparison++;
    if (first < second) {
      winners.push_back(second);
      pending.push_back(std::make_pair(second, first));
    } else {
      winners.push_back(first);
      pending.push_back(std::make_pair(first, second));
    }
  }

  if (values.size() % 2 != 0) {
    hasStray = true;
    stray = values[values.size() - 1];
  }

  std::vector<int> mainChain = fordJohnsonSort(winners);
  if (pending.empty()) {
    if (hasStray) {
      ComparisonCounter spy(this->comparison);
      std::vector<int>::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), stray, spy);
      mainChain.insert(it, stray);
    }
    return mainChain;
  }

  std::vector<std::pair<int, int> > orderedPending;
  std::vector<bool> used(pending.size(), false);
  for (size_t i = 0; i < mainChain.size(); ++i) {
    for (size_t j = 0; j < pending.size(); ++j) {
      if (!used[j] && pending[j].first == mainChain[i]) {
        used[j] = true;
        orderedPending.push_back(pending[j]);
        break;
      }
    }
  }

  for (size_t j = 0; j < pending.size(); ++j) {
    if (!used[j])
      orderedPending.push_back(pending[j]);
  }

  std::vector<bool> inserted(orderedPending.size(), false);
  if (!orderedPending.empty()) {
    mainChain.insert(mainChain.begin(), orderedPending[0].second);
    inserted[0] = true;
  }

  if (orderedPending.size() > 1) {
    std::vector<int> order =
      getInsertionOrder(static_cast<int>(orderedPending.size() - 1));

    for (size_t j = 0; j < order.size(); ++j) {
      size_t pendingIdx = static_cast<size_t>(order[j]);
      if (pendingIdx >= orderedPending.size() || inserted[pendingIdx])
        continue;
      int pos = BinarySearch(mainChain,
          orderedPending[pendingIdx].first,
          orderedPending[pendingIdx].second);
      mainChain.insert(mainChain.begin() + pos, orderedPending[pendingIdx].second);
      inserted[pendingIdx] = true;
    }

    for (size_t i = 1; i < orderedPending.size(); ++i) {
      if (!inserted[i]) {
        int pos = BinarySearch(mainChain,
            orderedPending[i].first,
            orderedPending[i].second);
        mainChain.insert(mainChain.begin() + pos, orderedPending[i].second);
        inserted[i] = true;
      }
    }
  }

  if (hasStray) {
    ComparisonCounter spy(this->comparison);
    std::vector<int>::iterator it =
      std::lower_bound(mainChain.begin(), mainChain.end(), stray, spy);
    mainChain.insert(it, stray);
  }

  return mainChain;
}

void PmergeMe::VectorTest(std::vector<Node> &pairs) {
  if (pairs.empty())
    return;

  sortRecursion(pairs);
}
