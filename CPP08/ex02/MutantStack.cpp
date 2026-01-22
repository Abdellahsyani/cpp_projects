#ifdef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

template <typename T>
class MutantStack : std::stack<T> {
public:
  MutantStack();
  MutantStack(const MutantStack<T>& other);
  MutantStack<T>& operator=(const MutantStack<T>& other);
  ~MutantStack();
};

#endif // MutantStack
