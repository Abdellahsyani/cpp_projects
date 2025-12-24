
#include "MateriaSource.hpp"

/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
MateriaSource::MateriaSource() {
    std::cout << "MateriaSource Default Constructor called" << std::endl;
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource Copy constructor called" << std::endl;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
MateriaSource MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource Copy assignement constructor called" << std::endl;
	return (*this);
}


void MateriaSource::learnMateria(AMateria* ma) {
  
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
MateriaSource::~MateriaSource() { std::cout << "MateriaSource Destructor called" << std::endl; };
