#include "stack_7.h"

void StackNew(stack *s, int elemSize, void (*freefn)(void *)){
   s -> elemSize = elemSize;
   s -> loglength = 0;
   s -> alloclength = 4;
   s -> elems = malloc(4 * elemSize);
   s -> freefn = freefn;
   assert(s -> elems != NULL);
}

void StackDispose(stack *s){
   if(s -> freefn != NULL){
     for(int i =0; i < s -> loglength; i++){
        s -> freefn((char *) s -> elems + i * s -> elemSize); 
     } 
   }
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


