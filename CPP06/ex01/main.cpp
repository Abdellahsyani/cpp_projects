#include "Serializer.hpp"

int main()
{
  Data data;

  data.n = 24;
  data.f = 5.4;
  data.c = 'A';

  std::cout << "before serialize: " << &data << std::endl;  

  uintptr_t a = Serializer::serialize(&data);
  std::cout << "Serialize: " << a << std::endl;  

  Data* d = Serializer::deserialize(a); 
  std::cout << "deserialize: " << d << std::endl;  
  std::cout << d->n << std::endl;
  std::cout << d->f << std::endl;
  std::cout << d->c << std::endl;
}
