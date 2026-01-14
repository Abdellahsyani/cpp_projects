#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>


/**
 * iter: Iterates through an array and applies a function to each element.
 *   * This is a higher-order function template that decouples array traversal 
 *     from the logic applied to the data.
 *
 * @param arr:  Pointer to the first element of the array.
 * @param len:  The number of elements to process (size_t for architectural safety).
 * @param func: A callable entity (function, functor) to apply to each element.
 **/
template <typename Array, typename F>
void iter(Array *arr, size_t const len, F func) {
  for (size_t i = 0; i < len; i++) {
    func(arr[i]);
  }
}


#endif
