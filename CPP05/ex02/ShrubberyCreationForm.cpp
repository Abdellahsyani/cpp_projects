#include "ShrubberyCreationForm.hpp"

/**
 * ShrubberyCreationForm: This is constructor responsible about setting the attributes
 *      for any object that created from this class.
 **/
ShrubberyCreationForm::ShrubberyCreationForm() :
  AForm("ShrubberyCreationForm", false, 145, 137) {}

  /**
   * ShrubberyCreationForm: This is a parametrize constructor to init the attributes
   *        without need for setters
   *    - ROLE:
   *          we use exception here to check if ShrubberyCreationForm enter's some high or low Grade
   *          and throw an error.
   **/
  ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("ShrubberyCreationForm", 145, 137) {}

    /**
     * ShrubberyCreationForm: a copy constructor to create an instance from another
     **/
    ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
      AForm(other), _target(other._target) {}

      /**
       * ShrubberyCreationForm: A copy assignement operator
       *   - USAGE:
       *        This override an existing instance with another one
       **/
      ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
        if (this != &other)
        {
          AForm::operator=(other);
          this->_target = other._target;
        }
        return (*this);
      }

/***/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  this->checkRequirements(executor);
  std::string filename = _target + "_shrubbery"; 
  std::ofstream outfile(filename.c_str());

  if (!outfile.is_open())
  {
    std::cerr << "File is not open!" << std::endl;
    return;
  }
  outfile << "          &&& &&  & &&" << std::endl;
  outfile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
  outfile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
  outfile << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
  outfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
  outfile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
  outfile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
  outfile << "      &&     \\|||" << std::endl;
  outfile << "             |||" << std::endl;
  outfile << "             |||" << std::endl;
  outfile << "             |||" << std::endl;
  outfile << "        , -=-~  .-^- _" << std::endl;
  outfile.close();
}

/**
 * ~Form:: The destructor responsible for cleaning the memory
 **/
ShrubberyCreationForm::~ShrubberyCreationForm() {};
