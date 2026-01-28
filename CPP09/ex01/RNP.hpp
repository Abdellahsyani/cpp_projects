#ifndef RNP_HPP
# define RNP_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>

/***/
struct ProcessOperation {

  std::stack<int>& _container;
  ProcessOperation(std::stack<int>& container);
  void operator()(char c);
  bool CheckOp(char c);
};

#endif // !RNP_HP
