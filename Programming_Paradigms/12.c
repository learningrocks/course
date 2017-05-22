#define kWidth 40
#define kHeight 80
#define kPerimer 2 * (kWidth + kHeight)

#define MAX(a, b)  (a > b) ? a : b

/**
 *  function may be ten assembly code instructions:
 *    that a lot of time is spent:
 *    setting up parameters, writing the parameters there, jumping to the function, and then after it’s all over, jumping back and cleaning up the parameters.
 *  but use of macros would expand to like three or four assembly code instructions
 *
 */ 

#ifdef NDEBUG 
  #define assert(cond) (void) 0 
#else
   #define assert(cond) \
   (cond) ? (void 0) : fprintf(stderr, "..."); exit(0) 
#endif

#include <stdio.h>
#include <assert.h>
#include "stack.h" // inject full content of stack.h


