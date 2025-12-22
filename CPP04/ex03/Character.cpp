#include "Character.hpp"


/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Character::Character() {
    std::cout << "Character Default Constructor called" << std::endl;
    name = "Character";
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 */
Character::Character(const Character& other) {
	std::cout << "Character Copy constructor called" << std::endl;
	this->name = other.name;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 */
Character& Character::operator=(const Character& other) {
	std::cout << "Character Copy assignement constructor called" << std::endl;
	if (this != &other)
		this->name = other.name;
	return (*this);
}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Character::~Character() { std::cout << "Character Destructor called" << std::endl; };
