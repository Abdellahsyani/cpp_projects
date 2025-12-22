#pragma once

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
  private:
    AMateria* _inventory[4];
    std::string name;
  public:
    Character();
    Character(const Character& other);
    Character operator=(const Character& other);
    ~Character();

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};
