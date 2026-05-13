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
void PmergeMe::makePair(std::vector<Node> &pairs, std::vector<Node> &losers) {
  std::vector<Node> paired;

  for (size_t i = 0; i + 1 < pairs.size(); i += 2) {
    this->comparison++;
    if (pairs[i].winner > pairs[i + 1].winner) {
      paired.push_back(pairs[i]);
      losers.push_back(pairs[i + 1]);
    } else {
      paired.push_back(pairs[i+1]);
      losers.push_back(pairs[i]);
    }
  }

  pairs = paired;
  // if (pairs.size() % 2 != 0 && !paired.empty()) {
  //   paired.back().has_stray = true;
  //   paired.back().stray     = pairs[pairs.size() - 1].winner;
  // }
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

void print(std::vector<Node> &winner) {
    std::cout <<  "-----------------" << std::endl;
  for (size_t i = 0; i < winner.size(); ++i) {
    std::cout << winner[i].winner << " ";
  }
  std::cout << std::endl;
  std::cout <<  "-----------------" << std::endl;
}

/***/
void PmergeMe::sortRecursion(std::vector<Node> &winners) {
  if (winners.size() == 1) {
    return ;
  }

  std::vector<Node> losers;
  makePair(winners, losers);
  for (size_t i = 0; i < winners.size(); ++i) {
    winners[i].index.push_back(i);
  }
  for (size_t i = 0; i < losers.size(); ++i) {
    losers[i].index.push_back(i);
  }
  std::cout << "\n===== Winners: ===\n";
  print(winners);
  std::cout << "\n===== losers: ===\n";
  print(losers);
  sortRecursion(winners);
  FordJohnson(winners, losers);

}


/***/
void PmergeMe::FordJohnson(std::vector<Node> &winners, std::vector<Node> &losers) {
  std::vector<Node> MainChain;
  std::vector<Node> collection;
  
  for (size_t i = 0; i < winners.size(); ++i) {
    int idx = winners[i].index.back();
    std::cout << "idx: =====[ " << i << " ]=======> " << losers[idx].winner << std::endl;
    collection.push_back(losers[idx]);
  }
  std::cout << "Collection: \n";
  print(winners);
  std::cout << "===== Winners: ===\n";
  print(winners);
  std::cout << "===== losers: ===\n";
  print(collection);

  std::cout << "Loser[0]: " << losers[0].index[0] << std::endl;
  MainChain.push_back(losers[0]);
  std::vector<int> insertionOrder = getInsertionOrder(losers.size() - 1);
  std::cout << "\n*********************\n";
  std::cout << "instertion: ";
  for (size_t i = 0; i < insertionOrder.size(); ++i) {
    std::cout << insertionOrder[i] << " ";
  }
  std::cout << "\n*********************\n";

  size_t currJacob = 0;
  size_t prevJacob = 0;

  for (size_t i = 0; i < insertionOrder.size(); i++) {
    currJacob = insertionOrder[i];
    if (currJacob >= losers.size()) {
      currJacob = losers.size() - 1;
    }
    for (size_t j = prevJacob; j < currJacob; j++) {
      MainChain.push_back(winners[j]);
    }
    for (size_t k = currJacob; k > prevJacob; k--) {
      std::vector<Node>::iterator it = std::lower_bound(MainChain.begin(), MainChain.end(), losers[k]);
      // std::cout << "iterator: " << it->winner << " ";
      // std::cout << "loserK: " << losers[k].winner << " ";
      MainChain.insert(it, losers[k]);
    }
    prevJacob = currJacob;
  }
  for (size_t i = prevJacob; i < winners.size(); i++) {
    MainChain.push_back(winners[i]);
  }
  winners = MainChain;
  for (size_t i = 0; i < winners.size(); ++i) {
    winners[i].index.pop_back();
  }
  // std::cout << std::endl;
  // std::cout << "MainChain: ";
  // for (size_t i = 0; i < winners.size(); ++i) {
  //   std::cout << winners[i].winner << " ";
  // }
}

void PmergeMe::VectorTest(std::vector<Node> &pairs) {
  if (pairs.empty())
    return;

  std::cout << "===========Input========= \n";
  print(pairs);
  std::cout << "==================== \n";
  sortRecursion(pairs);
  std::cout << "=========Result=========== \n";
  print(pairs);
  std::cout << "==================== \n";
}

