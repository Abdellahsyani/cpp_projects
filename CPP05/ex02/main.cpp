#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main()
{
  try {
    Bureaucrat b("abdo", 1);
    Form f("Back-end developer", 3, 4);

    b.signForm(f);
    f.beSigned(b);
    std::cout << f << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::cout << "-----------------------------------------" << std::endl;

  try {
    Bureaucrat b("abdo", 13);
    Form f("Software engineer", 3, 4);

    b.signForm(f);
    std::cout << f << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
