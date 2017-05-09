#include <stdio.h>
#include <string.h>

int study(){
   /* when you use malloc, it'll usually set aside 164 bytes or 168 bytes.
    * it's include space at the buginning of either 4 or 8
    * a little header of full mode
    * when you got pointer back, you actually dont'get a pointer to the header of node, you got a pointer that's 4 or 8 bytes inset from the beginning
    */
   int *arr = malloc(40 * sizeof(int));

   /* it's not work
    * you cant't do that because of free will check 4 or 8 bytes front of (arr + 60) for size of some node
    */
   int *arr1 = malloc(100 * sizeof(int));
   free(arr + 60);

   int array[100];
   free(array);

   void **handle = NewHandle(40);   
   Handlelock(handle);
   HandleUnlock(handle);

   //todo: implement malloc
}

/**
 * function call use stack
 */

void  C(){
  double m[3];
  int n;
}

void B(){
  ing x;
  char *y;
  char *z[2];
  C();
}

void A(){
  int a;
  short b[8];
  double c;
  
  B();
  C(); 
}

