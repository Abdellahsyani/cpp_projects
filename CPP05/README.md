# CPP05 - Repetition and Exceptions 📝

Bureaucrats, forms and grades — a whole module built around throwing and catching exceptions.

## 🧠 Concepts Covered

- Custom exception classes derived from `std::exception`, overriding `what()`
- Nested exception classes inside the class that raises them
- `try` / `catch`, exception safety, and throwing from constructors
- `const` attributes and initialization lists
- Abstract classes revisited (`AForm`) with a template-method style `execute()`
- The Factory pattern (`Intern::makeForm`)

## 📂 Exercises

Grades run from **1 (highest)** to **150 (lowest)**.

### ex00 - `Bureaucrat`
`Bureaucrat` with a `const std::string _name` and an `int _grade`. Constructing or
incrementing/decrementing out of range throws `Bureaucrat::GradeHighException` or
`Bureaucrat::GradeLowException`. `operator<<` prints `<name>, bureaucrat grade <grade>`.

### ex01 - `Bureaucrat` (Form)
Adds `Form`: a const name, a signed flag, and const grades required to sign and to execute.
`Form::beSigned()` throws `GradeTooHighException` when the bureaucrat's grade is insufficient, and
`Bureaucrat::signForm()` reports success or catches and prints the reason.

### ex02 - `AForm`
`Form` becomes the abstract `AForm` with a pure virtual `execute(Bureaucrat const&)` and a shared
`checkRequirements()` helper (throws `AFormNotSignedException` or `GradeTooLowException`).
Three concrete forms:

| Form | Sign | Exec | Effect |
|---|---|---|---|
| `ShrubberyCreationForm` | 145 | 137 | writes ASCII trees to `<target>_shrubbery` |
| `RobotomyRequestForm` | 72 | 45 | drilling noises, robotomizes the target 50% of the time |
| `PresidentialPardonForm` | 25 | 5 | announces a pardon by Zaphod Beeblebrox |

### ex03 - `Intern`
`Intern::makeForm(name, target)` is a factory: it matches the form name against the three known
forms and returns a newly allocated `AForm*`, or reports an unknown form instead of a
long `if`/`else` chain.

## 🛠️ Build & Run

```bash
cd ex00          # or ex01 / ex02 / ex03
make
./Bureaucrat     # ./Bureaucrat, ./AForm, ./Intern
make clean
make fclean
make re
```

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
