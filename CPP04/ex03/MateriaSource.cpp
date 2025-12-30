#include "MateriaSource.hpp"

/**
 * Default Constructor: Initializes the Materia "Vault".
 * - ROLE: Clears the _blueprint array to NULL.
 * - Why: Ensures the Source starts empty and prevents undefined behavior 
 * when checking slots for the first time.
 */
MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    _blueprint[i] = NULL;
}

/**
 * Copy Constructor: Duplicates the entire Source library.
 * - DEEP COPY: Uses AMateria::clone() to create new instances of stored 
 * blueprints. This ensures the new Source has its own unique memory 
 * independent of the original.
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
 * Copy Assignment Operator: Replaces current library with another.
 * - CLEANUP: Must delete existing blueprints first to prevent memory leaks.
 * - SAFETY: Includes a self-assignment guard (this != &other).
 * - CLONING: Performs a deep copy of all valid blueprints from 'other'.
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
 * learnMateria: Stores a "Master Copy" (Blueprint) of a spell.
 * - OWNERSHIP: The MateriaSource takes full ownership of the pointer 'm'.
 * - BRAIN: Stores up to 4 blueprints. Once a slot is filled, it acts as 
 * the template for all future creations.
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
 * createMateria: Manufactures a new spell instance from a stored blueprint.
 * - POLYMORPHISM: Searches the 'brain' for a matching type.
 * - PROTOTYPE PATTERN: Calls clone() on the blueprint to return a fresh 
 * heap-allocated copy. The original blueprint remains in the Source.
 * - RETURN: Returns the new Materia pointer, or 0 if the type is unknown.
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
 * Destructor: Cleans up the Source's internal library.
 * - RESPONSIBILITY: Deletes all 4 "Master Copy" Materias to ensure 
 * a clean exit with zero memory leaks in Valgrind.
 */
MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++)
    delete _blueprint[i];
};
