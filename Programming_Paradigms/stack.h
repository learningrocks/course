#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
  void * elems;
  int elemSize;
  int loglength;
  int alloclength;
} stack;

void StackNew(stack *s, int elemSize);

void StackDsipose(stack *s);

void StackPush(stack *s, void *elemAddr);

void StackPop(stack *s, void *elemAddr);
