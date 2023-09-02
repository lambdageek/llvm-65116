// Type your code here, or load an example.

#include <stdexcept>

// leave INLINE_CALLER undefined to get a working version, define it to see a crash
#ifdef INLINE_CALLER
#include "indirectCaller.hpp"
#else
int outlinedIndirectCaller();
#endif

int countCalls(void);


class RAIIObj {
public:
  explicit RAIIObj() { countCalls();}
  ~RAIIObj() {countCalls();};
};


int runMe(int);

int runMe(int num) {
    RAIIObj raiiObj{}; // calls to countCalls() happen here
#ifdef INLINE_CALLER
    return indirectCaller();
#else
    return outlinedIndirectCaller();
#endif
    // expected the call to foo to happen after baz returns
}

