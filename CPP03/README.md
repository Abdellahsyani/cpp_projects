# CPP03 - Inheritance 🤖

The ClapTrap family: single inheritance, constructor/destructor chaining and the diamond problem.

## 🧠 Concepts Covered

- Base and derived classes, `public` inheritance
- `protected` attributes shared with derived classes
- Order of construction and destruction along an inheritance chain
- Calling a base constructor from a derived initialization list
- Function hiding vs overriding
- Multiple and **virtual** inheritance, and the diamond problem

## 📂 Exercises

### ex00 - `clap`
`ClapTrap` with a name, hit points, energy points and attack damage.
`attack()`, `takeDamage()` and `beRepaired()` each consume energy and refuse to act once
hit points or energy points reach zero.

### ex01 - `Scav`
`ScavTrap : public ClapTrap` with its own stats, its own `attack()` message and the extra
`guardGate()` mode. `ClapTrap` attributes become `protected` so the child can use them, and the
construction/destruction messages show the base-then-derived ordering.

### ex02 - `Frag`
Adds `FragTrap : public ClapTrap` (high hit points) with `highFivesGuys()`, alongside `ScavTrap`.

### ex03 - `diamond`
`DiamondTrap : public ScavTrap, public FragTrap` — `ScavTrap` and `FragTrap` inherit **virtually**
from `ClapTrap` so only one `ClapTrap` sub-object exists. `DiamondTrap` keeps its own `name`
attribute, uses `ScavTrap::attack()`, and `whoAmI()` prints both its name and its ClapTrap name.

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02 / ex03
make
./clap           # ./Scav, ./Frag, ./diamond
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
