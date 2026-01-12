#pragma once

#include <iostream>

/**
 * Base: A Polymorphic Base Class.
 *  * ROLE:
 *      - Serves as the root of the inheritance hierarchy for classes A, B, and C.
 *      - Provides a Virtual Destructor: This is essential to enable RTTI (Run-Time 
 *        Type Information), which allows dynamic_cast to safely verify the 
 *        object's "real" type at runtime.
 *      - Enables Safe Downcasting: Acts as the common interface through which 
 *        we can identify and access specific child class implementations.
 **/
class Base {
public:
  virtual ~Base();
};


/**
 * Global Helper Functions
 * -----------------------
 * @generate:         Randomly instantiates A, B, or C and returns it as a Base pointer.
 * @identify(Base*):  Uses pointer-based dynamic_cast to identify the type (returns NULL on failure).
 * @identify(Base&):  Uses reference-based dynamic_cast to identify the type (throws on failure).
 **/
Base * generate(void);
void identify(Base* p);
void identify(Base& p);
