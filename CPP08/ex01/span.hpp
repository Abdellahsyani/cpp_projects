#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

/**
 * Span: */
class Span {
private:
  unsigned int _n;
  std::vector<int> _vec;

public:
  Span();
  Span(unsigned int n);
  Span(const Span &other);
  Span& operator=(const Span &other);
  ~Span();

  void addNumber(unsigned int n);
  long shortestSpan();
  long longestSpan();
  void bunchOfNumber(unsigned int range);

  class SpanNumberNotEnough : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "Error: Not enough numbers to find a span";
    }
  };

};


#endif // !SPAN_HPP
