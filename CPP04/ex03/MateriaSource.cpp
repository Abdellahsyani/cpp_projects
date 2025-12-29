#include "MateriaSource.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
MateriaSource::MateriaSource() {
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
 *              fill it or (teach MateriaSource the spell) and save on it's brain
 */
void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < 4; i++)
  {
    if (this->_blueprint[i] == NULL)
    {
      this->_blueprint[i] = m;
      break;
    }
  }
}

/**
 * createMateria: This function loop through _blueprint array and check for
 *              type on it if that array type == type clone() it and return,
 *              by using This method we insure that we don't care about the type of Materia
 *              we just using it mean's (create new spell's)
 *        if not return 0
 */
AMateria* MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++)
  {
    if (this->_blueprint[i] && this->_blueprint[i]->getType() == type)
      return this->_blueprint[i]->clone();
  }
  return 0;
}

/**
 * Destructor: This one used when the program finish
 * 	and calls to free all thing
 */
MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++)
    delete _blueprint[i];
};
