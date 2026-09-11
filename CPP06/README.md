# CPP06 - C++ Casts 🎭

The four C++ cast operators, pointer serialization and runtime type identification.

## 🧠 Concepts Covered

- `static_cast` for well-defined conversions between related types
- `reinterpret_cast` for bitwise reinterpretation of addresses
- `dynamic_cast` and RTTI for safe downcasting
- Non-instantiable classes (private canonical form, only static members)
- Handling special floating-point values (`nan`, `inf`) and pseudo-literals
- `uintptr_t`: an integer type guaranteed to hold a pointer

## 📂 Exercises

### ex00 - `scalar` (ScalarConverter)
`ScalarConverter::convert(std::string)` is a static method on a non-instantiable class.
It parses the literal, detects garbage input and pseudo-literals (`nan`, `nanf`, `+inf`, `-inf`,
`+inff`, `-inff`), then prints the value cast to the four scalar types:

```bash
./scalar 42
char: '*'
int: 42
float: 42.0f
double: 42.0
```

Impossible conversions print `impossible`, and non-displayable characters print
`Non displayable`.

### ex01 - `Serializer`
`Data` is a plain struct (`int n; float f; char c;`). `Serializer` is a static-only class with
`serialize(Data*) -> uintptr_t` and `deserialize(uintptr_t) -> Data*`, both implemented with
`reinterpret_cast`. `main` verifies the round-trip returns the original address and that the
fields are unchanged.

### ex02 - `dynamic` (Identify real type)
`Base` is a polymorphic base (virtual destructor) with empty children `A`, `B` and `C`.

- `generate()` randomly allocates one of `A`, `B`, `C` and returns it as a `Base*`.
- `identify(Base* p)` uses pointer `dynamic_cast`, which yields `NULL` on failure.
- `identify(Base& p)` uses reference `dynamic_cast` inside `try`/`catch`, since a failed
  reference cast throws `std::bad_cast`.

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02
make
./scalar 42.0f   # ./Serializer, ./dynamic
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
