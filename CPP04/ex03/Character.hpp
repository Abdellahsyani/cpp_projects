#pragma once

#include <iostream>
#include "ICharacter.hpp"

/**
 * Character: A concrete implementation of the ICharacter interface.
 *    * ROLE:
 *      Acts as the 'Context' in the Strategy Pattern, managing an inventory of 
 *      AMateria objects. It interacts with Materia through the AMateria abstraction,
 *      remaining unaware of concrete types like Ice or Cure (Dependency Inversion).
 *    * RESOURCE MANAGEMENT (Ownership):
 *      This class 'owns' the Materia pointers in its inventory. It is responsible 
 *      for:
 *        1. Deep-copying Materia via clone() during copy/assignment.
 *        2. Deleting all equipped Materia upon destruction to prevent memory leaks.
 *    * CONTRACT:
 *      Implements the ICharacter interface 'contract', ensuring it can be used 
 *      polymorphically by any system expecting an ICharacter reference.
 **/
class Character : public ICharacter {
  private:
    AMateria* _inventory[4];
    std::string _name;
  public:
    Character();
    Character(std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};
