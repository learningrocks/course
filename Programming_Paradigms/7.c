#include <stdio.h>
#include "stack_7.h"

void StringFree(void *elem){
  free(* (char **) elem);
}

void rotate(void *front, void *middle, void *end){
   int frontSize = (char *) middle - (char *)front;  
   int backSize = (char *) end - (char *) middle;
   char buffer[frontSize];
   memcpy(buffer, front, frontSize);
   memmove(front, middle, backSize);
   memcpy((char *)end - frontSize, buffer, frontSize);
}

int main(){
  const char *friends[] = {"Al", "Bob", "Carl"};
  stack stringStack;
  StackNew(&stringStack, sizeof(char *), StringFree);
  for(int i = 0; i < 3; i++){
    char *copy = strdup(friends[i]);
    StackPush(&stringStack, &copy);
  }
  char *name;
  for(int i = 0; i < 3; i++){
    StackPop(&stringStack, &name);
    printf("pop element from stack is %s \n", name);
    free(name);
  }
  StackDispose(&stringStack);
}
