# C++ Projects - Object-Oriented Programming Journey

Welcome to my C++ learning repository! This project is dedicated to mastering Object-Oriented Programming (OOP) concepts using C++.

## 📚 About

This repository contains a series of C++ modules (CPP00 through CPP09) that progressively explore fundamental and advanced OOP concepts. Each module includes multiple exercises designed to build a solid foundation in C++ programming.

## 🗂️ Repository Structure

```
cpp_projects/
├── CPP00/          # Module 00 - Introduction to C++
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── CPP01/          # Module 01 - Memory allocation, references, pointers
├── CPP02/          # Module 02 - Ad-hoc polymorphism, operators overloading
├── CPP03/          # Module 03 - Inheritance
├── CPP04/          # Module 04 - Subtype polymorphism, abstract classes, interfaces
├── CPP05/          # Module 05 - Repetition and exceptions
├── CPP06/          # Module 06 - C++ casts and serialization
├── CPP07/          # Module 07 - C++ templates
├── CPP08/          # Module 08 - Templated containers, iterators, algorithms
└── CPP09/          # Module 09 - STL containers
```

Every module folder has its own `README.md` detailing each exercise.

## 🎯 Learning Objectives

Throughout these modules, I'm learning and practicing:

- **Basic C++ Syntax**: Understanding fundamental C++ constructs
- **Classes and Objects**: Implementing OOP principles
- **Memory Management**: Working with dynamic memory allocation
- **References and Pointers**: Understanding memory addressing
- **Operator Overloading**: Customizing operators for classes
- **Inheritance**: Creating hierarchical class structures
- **Polymorphism**: Both compile-time and runtime polymorphism
- **Abstract Classes and Interfaces**: Designing flexible architectures
- **Exception Handling**: Writing robust error-handling code
- **C++ Casts**: Choosing between static, reinterpret and dynamic casts
- **Templates**: Writing type-independent functions and classes
- **The STL**: Containers, iterators and standard algorithms

## 🛠️ Technologies

- **Language**: C++ (96.9%)
- **Build System**: Makefile (3.1%)
- **Compiler**: C++ compiler with C++98 standard (or higher)

## 🚀 Getting Started

### Prerequisites

- C++ compiler (g++, clang++, etc.)
- Make utility

### Building and Running
Each module contains exercises with their own Makefiles. To compile and run an exercise:

```bash
# Navigate to the desired module and exercise
cd CPP00/ex00

# Build the project
make

# Run the executable
./[executable_name]

# Clean build files
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Rebuild from scratch
```

## 📖 Module Overview

### [CPP00 - Introduction to C++](CPP00/README.md)
Introduction to the fundamentals of C++, including namespaces, classes, member functions, stdio streams, initialization lists, static and const keywords. This module covers the basic building blocks needed to write C++ programs and introduces object-oriented programming concepts.

#### 📚 Resources
- [C++ Classes and Objects](https://www.learncpp.com/cpp-tutorial/classes-and-class-members/)
- [Namespaces in C++](https://en.cppreference.com/w/cpp/language/namespace)
- [Member Initialization Lists](https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/)
- [Static Members](https://www.learncpp.com/cpp-tutorial/static-member-variables/)
- [Const Keyword](https://www.learncpp.com/cpp-tutorial/const-class-objects-and-member-functions/)

### [CPP01 - Memory Allocation](CPP01/README.md)
Deep dive into dynamic memory allocation, pointers to members, references, and understanding the difference between stack and heap memory. Learn about memory leaks, proper resource management, and the importance of destructors in C++.

#### 📚 Resources
- [Dynamic Memory Allocation](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
- [Pointers vs References](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)
- [Memory Management](https://isocpp.org/wiki/faq/freestore-mgmt)
- [Stack vs Heap Memory](https://www.learncpp.com/cpp-tutorial/the-stack-and-the-heap/)
- [RAII Pattern](https://en.cppreference.com/w/cpp/language/raii)

### [CPP02 - Ad-hoc Polymorphism](CPP02/README.md)
Understanding operator overloading, fixed-point numbers, and the orthodox canonical class form (Coplien form). This module teaches how to make custom types behave like built-in types and properly manage copy semantics.

#### 📚 Resources
- [Operator Overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/)
- [The Rule of Three](https://en.cppreference.com/w/cpp/language/rule_of_three)
- [Copy Constructor](https://www.learncpp.com/cpp-tutorial/copy-constructors/)
- [Assignment Operator](https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/)
- [Fixed Point Arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)

### [CPP03 - Inheritance](CPP03/README.md)
Exploring inheritance hierarchies, access specifiers, and understanding the diamond problem in multiple inheritance. Learn how to create class hierarchies and understand the relationship between base and derived classes.

#### 📚 Resources
- [Inheritance Basics](https://www.learncpp.com/cpp-tutorial/introduction-to-inheritance/)
- [Multiple Inheritance](https://www.learncpp.com/cpp-tutorial/multiple-inheritance/)
- [Diamond Problem](https://www.geeksforgeeks.org/multiple-inheritance-in-c/)
- [Virtual Inheritance](https://en.cppreference.com/w/cpp/language/derived_class)
- [Access Specifiers](https://www.learncpp.com/cpp-tutorial/public-vs-private-inheritance/)

### [CPP04 - Subtype Polymorphism](CPP04/README.md)
Working with abstract classes, interfaces, pure virtual functions, and runtime polymorphism through virtual functions. Understanding how to design flexible and extensible class hierarchies using polymorphic behavior.

#### 📚 Resources
- [Virtual Functions](https://www.learncpp.com/cpp-tutorial/virtual-functions/)
- [Abstract Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)
- [Polymorphism in C++](https://www.geeksforgeeks.org/polymorphism-in-c/)
- [Virtual Destructors](https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/)
- [Interface Classes](https://isocpp.org/wiki/faq/abcs)

### [CPP05 - Exceptions](CPP05/README.md)
Mastering exception handling, understanding stack unwinding, and learning how to write robust error-handling code. This module also reinforces concepts from previous modules through repetition and practical application.

#### 📚 Resources
- [Stack Unwinding](https://stackoverflow.com/questions/2331316/what-is-stack-unwinding)
- [Skeleton Template](https://refactoring.guru/design-patterns/template-method)
- [Exceptions and repetitive](https://stackoverflow.com/questions/77901472/how-to-simplify-the-repetitive-exception-handling-in-c)
- [Factory pattern](https://refactoring.guru/design-patterns/factory-method/cpp/example)

### [CPP06 - C++ Casts](CPP06/README.md)
Exploring the four C++ cast operators and when each one is the right tool: `static_cast` for well-defined conversions, `reinterpret_cast` for bitwise reinterpretation of addresses, and `dynamic_cast` with RTTI for safe downcasting. The module also covers scalar conversion, pointer serialization and identifying the real type of a polymorphic object at runtime.

#### 📚 Resources
- [Explicit Type Conversion](https://en.cppreference.com/w/cpp/language/explicit_cast)
- [static_cast](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)
- [dynamic_cast and RTTI](https://www.learncpp.com/cpp-tutorial/dynamic-casting/)
- [reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast)
- [uintptr_t](https://en.cppreference.com/w/cpp/types/integer)

### [CPP07 - C++ Templates](CPP07/README.md)
Writing code that works with any type: function templates, template argument deduction, higher-order functions taking a callable as a template parameter, and class templates with their implementation split into a `.tpp` file. Ends with a generic, bounds-checked dynamic array.

#### 📚 Resources
- [Function Templates](https://www.learncpp.com/cpp-tutorial/function-templates/)
- [Class Templates](https://www.learncpp.com/cpp-tutorial/class-templates/)
- [Template Argument Deduction](https://en.cppreference.com/w/cpp/language/template_argument_deduction)
- [Why templates live in headers](https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl)
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range)

### [CPP08 - Templated Containers, Iterators, Algorithms](CPP08/README.md)
First real contact with the STL: sequence containers, iterators and the standard algorithms that operate on them. Covers writing templates that accept any container, and extending `std::stack` so its underlying container becomes iterable.

#### 📚 Resources
- [STL Containers](https://en.cppreference.com/w/cpp/container)
- [Iterators](https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/)
- [Standard Algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [The dependent `typename` keyword](https://en.cppreference.com/w/cpp/language/dependent_name)

### [CPP09 - STL Containers](CPP09/README.md)
Three standalone programs, each restricted to a different container, with strict input parsing and validation: a Bitcoin price evaluator built on `std::map`, an RPN calculator built on `std::stack`, and a Ford-Johnson merge-insertion sort benchmarked across `std::vector` and `std::deque`.

#### 📚 Resources
- [std::map](https://en.cppreference.com/w/cpp/container/map)
- [std::vector vs std::deque](https://en.cppreference.com/w/cpp/container/deque)
- [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- [Merge-Insertion (Ford-Johnson) Sort](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Jacobsthal Numbers](https://en.wikipedia.org/wiki/Jacobsthal_number)

## 📝 Notes

- All code follows C++98 standard (unless specified otherwise)
- Each exercise builds upon concepts from previous modules
- Makefiles include flags for strict compilation (-Wall -Wextra -Werror)

## 👨‍💻 Author

**Abdellahsyani**

## 📄 License

This project is created for educational purposes.

## 🤝 Contributing
This is a personal learning repository, but feel free to open issues if you spot any problems or have suggestions!

---

*Happy Coding! 🚀*