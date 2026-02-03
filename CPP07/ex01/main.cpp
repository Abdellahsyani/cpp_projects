#include "iter.hpp"
#include <iostream>


/**
 * func1: This function accept a non const template data typename
 **/
template <typename T>
void func(T& n)
{
  n++;
  std::cout << n << std::endl;
}


int main()
{
  float arr[] = {1.2f, 54.6f,  34.5f};
  
  iter(arr, 3, func<float>);
  return 0;
}
