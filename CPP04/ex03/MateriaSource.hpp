#pragma once

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// Forward declaration
class AMateria;


/**
 * MateriaSource: A concret class that Implementing IMateriaSource interface
 * **/
class MateriaSource : public IMateriaSource {
  private:
    AMateria* _blueprint[4];
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria* ma);
    AMateria* createMateria(std::string const & str);
};
