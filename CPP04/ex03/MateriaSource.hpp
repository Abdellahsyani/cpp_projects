#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria* ma);
    AMateria* createMateria(std::string const & str);
};
