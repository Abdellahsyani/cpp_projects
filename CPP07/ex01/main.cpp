#include "iter.hpp"
#include <iostream>


/**
 * func: This function accept a const template data typename
 **/
template <typename T>
void func(T const& n)
{
  std::cout << n << std::endl;
}

/**
 * func1: This function accept a non const template data typename
 **/
template <typename T>
void func1(T& n)
{
  n++;
  std::cout << n << std::endl;
}

int main()
{
  float const arr[] = {1.2f, 54.6f,  34.5f};
  
  iter(arr, 3, func<float>);
  return 0;
}
