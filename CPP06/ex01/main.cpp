#include "Serializer.hpp"

int main()
{
  Data data;

  data.n = 24;
  data.f = 5.4;
  data.c 'A';

  Serializer::Serialize(&data);
  std::cout 
}
