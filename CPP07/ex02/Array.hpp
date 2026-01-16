#ifndef ARRAY_HPP
# define ARRAY_HPP


template <typename T>
class Array {
  private:
    T* _element;
    unsigned int _n;
  public:
    Array();
    Array(unsigned int size);
    Array(const Array &other);
    Array &operator=(const Array &other);
    Array &operator[](Array &other);
    ~Array();
};

#include "Array.tpp"

#endif // !ARRAY_HPP
