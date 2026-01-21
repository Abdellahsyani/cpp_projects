#include "span.hpp"

/**
 * Default Constructor: setting _n to 0
 */
Span::Span() : _n(0) {};

/**
 * Parametrize Constructor: init private attributes at creation time
 */
Span::Span(unsigned int n) : _n(n) {};

/**
 * Copy Constructor: used to copy an instance from an existing one.
 */
Span::Span(const Span& other) : _n(other._n), _vec(other._vec) {};

/**
 * Copy assignment Constructor: copy or assign an instance from an existing one.
 */
Span& Span::operator=(const Span& other) {
  if (this != &other) {
    this->_vec = other._vec;
    this->_n = other._n;
  }
  return *this;
};


/***/
void Span::addNumber(unsigned int n) {
  if (this->_vec.size() >= this->_n)
    throw std::out_of_range("Span is full!");
  this->_vec.push_back(n);
};

/***/
void Span::bunchOfNumber(unsigned int range) {
  for (unsigned int i = 0; i < _n; i++) {
    unsigned int num = rand() % range;
    _vec.push_back(num);
  }
};

/***/
int Span::shortestSpan() {
  if (_vec.size() < 2)
    throw Span::SpanNumberNotEnough();
  std::sort(_vec.begin(), _vec.end());

  std::vector<int> diffs(_vec.size());
  std::adjacent_difference(_vec.begin(), _vec.end(), diffs.begin());

  return *std::min_element(diffs.begin() + 1, diffs.end());
};

/***/
int Span::longestSpan() {
  if (_vec.size() < 2)
    throw Span::SpanNumberNotEnough();
  std::sort(_vec.begin(), _vec.end());
  return (_vec.back() - _vec.front());
};


/***/
Span::~Span() {};
