
int main(){
  int i;
  short s1;
  short s2;

  i = 200; //=>  M[R1 + 4] = 200;
  s1 = i; // => R2 = M[R1 + 4]; M[R1 + 2] = .2 R2; 
  s2 = s1 + 1; // => R2 = .2 M[R1 + 2]; R3 = R2 + 1; M[R1] = .2 R3;

  int array[4]; 
  int i;
  /**
   *  M[R1] = 0;
   *  R2 = M[R1];
   *  BGE R2, 4, PC + 40;
   *  R3 = M[R1]; 
   *  R4 = R3 * 4;
   *  R5 = R1 + 4;
   *  R6 = R4 + R5;
   *  M[R6] = 0;
   *
   *  R2 = M[R1];
   *  R2 = R2 + 1;
   *  M[R1] = R2;
   *  JMP PC-40;
   **/  
 
  for (i = 0; i < 4; i++){
    array[i] = 0;
  }

  i--;

}

struct fraction {
  int num;
  int denom;
};

struct fraction pi;
pi.num = 22; => m[R1] = 22;
pi.denom = 7; => M[R1 + 4] = 7; 

((struct fraction)&pi.denom) -> denom = 451;
// M[R1 + 8] = 451;
