#include <stdio.h> 

void foo(int bar, int *baz){
  char snink[4];
  short *why;
  why = (short *)(snink + 2);
  *why = 50;
}

/**
 *  |_______| baz
 *  |_______| bar
 *  |_______| function that call us 
 *  |_|_|_|_| snink[0..3]
 *  |_______| why
 *
 *  foo: SP = SP - 8;
 *  R1 = SP + 6;
 *  M[SP] = R1;
 *  R1 = M[SP];
 *  M[R1] = .2 50;
 *  SP = SP + 8
 *  RET;
 *
 */

int main(int argc, char **argv){
  int i = 4;
  foo(i, &i);
  return 0;
}

/**
 * |___| ->  |_|_|_|  argv
 * |_2_| argc
 * |___| saved pc
 * |___| 4
 * |___| 
 * |___| 4
 * |___| saved pc
 *
 *
 * SP = SP - 4;
 * M[SP] = 4;
 * - 
 * SP = SP - 8;
 * R1 = M [SP + 8];
 * R2 = SP + 8;
 * M[SP] = R1;
 * MP[SP + 4] = R2;
 * CALL <foo>
 * SP = SP + 8
 * RX = 0;
 */

int fact (int x){
  if (x == 0){
    return 1;
  }
  return x * fact(x - 1);
}

/**
 * |____| 4
 * |____| pc
 * |____| 3
 *
 *  R1 = M[SP + 4]
 *  BNE R1, 0, PC+12
 *  RV = 1;
 *  RET;
 *  R1 = M[SP + 4];
 *  R1 = R1 - 1;
 *  SP = SP -4;
 *  M[SP] = R1;
 *  CALL <fact>
 *  SP = SP + 4;
 *  R1 = M[SP + 4];
 *  RV = RV * R1;
 *  RET
 **/
















