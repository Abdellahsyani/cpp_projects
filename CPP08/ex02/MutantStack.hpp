#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>
#include <iostream>

/**
 * @brief A mutant version of std::stack that provides iterator access.
 *  * std::stack is a container adapter that usually hides its underlying 
 *      container. MutantStack inherits from std::stack and exposes the 
 *      underlying container's iterators, allowing it to be used with 
 *      STL algorithms and range-based loops while maintaining stack behavior.
 *
 * @tparam T The type of elements stored in the stack.
 */
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
