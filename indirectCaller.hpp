#ifndef INDIRECT_CALLER_H_
#define INDIRECT_CALLER_H_

int throwingFunc(int);

static inline int
indirectCaller (void)
{
    int x = 0;
#if 1
//    try {
	asm volatile(
	    "xor %%edi, %%edi; "
	    "callq *%P1; "
	    "incl %%eax;"
	    "movl %%eax, %0 ;"
	    : "=r"(x)
	    : "r"(throwingFunc)
	    : "%rdi", "%rsi", "%rax", "%rbx", "%rcx", "%rdx"
	    );
//    } catch (...) {
//	throw;
//    }
#else
      x = 1 + bar (0);
#endif
    return x;
}

#endif
