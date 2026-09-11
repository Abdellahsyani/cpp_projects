# CPP07 - C++ Templates 🧩

Writing type-independent code: function templates, higher-order templates and a class template.

## 🧠 Concepts Covered

- Function templates and template argument deduction
- Higher-order functions: passing a function or functor as a template parameter
- Class templates, with the implementation split into a `.tpp` included by the header
- Templates and operator overloading (`operator[]`)
- Throwing `std::out_of_range` on invalid indices
- Deep copy semantics for a templated container

## 📂 Exercises

### ex00 - `ex00` (Start with a few functions)
`template.hpp` defines three function templates usable with any type that supports comparison
and assignment: `swap(T&, T&)`, `min(T, T)` and `max(T, T)` (both return the second argument
when the values are equal). `main` exercises them with `int` and `std::string`.

### ex01 - `ex01` (iter)
`iter(Array* arr, size_t len, F func)` applies `func` to each element of an array.
The array type and the callable are both template parameters, so it works with any element type
and with functions, function templates or functors — array traversal is decoupled from the logic.

### ex02 - `ex02` (Array)
`Array<T>`, a dynamically allocated container:

- `Array()` — empty array, no allocation
- `Array(unsigned int n)` — `n` elements value-initialized with `new T[n]()`
- Copy constructor and assignment operator performing a deep copy (modifying a copy never
  affects the original)
- `operator[]` in const and non-const versions, throwing `std::out_of_range` when the index
  is past the end
- Element count kept privately alongside the buffer; memory released with `delete[]`

Implementation lives in `Array.tpp`, included at the bottom of `Array.hpp`.

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02
make
./ex00           # ./ex01, ./ex02
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
