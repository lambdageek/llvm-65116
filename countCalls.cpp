#include <stdio.h>

int countCalls(void);
int getCallCount(void);

static int count = 0;

int countCalls(void)
{
    printf ("in foo %d times\n", ++count);
    return 0;
}

int getCallCount(void)
{
  return count;
}
