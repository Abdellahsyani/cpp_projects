# CPP08 - Templated Containers, Iterators, Algorithms 📦

Using the STL: generic algorithms, iterator-based interfaces and extending a container adapter.

## 🧠 Concepts Covered

- STL sequence containers (`std::vector`, `std::list`, `std::deque`) and `std::stack`
- Iterators, `typename` for dependent types (`typename T::iterator`)
- Standard algorithms: `std::find`, `std::sort`
- Writing templates that accept any container instead of one concrete type
- Custom exceptions for invalid container states
- Inheriting from a container adapter to expose its underlying container

## 📂 Exercises

### ex00 - `easy` (easyfind)
`easyfind(T& container, int n)` is a function template that searches any container of `int`
with `std::find` and returns the iterator to the first match, or throws
`std::runtime_error("Value not found")`. `main` tests it with a `vector`, a `list` and a `deque`.

### ex01 - `span` (Span)
`Span` stores up to `N` integers in a `std::vector<int>`:

- `addNumber()` throws `std::out_of_range` when the span is already full
- `bunchOfNumber(range)` fills the span with many numbers in one call
- `shortestSpan()` / `longestSpan()` sort a copy of the numbers to return the smallest and
  largest distance between two of them, and throw `SpanNumberNotEnough` when fewer than two
  numbers are stored

### ex02 - `stack` (MutantStack)
`MutantStack<T> : public std::stack<T>` exposes the iterators of the protected underlying
container `c`, adding `begin()` / `end()` and an `iterator` typedef. The stack therefore keeps
LIFO behaviour while becoming traversable and usable with STL algorithms; `main` compares its
output with the equivalent `std::list`.

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02
make
./easy           # ./span, ./stack
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
