#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
public:
  MutantStack() {};
  MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {};
  MutantStack<T>& operator=(const MutantStack<T>& other) {
    if (this != &other)
      std::stack<T>::operator=(other);
    return *this;
  };
  virtual ~MutantStack() {};

  typedef typename std::stack<T>::container_type::iterator iterator; 
  iterator begin() {
    return this->c.begin();
  }
  
  iterator end() {
    return this->c.end();
  }
};

#endif // MutantStack
