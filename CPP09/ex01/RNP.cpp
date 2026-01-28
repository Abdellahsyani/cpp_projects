#include "RNP.hpp"

//$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

/***/
ProcessOperation::ProcessOperation(std::stack<int>& container) : _container(container) {};

/***/
void ProcessOperation::operator()(char c) {

}
