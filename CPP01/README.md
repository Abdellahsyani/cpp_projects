# CPP01 - Memory Allocation, References, Pointers to Members 🧠

Stack vs heap, `new`/`delete`, references versus pointers, file streams and switch-driven dispatch.

## 🧠 Concepts Covered

- Allocating objects on the stack versus on the heap and who is responsible for `delete`
- References (`&`) as non-nullable aliases, compared with pointers
- Passing objects by reference to avoid copies
- Arrays of objects allocated with `new[]` / freed with `delete[]`
- File I/O with `<fstream>` and string manipulation (`find`, `substr`)
- Private member functions and pointers to member functions

## 📂 Exercises

### ex00 - `zombie`
`Zombie` class with a name and `announce()`. Two creation strategies:
`newZombie(name)` returns a heap-allocated zombie that outlives the function, while
`randomChump(name)` creates a stack zombie that announces itself and dies at the end of the scope.

### ex01 - `horde`
`zombieHorde(N, name)` allocates an array of `N` zombies in **a single** `new[]` call, names them all,
makes each one announce itself, then the horde is released with `delete[]`.

### ex02 - `ref`
The "HI THIS IS BRAIN" exercise: prints the address of a string, of a pointer to it and of a
reference to it, then the value through each — showing that a reference is just another name
for the same object.

### ex03 - `weapon`
`Weapon` (with `getType()`/`setType()`), `HumanA` which holds a `Weapon&` (weapon always present,
bound at construction) and `HumanB` which holds a `Weapon*` (weapon optional, set later via
`setWeapon()`). Changing the weapon type is reflected in both humans' attacks.

### ex04 - `sed`
A mini `sed -i "s/s1/s2/g"`: reads `<filename>`, replaces every occurrence of `s1` with `s2`
using `find`/`substr` (no `std::string::replace`) and writes the result to `<filename>.replace`.

```bash
./sed file.txt oldWord newWord
```

### ex05 - `harl`
`Harl` complains on four levels — `DEBUG`, `INFO`, `WARNING`, `ERROR` — each implemented as a private
member function. `complain(level)` dispatches to the right one through an array of pointers to
member functions instead of a chain of `if`/`else`.

### ex06 - `harlFilter`
Same Harl, driven from the command line: `./harlFilter <LEVEL>` uses a `switch` to print the
requested level **and every level above it**; an unknown level prints
`[ Probably complaining about insignificant problems ]`.

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 ... ex06
make
./zombie         # ./horde, ./ref, ./weapon, ./sed, ./harl, ./harlFilter
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
