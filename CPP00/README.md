# CPP00 - Introduction to C++ 🚀

Namespaces, classes, member functions, stdio streams, initialization lists, `static` and `const`.
This module is the first contact with C++ syntax after C: standard streams (`std::cout`, `std::cin`),
`std::string`, encapsulation with getters/setters, and class-wide (static) state.

## 🧠 Concepts Covered

- `std::string` and the iostream library (`std::cout`, `std::cin`, `std::endl`)
- Classes, access specifiers, constructors and destructors
- Getters / setters and encapsulation of private attributes
- Static members and static member functions (data shared by all instances)
- Output formatting with `<iomanip>` (`std::setw`, truncation to fixed-width columns)

## 📂 Exercises

### ex00 - `megaphone`
A command-line program that prints all its arguments converted to uppercase.
With no arguments it prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.

```bash
./megaphone "shhhhh... I think the students are asleep..."
```

### ex01 - `phone` (My Awesome PhoneBook)
An interactive phonebook holding **8 contacts** in a fixed array (no dynamic allocation).

- `Contact` (`contact.hpp`/`contact.cpp`): first name, last name, nickname, phone number and
  darkest secret, with one getter/setter per field.
- `PhoneBook` (`phonebook.hpp`/`phonebook.cpp`): holds `Contact contacts[8]` and a `static int counter`;
  oldest contact is overwritten once the book is full.
- Commands: `ADD` (prompts for every field), `SEARCH` (prints the index/first name/last name/nickname
  table, then the full contact for a chosen index) and `EXIT`.
- `phone_helper.cpp`: input validation, `simple_atoi`, and `format_column()` which pads/truncates
  fields to 10 characters with a trailing `.`.

### ex02 - `account` (Ford-A-Car / Account class)
Reimplementation of `Account.cpp` from the provided `Account.hpp` and log file.
The class tracks per-account state (`_accountIndex`, `_amount`, `_nbDeposits`, `_nbWithdrawals`) and
bank-wide static state (`_nbAccounts`, `_totalAmount`, `_totalNbDeposits`, `_totalNbWithdrawals`).
Running `./account` must reproduce `19920104_091532.log` (timestamps aside).

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02
make             # build
./megaphone      # ./phone, ./account
make clean       # remove object files
make fclean      # remove object files and the executable
make re          # rebuild from scratch
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
