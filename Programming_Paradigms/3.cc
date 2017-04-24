#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "listen 3\n";
    return 0;
}

// transfer struct memory pointer
void struct_cast(){
    struct fractor {
        int num;
        int demon;
    };
    struct fractor val;
    val.num = 11;
    val.demon = 22;
    
    fractor nval = *(fractor*)&(val.demon);
    cout << nval.num << endl;
}

// c/c++ did not handle boundary
void arr_boundary(){
    int arr[10];
    arr[0] = 1;
    arr[1] = 10;
    arr[-1] = 5;
    arr[10] = 4;
    cout << arr[10] << endl;
    cout << arr[-1] << endl;
}

void struct_memory(){
    struct student{
        char* name;
        char suid[8];
        int nvmUnits;
    };
    struct student pupils[4];
    pupils[0].nvmUnits = 21;
    pupils[2].name = strdup("Adam");
    strcpy(pupils[0].suid, "abcdefg");
    pupils[3].name = pupils[0].suid + 6;
    cout << "name:" << pupils[3].name << endl;
    cout << "suid:" << pupils[1].suid << endl;
    cout << "before:" << pupils[0].nvmUnits << endl;
    // will affeacted pupile[0]
    strcpy(pupils[1].suid, "40415xx");
    strcpy(pupils[3].name, "123456");
    cout << "after:" << pupils[0].nvmUnits << endl;
    //pupils[7].suid[11] = 'A';
}