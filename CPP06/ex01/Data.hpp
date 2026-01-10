#pragma once

/**
 * Data: A Plain Old Data (POD) structure.
 * This structure serves as our serialization target. It contains diverse 
 * scalar types (int, float, char) to verify that data integrity is 
 * maintained after the address is converted and restored.
 **/
struct Data {
  int n;
  float f;
  char c;
};


