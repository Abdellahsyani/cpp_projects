# CPP02 - Ad-hoc Polymorphism, Operator Overloading, Canonical Form ➗

Building a fixed-point number type that behaves like a built-in type.

## 🧠 Concepts Covered

- **Orthodox Canonical Form**: default constructor, copy constructor, copy assignment operator, destructor
- Fixed-point representation: an `int` storing the value shifted left by 8 fractional bits
- Conversion constructors (`int`, `float`) and conversion methods (`toInt()`, `toFloat()`)
- Operator overloading: stream insertion, comparison, arithmetic, increment/decrement
- Static member functions and `const`-correct overloads

## 📂 Exercises

### ex00 - `Fixed`
The minimal `Fixed` class: a private `int Fixedpoint` plus `static const int frac_bit = 8`,
the four canonical member functions (each printing a message so the calls are observable), and
`getRawBits()` / `setRawBits()`.

### ex01 - `FixedP`
Adds constructors from `int` and from `float` (value shifted by `frac_bit`, rounded with `roundf`),
the `toInt()` / `toFloat()` conversions, and `operator<<` so a `Fixed` can be printed directly.

### ex02 - `FixedPoint`
Completes the type with the full operator set (`operator.cpp`):

- Comparison: `>`, `<`, `>=`, `<=`, `==`, `!=`
- Arithmetic: `+`, `-`, `*`, `/`
- Pre/post increment and decrement, stepping by the smallest representable ε
- Static `min()` / `max()` in both non-const and const overloads

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02
make
./Fixed          # ./FixedP, ./FixedPoint
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
