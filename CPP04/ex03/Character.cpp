#include "Character.hpp"
#include "AMateria.hpp"


/**
 * Default Constructor: Initializes a Character with a default name.
 * - Ensures all inventory slots are initialized to NULL to prevent 
 * accessing indeterminate memory.
 */
Character::Character() : _name("Character") {
  for (int i = 0; i < 4; i++)
    _inventory[i] = NULL;
}

/**
 * Parameterized Constructor: Initializes a Character with a specific name.
 * - Sets the internal _name and clears the inventory slots.
 */
Character::Character(std::string name) : _name(name) {
  for (int i = 0; i < 4; i++)
    _inventory[i] = NULL;
}

/**
 * Copy Constructor: Performs a Deep Copy of an existing Character.
 *  - ROLE: Creates a new object by duplicating the name and cloning 
 *          each Materia in the inventory.
 *  - MEMORY: Uses AMateria::clone() to ensure the new Character owns 
 *          distinct memory from the original, preventing double-free errors.
 */
Character::Character(const Character& other) {
  for (int i = 0; i < 4; i++)
  {
    if (other._inventory[i] == NULL)
      this->_inventory[i] = NULL;
    else
      this->_inventory[i] = other._inventory[i]->clone();
  }
  this->_name = other._name;
}

/**
 * Copy Assignment Operator: Replaces current state with a Deep Copy of another.
 * - SELF-ASSIGNMENT: Guarded by (this != &other).
 * - CLEANUP: Deletes existing Materia before copying to prevent memory leaks.
 * - CLONING: Uses the Prototype pattern (clone()) to duplicate Materia.
 */
Character& Character::operator=(const Character& other) {
  if (this != &other)
  {
    for (int i = 0; i < 4; i++)
    {
      if (this->_inventory[i])
      {
        delete _inventory[i];
        this->_inventory[i] = NULL;
      }
    }
    for (int i = 0; i < 4; i++)
    {
      if (other._inventory[i] == NULL)
        this->_inventory[i] = NULL;
      else
      {
        this->_inventory[i] = other._inventory[i]->clone();
      }
    }
    this->_name = other._name;
  }
  return (*this);
}

/**
 * getName: Returns the Character's name by constant reference.
 */
std::string const& Character::getName() const {
  return this->_name;
}

/**
 * equip: Adds a Materia to the first available slot.
 * - OWNERSHIP: Once equipped, the Character takes ownership of the pointer.
 * - CONSTRAINTS: Fills slots 0 to 3. If full, the Materia is ignored.
 */
void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++)
  {
    if (this->_inventory[i] == NULL)
    {
      this->_inventory[i] = m;
      break;
    }
  }
}

/**
 * unequip: Removes a Materia from the inventory without deleting it.
 * - IMPORTANT: The address is set to NULL so the Character no longer "owns" it.
 * - LEAK PREVENTION: The pointer must be saved externally before calling this 
 * to avoid a memory leak.
 */
void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        return;
    }
    this->_inventory[idx] = NULL;
}

/**
 * use: Triggers the Materia's effect on a target.
 * - POLYMORPHISM: Calls the virtual AMateria::use method.
 * - SAFETY: Checks if index is valid and slot is not empty.
 */
void Character::use(int idx, ICharacter& target)
{
  if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
    this->_inventory[idx]->use(target);
  else
    std::cout << "Index Or target is not valid" << std::endl;
}

/**
 * Destructor: Cleans up all resources owned by the Character.
 * - Ensures all heap-allocated Materia in the inventory are deleted.
 */
Character::~Character() {
  for (int i = 0; i < 4; i++)
    delete _inventory[i];
};
