#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>


/**
 * easyfind: A template function that search in a container and return the match int,
 *            if there is not match throw an runtime_error.
 *
 * @param container: This a sequence container to search on it to find the int n
 * @param n: an integer to search in inside the container. 
 *
 * return: The function return an container iterator
 */
template <typename T>
typename T::iterator easyfind(T& container, int n) {
  typename T::iterator it = find(container.begin(), container.end(), n);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return it;
}

#endif // !EASYFIND_HPP
