#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
  private:
    T* _element;
    unsigned int _n;
  public:
    Array();
    Array(Array &&);
    Array(const Array &other);
    Array &operator=(const Array &other);
    Array &operator[](Array &other);
    ~Array();
};

#endif // !ARRAY_HPP
