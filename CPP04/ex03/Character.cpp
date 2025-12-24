#include "Character.hpp"
#include "AMateria.hpp"


/**
 * Default Constructor: This called when an object created
 *  - does not take any parameter
 */
Character::Character() {
  std::cout << "Character Default Constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    _inventory[i] = NULL;
  name = "Character";
}

/**
 * Copy Constructor: This one copy all members from an object to another one that created in the same time
 *  - Happens only when the object is being created
 *  	- behavior: b,a(b)
 *  	- The copy constructor apply the deep copy to avoid shallow copy
 *  	  if we don't use deep copy we will occure memory leak.
 */
Character::Character(const Character& other) {
  std::cout << "Character Copy constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (other._inventory[i] == NULL)
      this->_inventory[i] = NULL;
    else
      this->_inventory[i] = other._inventory[i]->clone();
  }
  this->name = other.name;
}

/**
 * Copy assignment Constructor: This type of constructor create an object from an existing one
 *  - so it behaves like this: a, b, a = b
 *  - This copy assignment implement the deep copy to avoid shallow copy
 *    because shallow copy let leaks
 */
Character Character::operator=(const Character& other) {
  std::cout << "Character Copy assignement constructor called" << std::endl;
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
    this->name = other.name;
  }
  return (*this);
}

/**
 * equip; This function check if there some empty slot in _inventory array
 *  fill it with m pointer
 *  if all slots are full dont do anything
 *  I set continue to avoid an unexpected bugs
 */
void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++)
  {
    if (this->_inventory[i] == NULL)
      this->_inventory[i] = m;
    else
     continue;
  }
}

/**
 * unequip: This function loop through the _inventory array and check if the idx
 *          is not equal NULL delete it 
 */
void Character::unequip(int idx) {
  for (int i = 0; i < 4; i++)
  {
    if (i == idx)
    {
      if (this->_inventory[i] != NULL)
        delete this->_inventory[i];
    }
  }
}

/***/
void Character::use(int idx, ICharacter& target)
{

}

/**
 * Destructor: THis one used when the program finish
 * 	and calls to free all thing
 */
Character::~Character() { std::cout << "Character Destructor called" << std::endl; };
