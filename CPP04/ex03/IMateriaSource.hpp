#pragma once

#include <iostream>

//Forward declaration
class AMateria;

/**
 * IMateriaSource: This is an interface, (all methods are pure virtual function)
 *                In this interface we create and learn Materia or (spells) like Ice, Cure ..
 *                and this interface depend on AMateria abstraction
 **/
class IMateriaSource
{
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
