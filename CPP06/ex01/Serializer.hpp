#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

/**
 * Serializer: A static utility class for pointer serialization.
 *    * DESIGN PATTERN:
 *      - This class is non-instantiable (Private OCF) to enforce its role 
 *        as a purely static interface.
 *    * ROLE:
 *      - Implements a "bitwise reinterpretation" of memory addresses.
 *      - By using reinterpret_cast, we instruct the compiler to treat a pointer 
 *        address as a raw numerical value (uintptr_t) without altering the 
 *        underlying binary data.
 *      - Uses uintptr_t to ensure the integer type is exactly the same width 
 *        as a pointer, preventing data loss during the conversion.
 **/ 
class Serializer {
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

public:
   static uintptr_t serialize(Data* ptr);
   static Data* deserialize(uintptr_t raw);
};
