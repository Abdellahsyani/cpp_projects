template <typename T>
Array<T>::Array() : _element(NULL), _n(0) {};


template <typename T>
Array<T>::Array(unsigned int size) : _n(size) {
  _element = new T[size]();
};


template <typename T>
Array<T>::Array(const Array<T> &other) {
  this->_n = other._n;
  if (this->_n > 0) {
    this->_element = new T[other._n]();
    for (unsigned int i = 0; i < other->_n; i++) {
      this->_element[i] = other._element[i];
    }
  } else {
      this->_element = NULL;
    }
  }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    T* tmp = NULL;
    if (this->_n > 0) {
      tmp = new T[other._n]();
      for (unsigned int i = 0; i < other->_n; i++) {
        tmp[i] = other._element[i];
      }
    }
    delete[] this->_element;
    this->_element = tmp;
    this->_n = other._n;
  }
  return *this;
}


template <typename T>
T& Array<T>::operator[](unsigned int idx) {
  if (idx >= _n) {
    throw std::out_of_range("Index out of range");
  }
  return _element[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const {
  if (idx >= _n) {
    throw std::out_of_range("Index out of range");
  }
  return _element[idx];
}

template <typename T>
Array<T>::~Array() { delete[] this->_element; };
