#ifdef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

template <typename T>
class MutantStack : std::stack<T> {
  private:
    std::stack<T> st;
public:
  MutantStack();
  MutantStack(const MutantStack<T>& other);
  MutantStack<T>& operator=(const MutantStack<T>& other);
  ~MutantStack();

  typedef typename 
};

#include "MutantStack.tpp";

#endif // MutantStack
