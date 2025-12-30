#include "Cure.hpp"

/**
 * Default Constructor: Initializes a new Cure instance.
 *    * ROLE:
 *        It explicitly calls the parameterized AMateria constructor with "cure".
 *        This ensures that the Materia is correctly identified by the MateriaSource
 *        and Character during polymorphic operations (like createMateria or use).
 *    * NOTE:
 *        Uses an empty body because all necessary state initialization is handled 
 *        through the base class constructor chaining.
 **/
Cure::Cure() : AMateria("cure") {}

/**
 * Copy Constructor: Creates a new Cure instance by duplicating an existing one.
 *    * INHERITANCE:
 *        Uses 'AMateria(other)' in the initializer list. This is called 'Constructor 
 *        Chaining,' ensuring the base class attributes (like the type string) are 
 *        initialized before the derived class body executes.
 *    * BEHAVIOR:
 *        Handles the 'Deep Copy' logic required for Orthodox Canonical Form.
 *      Example: Cure a; Cure b(a);
 **/
Cure::Cure(const Cure& other) : AMateria(other) {}

/**
 * Copy assignment operator: Update an existing Cure instance using another
 *    * LOGIC:
 *        Uses the 'this != other' to prevent self-assignement issues.
 *    * INHERITANCE:
 *        It explicitly calls 'AMateria::operator=' to ensure the base class state
 *        (like the type string) is correctly synchronized before handling
 *        Cure-specific data.
 *    * RETURN:
 *        return a reference to (*this) to support assignment chaining (a = b = c).
 **/
Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

/**
 * use: Executes the Materia's unique behavior on a target.
 *    * LOGIC:
 *        Implements the specific interaction logic for "Cure". It uses the ICharacter 
 *        interface to identify the target, ensuring that this Materia can interact 
 *        with any class that implements the ICharacter contract.
 *    * DESIGN PATTERN (Strategy):
 *        This is the concrete implementation of the Strategy pattern. The Character 
 *        (Context) triggers this behavior without needing to know the specifics 
 *        of how the healing is performed.
 **/
void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
} 

/**
 * clone: The "Prototype" factory method.
 *    * LOGIC:
 *        Creates and returns a NEW heap-allocated instance of the current object.
 *        This allows the MateriaSource to duplicate spells without knowing their 
 *        concrete types (Ice, Cure, etc.), depending only on the AMateria interface.
 *    * DESIGN PATTERN:
 *        This is the Prototype Pattern in action, supporting the Open/Closed Principle
 *        by enabling the system to be extended with new Materia types without 
 *        modifying the Source's creation logic.
 **/
AMateria* Cure::clone() const {
  return new Cure();
}

/**
 * Destructor: Cleans up the Cure instance when its lifetime ends.
 *    * VIRTUAL BEHAVIOR:
 *        Although this body is empty, it is marked virtual in the base class 
 *        (AMateria). This ensures that when a Character deletes an AMateria* * pointing to a Cure object,
 *        the derived destructor is called first, 
 *        preventing partial destruction and memory leaks.
 **/
Cure::~Cure() {};
