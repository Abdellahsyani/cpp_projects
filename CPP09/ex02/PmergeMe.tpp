#ifndef PMERGEME_TPP
#define PMERGEME_TPP

/***/
template <typename Container>
void PmergeMe::makePair(Container &pairs, Container &losers) {
  Container paired;

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

/***/
template <typename Container>
void PmergeMe::sortRecursion(Container &winners) {
  if (winners.size() == 1) {
    return ;
  }

  Container losers;
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
template <typename Container>
void PmergeMe::FordJohnson(Container &winners, Container &losers) {
  Container MainChain;
  Container collection;

  for (size_t i = 0; i < winners.size(); ++i) {
    int idx = winners[i].index.back();
    collection.push_back(losers[idx]);
  }

  // push stary element
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

    typename Container::iterator it_end = MainChain.end();

    if (k < (int)winners.size()) {
      for (typename Container::iterator it = MainChain.begin(); it != MainChain.end(); ++it) {
        if (it->winner == winners[k].winner) {
          it_end = it;
          break;
        }
      }
    }
    ComparisonCounter spy(this->comparison);

    typename Container::iterator insert_pos = std::lower_bound(MainChain.begin(), it_end, collection[k], spy);
    MainChain.insert(insert_pos, collection[k]);
  }

  winners = MainChain;
  for (size_t i = 0; i < winners.size(); ++i) {
    if (!winners[i].index.empty()) {
      winners[i].index.pop_back();
    }
  }
}


template<typename Container>
void PmergeMe::print(Container &winner) {
    std::cout <<  "-----------------" << std::endl;
  for (size_t i = 0; i < winner.size(); ++i) {
    std::cout << winner[i].winner << " ";
  }
  std::cout << std::endl;
  std::cout <<  "-----------------" << std::endl;
}
#endif
