#include "Serializer.hpp"
// Note: reinterpret_cast is used here as a compiler directive to re-label 
// the memory address. It does not modify the underlying bit pattern; 
// it only changes the type-checking logic for the provided value.


/**
 * serialize: Converts a Data pointer into its integer representation.
 * This is used to store or transmit the address as a raw numerical value.
 **/
uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * deserialize: Reconstructs the Data pointer from its integer representation.
 * This allows us to access the original object's members via the restored address.
 **/
Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
