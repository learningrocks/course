// listen 4 c
#include <stdio.h>
#include <string.h>


// swap void pointer need to assign memery size, not only use void size
void swap(void *vp1, void *vp2, int size){
    char buffer[size];
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}

int search(int key, int array[], int size){
    for(int i = 0; i < size; i++){
        if(array[i] == key){
            return i;
        }
    }
    return -1;
}

void *isearch(void *key, void *base, int n, int elemSize){
    for(int i = 0; i < n; i++ ){
        void *elemAddr = (char*)base + i * elemSize;
        if(memcmp(key, elemAddr, elemSize) == 0) return elemAddr;
    }
    return NULL;
}

int main(){
    // int swap
    int x = 1;
    int y = 2;
    printf("%d, %d \n", x, y);
    swap(&x, &y, 4);
    printf("%d, %d \n", x, y);
    
    // string swap, still neec refer &
    char *husband = strdup("Fred");
    char *wife = strdup("Willma");
    swap(&husband, &wife, sizeof(char *));
    printf("%s, %s\n", husband, wife);
}

