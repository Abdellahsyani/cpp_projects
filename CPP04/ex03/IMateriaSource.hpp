#pragma once

#include <iostream>

//Forward declaration
class AMateria;

/**
 * IMateriaSource: A pure interface acting as a Factory for AMateria.
 *  ** ROLE:
 *        Defines the contract for a "Materia generator." It allows the system to 
 *        store blueprints (learn) and manufacture new instances (create).
 *  ** DESIGN PATTERN (Abstract Factory):
 *        By using this interface, the High-Level logic remains decoupled from the 
 *        concrete magic types. It depends entirely on the AMateria abstraction.
 *  ** MEMORY MANAGEMENT:
 *        Implementing classes are responsible for managing the memory of learned 
 *        blueprints and ensuring cloned Materias are returned for character use.
 **/
class IMateriaSource
{
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
