#include "iter.hpp"
#include <iostream>

template <typename T>
void func(T n)
{
  std::cout << n << std::endl;
}

int main()
{
  char arr[] = "hello";
  size_t len = 5;
  
  iter(arr, len, func<char>);

  return 0;
}
