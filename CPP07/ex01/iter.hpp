#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename Array, typename F>
void iter(Array *arr, size_t const len, F func) {
  for (size_t i = 0; i < len; i++) {
    func(arr[i]);
  }
}


#endif
