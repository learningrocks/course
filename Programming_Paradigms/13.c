#include <stdio.h>
#include <string.h>

//define prototype
int strlen(char *s, int num);

int memcmp(void *v1);



int main(){
  int num = 65;
  int length = strlen((char *) &num, num);
  // more arguments, but in link parse did not check
  printf("length = %d \n", length);

  int m = 17;
 

  return 0;
}


/**
 * seg fault: *(NULL) when you dereference a bad pointer;
 *
 * bus error: 
 * when you’re dealing with manually packed data like we say on assignment two and you’re trying to rehydrate two byte and one byte – four byte figures from arbitrary addresses internal to some data image
 * =====
 * void *vp = ___
 * *(short *) vp = 7;
 * *(int *) vp = 55;
 *
 */

//forever loop because of array[i] trans i to 0 again

int loop(){
  int i;
  int array[4];
  for(i = 0; i <=4; i++){
    array[i] = 0;
  }
  return i
}


