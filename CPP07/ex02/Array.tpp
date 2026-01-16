template <typename T>
Array<T>::Array() : _element(NULL), _n(0) {};


template <typename T>
Array<T>::Array(unsigned int size) : _n(size) {
  _element = new T[size]();
};


template <typename T>
Array<T>::Array(const Array &other) {
  this->_n = other._n;
  for (unsigned int i = 0; i < this->_n; i++)
  {
    if (this->_n > 0) {
      this->_element = new T[_n]();
      this->_element[i] = other._element[i];
    }
    else {
      this->_element = NULL;
    }
  }
}

template <typename T>
Array& Array<T>::operator=(const Array &other) {
  if (other != &other) {
    delete[] this->_element;

    this->_n = other._n;
    if (this->_n > 0) {
      this->_element = new T[_n]();
      for (int i = 0; i < this->_n; i++)
      {
        this->_element[i] = other._element[i];
      }
    }
    else {
      this->_element = NULL;
    }
  }
  return *this;
}


template <typename T>
Array& Array<T>::operator[](Array &other) {

}


template <typename T>
Array<T>::~Array() { delete[]; };
