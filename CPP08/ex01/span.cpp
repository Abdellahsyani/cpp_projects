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


/**
 * addNumber: A member function that add numbers to the span vector
 * @param n: the number that will be added 
 **/
void Span::addNumber(unsigned int n) {
  if (this->_vec.size() >= this->_n)
    throw std::out_of_range("Span is full!");
  this->_vec.push_back(n);
};

/**
 * bunchOfNumber: A member function that add a bunch of numbers to span vector at ones
 * @param range: the range that will add numbers from
 **/
void Span::bunchOfNumber(unsigned int range) {
  if (this->_vec.size() >= this->_n)
    throw std::out_of_range("Span is full!");
  _vec.reserve(_n);
  for (unsigned int i = _vec.size(); i < _n; i++) {
    _vec.push_back(rand() % range);
  }
};

/**
 * shortestSpan: The function that find the shortest span in the vector
 *
 * return : the shortest one when find it
 **/
long Span::shortestSpan() {
    if (_vec.size() < 2)
        throw Span::SpanNumberNotEnough();
    
    std::sort(_vec.begin(), _vec.end());

    long minSpan = -1;
    for (size_t i = 0; i < _vec.size() - 1; i++) {
        long currentDiff = static_cast<long>(_vec[i + 1]) - static_cast<long>(_vec[i]);
        
        if (minSpan == -1 || currentDiff < minSpan)
          minSpan = currentDiff;
    }
    return minSpan;
}

/**
 * longestSpan: A function that rerurn the longest Span in the vector 
 **/
long Span::longestSpan() {
  if (_vec.size() < 2)
    throw Span::SpanNumberNotEnough();
  std::sort(_vec.begin(), _vec.end());
  return (static_cast<long>(_vec.back()) - static_cast<long>(_vec.front()));
};


/**
 * Destructor: to clean up all trash
 **/
Span::~Span() {};
