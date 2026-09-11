# CPP09 - STL Containers 🗃️

Three programs, each forced to use a different standard container, with heavy input validation.

## 🧠 Concepts Covered

- Choosing the right container: `std::map`, `std::stack`, `std::vector` / `std::deque`
- Parsing files and command-line input with `<fstream>` and `<sstream>`
- Strict validation of dates, numeric ranges and expression syntax
- Functors (`operator()`) combined with `std::for_each`
- Error reporting through exceptions
- Benchmarking with `gettimeofday` and comparing two container implementations

## 📂 Exercises

### ex00 - `btc` (Bitcoin Exchange)
Reads an input file whose header must be `date | value`, and a price database `data.csv`
(`date,exchange_rate`) loaded into a `std::map<std::string, double>`.
For each line it validates the date (year 2008–2026, month 1–12, day 1–31 / max 29 in February)
and the value (`not a positive number` below 0, `too large a number` above 1000), then multiplies
the value by the rate of that date — or, via `std::map::lower_bound`, of the closest earlier date.

```bash
./btc input.txt
```

### ex01 - `RPN` (Reverse Polish Notation)
Evaluates an RPN expression given as a single argument, using a `std::stack<int>`.
`ProcessOperation` is a functor holding a reference to the stack; `std::for_each` runs it over
every character. Digits are pushed, `+ - * /` pop two operands and push the result.
Invalid characters, missing operands, division by zero and leftover operands all raise an error.

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

### ex02 - `PmergeMe` (Ford-Johnson merge-insertion sort)
Sorts a sequence of positive integers twice — once with `std::vector<Node>` and once with
`std::deque<Node>` — and reports the time each container took.

- `Node` pairs a winner with the indices of the elements it beat, plus a possible stray element.
- `makePair()` splits elements into winners and losers; `sortRecursion()` recurses on the winners.
- `FordJohnson()` builds the main chain and inserts the pending elements in Jacobsthal order
  (`getInsertionOrder()` / `getNextJacobsthal()`) using `std::lower_bound`.
- `ComparisonCounter` is a comparison functor that counts every comparison performed.

```bash
./PmergeMe 3 5 9 7 4
```

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02
make
./btc input.txt  # ./RPN "1 2 +", ./PmergeMe 3 5 9 7 4
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
