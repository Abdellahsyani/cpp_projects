#include "iter.hpp"
#include <iostream>


/***/
template <typename T>
void func(T const& n)
{
  std::cout << n << std::endl;
}

int main()
{
  float arr[] = {1.2f, 54.6f,  34.5f};
  size_t const len = 3;
  
  iter(arr, len, func<float>);

  return 0;
}
