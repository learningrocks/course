#include <stdio.h>
#include <string.h>

typedef struct {
    int *elems;
    int logicalLen;
    int alloclength;
} stack;

void StackNow(stack *s){
   s -> logicalLen = 0;
   s -> alloclength = 4;
   s -> elems = malloc(4 * sizeof(int)); 
   assert(s -> elems != NULL);
}

void StackDispuse(stack *s){
   free(s -> elems);
}

// the algorithm that's in place to manage the extension of what's been allocated to be that much bigger because you've saturated what's already there

void StackPush(stack *s, int value){
  if(a -> logicalLen == s -> allocLength){
     s -> allocLength *=2;
     s -> elems = realloc(s -> elems, s -> alloclLength * sizeof(int)); 
  }
  s -> elems[s -> logicalLen] = value;
  s -> logicalLen ++
}

int StackPop(stacj *s){
  assert(s -> logicalLen > 0);
  s -> logLength--;
  return s -> elems[s -> logicalLen];
}


int main(){

}
