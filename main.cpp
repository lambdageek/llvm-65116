#include <stdexcept>
#include <string>
#include <stdio.h>

int runMe(int);

int getCallCount();

int main()
{
  try {
    runMe(42);
  } catch (const std::exception& e) {
    std::string s = e.what();
    printf("caught something: %s\n", s.c_str());
  }
  int n = getCallCount();
  if (n == 2)
    printf ("GOOD: there were 2 calls to countCalls()\n");
  else
    printf ("BAD: there were %d calls to countCalls(), expected 2\n", n);
  return 0;
}

