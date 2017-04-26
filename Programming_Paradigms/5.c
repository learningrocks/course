#include <stdio.h>
#include <string.h>

void *l_search(void *key, void *base, int n, int elemSize, int (*cmpFn)(void *, void *)){
    for(int i =0; i < n; i++){
        void *elemAddr = (char*)base + i * elemSize;
        if(cmpFn(key, elemAddr) == 0)
            return elemAddr;
    }
    return NULL;
}

int intcmp(void *elem1, void *elem2){
    int *ip1 = elem1;
    int *ip2 = elem2;
    return *ip1 - *ip2;
}

int strCmp(void *vp1, void *vp2){
    char *s1 = *(char **)vp1;
    char *s2 = *(char **)vp2;
    return strcmp(s1, s2);
}

int main(){
    int arr[] = {4, 2, 3, 7, 11, 6};
    int size = 6;
    int number = 7;
    int *found = l_search(&number, arr, size, sizeof(int), intcmp);
    if(found == NULL){
        printf("not found!\n");
    }else{
        printf("found it in %d\n", *found);
    }
    
    char *notes[] = {"Ab", "F#", "B", "6b", "D"};
    char *favoriteNote = "Eb";
    
    char **found2 = l_search(&favoriteNote, notes, 5, sizeof(char *), strCmp);
}

/*
 *  method/regular function
 *  
 *  method: in class, have the address of the relevent oject lying around as this invisible parameter 
 *  (via this invisible parameter called this)
 *
 *  function: object-oriented-less normal functions
*/

// use struct to simulate class in c
typedef struct {
    int *elems;
    int logicalLen;
    int alloclength;
} stack;

void StackNew(stack *s);

void StackDispose(stack *s);

void StackPush(stack *s, int value);

int StackPop(stack *s);


 






