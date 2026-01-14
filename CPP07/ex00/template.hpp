#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

/**
 * swap: A function that swaps two types by using template
 *
 * @param a: The first template parameter that will accept any type
 * @param b: The second template parameter that will accept any type
 *
 * NOTE:
 *    if you pass two different types to this function it will fail
 *    if you want to pass different types to one function you should declare template
 *    in this way " template <typename T, typename U> " the template should take two typename
 **/
template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

/**
 * min: A function that compare two types and return the min one
 *
 * @param a: The first template parameter that will accept any type
 * @param b: The second template parameter that will accept any type
 *
 * @return: the smallest one (a : b)
 *
 * NOTE:
 *    if you pass two different types to this function it will fail
 *    if you want to pass different types to one function you should declare template
 *    in this way " template <typename T, typename U> " the template should take two typename
 **/
template <typename T>
T min(T a, T b) {
  return (a < b) ? a : b;
}


/**
 * max: A function that compare two types and return the biggest one
 *
 * @param a: The first template parameter that will accept any type
 * @param b: The second template parameter that will accept any type
 *
 * @return: the biggest one (a : b)
 *
 * NOTE:
 *    if you pass two different types to this function it will fail
 *    if you want to pass different types to one function you should declare template
 *    in this way " template <typename T, typename U> " the template should take two typename
 **/
template <typename T>
T max(T a, T b) {
  return (a > b) ? a : b;
}


#endif

