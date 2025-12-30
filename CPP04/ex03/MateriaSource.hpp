#pragma once

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// Forward declaration
class AMateria;

/**
 * MateriaSource: A concrete implementation of the IMateriaSource interface.
 *    * ROLE:
 *        Acts as a "Materia Factory." It maintains a library of up to 4 AMateria 
 *        'blueprints' which serve as templates for creating new spells.
 *    * ARCHITECTURE:
 *      - learnMateria: Populates the internal library with a master copy of a Materia.
 *      - createMateria: Searches the library for a matching type and returns a 
 *        freshly cloned instance (Prototype Pattern).
 *    * DECOUPLING:
 *        By interacting only with the AMateria abstraction, this class satisfies 
 *        the Dependency Inversion Principle, as it remains unaware of specific 
 *        Materia implementations (like Ice or Cure).
 **/
class MateriaSource : public IMateriaSource {
  private:
    AMateria* _blueprint[4];
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria* ma);
    AMateria* createMateria(std::string const & str);
};
