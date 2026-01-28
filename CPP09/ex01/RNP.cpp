#include "RNP.hpp"


/**
 * @brief Constructor for the functor.
 *  *Capture a reference to an external stack, this allows the functor
 *  maintain state and modify the original stack during the execution of algorithms like std::for_each. 
 * @param container reference to the stack where operands and results are stored.
 **/
ProcessOperation::ProcessOperation(std::stack<int>& container) : _container(container) {};

/**
 * @brief Validates if a character is a supported RNP operator.
 *
 * @param c: The character to check
 * @return true if c is '+', '*', '/', or '-' ; false otherwise
 **/
bool ProcessOperation::CheckOp(char c) {
  if (c == '*' || c == '-' || c == '/' || c == '+') {
    return true;
  }
  return false;
}

/**
 * @brief Primary logic execution (Function Call Operator).
 * * This method is called automatically by std::for_each for every character
 * in the input string. It performs three main tasks:
 * 1. Validation: Ensures the character is a digit, space, or valid operator.
 * 2. Operand Storage: Converts digit chars to integers and pushes them to the stack.
 * 3. Operation Execution: Pops the last two operands, applies the operator, 
 * and pushes the result back.
 * @param c The current character from the input stream.
 * @throws std::invalid_argument If an illegal character is encountered.
 * @throws std::runtime_error If an operator is found with fewer than 2 operands on the stack.
 */
void ProcessOperation::operator()(char c) {
  if (!isspace(c) && !isdigit(c) && CheckOp(c) == false)
    throw std::invalid_argument("Invalid input");
  if (isspace(c)) {
    return;
  }
  if (isdigit(c)) {
    _container.push(c - '0');
  }
  if (CheckOp(c)) {
    if (_container.size() < 2) {
      throw std::runtime_error("Not enough operands");
    }
    int right = _container.top();
    _container.pop();
    int left = _container.top();
    _container.pop();
    if (c == '*'){
      _container.push(left * right);
    }
    if (c == '-'){
      _container.push(left - right);
    }
    if (c == '+'){
      _container.push(left + right);
    }
    if (c == '/'){
      if (right == 0)
        throw std::runtime_error("Division by zero");
      _container.push(left / right);
    }
  }
}
