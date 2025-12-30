#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

/**
 * Cure: A concrete implementation of the AMateria abstraction.
 *  ** ROLE:
 *      Provides the specific logic for "healing" spells. It acts as a concrete 
 *      product in the Materia system.
 *  ** DESIGN PATTERN (Prototype):
 *      Implements the clone() method to allow polymorphic duplication. This 
 *      satisfies the Open/Closed Principle: you can add new Materia types 
 *      without changing the MateriaSource or Character logic.
 *  ** COUPLING:
 *      By depending on the ICharacter interface rather than a specific class, 
 *      it achieves loose coupling, allowing the spell to target any entity 
 *      that implements the ICharacter contract.
 **/
class Cure : public AMateria { 
public:
	Cure();
	Cure(const Cure &other);
	Cure& operator=(const Cure &other);
	~Cure();

	void use(ICharacter& target);
	AMateria* clone() const;
};
