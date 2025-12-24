#include "MateriaSource.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
MateriaSource::MateriaSource() {
  std::cout << "MateriaSource Default Constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    _blueprint[i] = NULL;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 *  	- The copy constructor apply the deep copy to avoid shallow copy
 *  	  if we don't use deep copy we will occure memory leak.
 */
MateriaSource::MateriaSource(const MateriaSource& other) {
  std::cout << "MateriaSource Copy constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (other._blueprint[i] == NULL)
      this->_blueprint[i] = NULL;
    else
      this->_blueprint[i] = other._blueprint[i]->clone();
  }
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 *  - This copy assignment implement the deep copy to avoid shallow copy
 *    because shallow copy let leaks
 */
MateriaSource MateriaSource::operator=(const MateriaSource& other) {
  std::cout << "MateriaSource Copy assignement constructor called" << std::endl;
  if (this != &other)
  {
    for (int i = 0; i < 4; i++)
    {
      if (this->_blueprint[i])
      {
        delete _blueprint[i];
        this->_blueprint[i] = NULL;
      }
    }
    for (int i = 0; i < 4; i++)
    {
      if (other._blueprint[i] == NULL)
        this->_blueprint[i] = NULL;
      else
      {
        this->_blueprint[i] = other._blueprint[i]->clone();
      }
    }
  }
  return (*this);
}

/**
 * learnMateria; This function check if there some empty slot in _blueprint array
 *  fill it with m pointer
 *  if all slots are full dont do anything
 *  I set continue to avoid an unexpected bugs
 */
void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < 4; i++)
  {
    if (this->_blueprint[i] == NULL)
      this->_blueprint[i] = m;
    else
     continue;
  }
}

/**
 * createMateria: This function check the type if it is cure or ice allocate and return it
 *        if not return 0
 */
AMateria* MateriaSource::createMateria(std::string const &type) {
  if (type == "Ice")
    return new Ice; 
  if (type == "Cure")
    return new Cure; 
  return 0;
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
MateriaSource::~MateriaSource() { std::cout << "MateriaSource Destructor called" << std::endl; };
