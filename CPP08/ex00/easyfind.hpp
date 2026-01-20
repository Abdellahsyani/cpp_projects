#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
T easyfind(T& container, int n) {
  typename T::iterator it = find(container.begin(), container.end(), n);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return it;
}

#endif // !EASYFIND_HPP
