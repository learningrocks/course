#include <stdio.h>
#include "stack.h"
// 

int main(){
  stack s;
  int x;
  StackNew(&s, sizeof(int));
  for(int i = 0; i < 10; i ++){
    StackPush(&s, &i);
  }
  StackPop(&s, &x);
  printf("pop element from stack is %d \n", x);
}
