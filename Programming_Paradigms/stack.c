#include "stack.h"

void StackNew(stack *s, int elemSize){
   s -> elemSize = elemSize;
   s -> loglength = 0;
   s -> alloclength = 4;
   s -> elems = malloc(4 * elemSize);
   assert(s -> elems != NULL);
}

void StackDispose(stack *s){
   free(s -> elems);
}

static void StackGrow(stack *s){
   s -> alloclength *= 2;
   s -> elems = realloc(s -> elems, s -> alloclength * s -> elemSize);
}

void StackPush(stack *s, void *elemAddr){
   if(s -> loglength == s -> alloclength) {
      StackGrow(s); 
   }
   void *target = (char *) s -> elems + s -> loglength * s -> elemSize;
   memcpy(target, elemAddr, s -> elemSize);
   s -> loglength++;
}

void StackPop(stack *s, void *elemAddr){
  void *source = (char *) s -> elems + (s -> loglength - 1) * s -> elemSize;
  memcpy(elemAddr, source, s -> elemSize);
  s -> loglength--;
}


