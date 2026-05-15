#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : comparison(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
  *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
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
  if (pairs.size() % 2 != 0)
    losers.push_back(pairs.back());

  pairs = paired;
}


int PmergeMe::getNextJacobsthal(int prev, int curr) { return curr + 2 * prev; }

void print(std::vector<Node> &winner) {
    std::cout <<  "-----------------" << std::endl;
  for (size_t i = 0; i < winner.size(); ++i) {
    std::cout << winner[i].winner << " ";
  }
  std::cout << std::endl;
  std::cout <<  "-----------------" << std::endl;
}

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
  sortRecursion(winners);

  FordJohnson(winners, losers);
}


/***/
void PmergeMe::FordJohnson(std::vector<Node> &winners, std::vector<Node> &losers) {
  std::vector<Node> MainChain;
  std::vector<Node> collection;

  for (size_t i = 0; i < winners.size(); ++i) {
    int idx = winners[i].index.back();
    collection.push_back(losers[idx]);
  }

  if (losers.size() > winners.size()) {
    collection.push_back(losers.back()); 
  }
  MainChain.push_back(collection[0]);
  for (size_t i = 0; i < winners.size(); ++i) {
    MainChain.push_back(winners[i]);
  }

  std::vector<int> insertionOrder = getInsertionOrder(collection.size() - 1);

  for (size_t i = 0; i < insertionOrder.size(); i++) {
    int k = insertionOrder[i];

    if (k >= (int)collection.size()) {
      continue; 
    }

    std::vector<Node>::iterator it_end = MainChain.end();

    if (k < (int)winners.size()) {
      for (std::vector<Node>::iterator it = MainChain.begin(); it != MainChain.end(); ++it) {
        if (it->winner == winners[k].winner) {
          it_end = it;
          break;
        }
      }
    }
    ComparisonCounter spy(this->comparison);

    std::vector<Node>::iterator insert_pos = std::lower_bound(MainChain.begin(), it_end, collection[k], spy);
    MainChain.insert(insert_pos, collection[k]);
  }

  winners = MainChain;
  for (size_t i = 0; i < winners.size(); ++i) {
    if (!winners[i].index.empty()) {
      winners[i].index.pop_back();
    }
  }
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

