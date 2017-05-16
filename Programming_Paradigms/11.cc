
void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp; 
}

/**
 *  assembly code exactly like c compiled  
 */


/**
 * struct and object in memory is exactly the same way
 * structs can have constructors, destructors, and methods 
 * The only difference between structs and classes, in C + +, is that the default access modifier for classes is private, and the default access modifier for structs is public. 
 *
 */

class binky{
  public:
    int dunky(int x, int y);
    char * minky(int *z){
      int w = *x; 
      return slinky + dunky(winky, winky); 
    };

  private:
    int winky;
    char *blinky;
    char slinky[8];
}

class fraction{
  public: 
    fraction(int n, int d =1);

    void reduce();

  private:
    static int god(int x; int y);
  
}

int main(){
  int x;
  int y;
  x = 11;
  y = 17;
  swap(x, y);
  binky b;
  int n = 17;
  b.minky(&n); // ==  binky::minky(&b. &n);
}

