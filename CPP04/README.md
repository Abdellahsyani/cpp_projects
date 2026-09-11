# CPP04 - Subtype Polymorphism, Abstract Classes, Interfaces 🐾

Virtual functions, deep copies, pure virtual classes and interface-based design.

## 🧠 Concepts Covered

- `virtual` member functions and dynamic dispatch through base pointers
- Virtual destructors, and what breaks without them
- Deep copy of a heap-allocated member (rule of three in practice)
- Abstract classes (`= 0`) that cannot be instantiated
- Interfaces: classes made only of pure virtual functions
- The Prototype pattern via `clone()`

## 📂 Exercises

### ex00 - `animal`
`Animal` base class with `virtual void makeSound() const`, plus `Dog` and `Cat` overriding it.
`WrongAnimal`/`WrongCat` are the same hierarchy **without** `virtual`, so calling `makeSound()`
through a `WrongAnimal*` runs the base implementation — the contrast that makes dynamic dispatch obvious.

### ex01 - `animal` (Brain)
`Brain` holds `std::string ideas[100]`. `Dog` and `Cat` each own a `Brain*` allocated with `new`
in the constructor and released in the destructor. The copy constructor and assignment operator
perform a **deep copy**, so copies own independent brains. `main` fills an array of `Animal*`
with half dogs and half cats and deletes them all through the base pointer.

### ex02 - `abstract`
`Animal::makeSound()` becomes pure virtual (`= 0`), turning `Animal` into an abstract class:
instantiating it no longer compiles, while `Dog` and `Cat` still work polymorphically.

### ex03 - `interface` (Interface & Recap)
A small materia/spell system:

- `AMateria`: abstract base with `getType()`, pure virtual `clone()` and `use(ICharacter&)`.
- `Ice` and `Cure`: concrete materias printing their effect and implementing `clone()`.
- `ICharacter` / `IMateriaSource`: pure interfaces.
- `Character`: owns an inventory of 4 `AMateria*`, deep-copies it via `clone()`, `unequip()`
  drops a materia without deleting it, and the destructor frees everything it still holds.
- `MateriaSource`: learns up to 4 materia templates and creates new ones by name (`createMateria`).

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02 / ex03
make
./animal         # ./animal, ./abstract, ./interface
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
