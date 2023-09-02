#include <stdexcept>

int throwingFunc(int);

int throwingFunc(int)
{
  throw std::logic_error("throwingFunc called");
}
