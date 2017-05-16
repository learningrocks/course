void swap(int *ap, int *bp){
  int temp = *ap;
  *ap = *bp;
  *bp = temp;
}
/**
 * SP = SP - 4;
 * R1 = M[SP + 8];
 * R2 = M[R1];
 * M[SP] = R2;
 *
 * R1 = M[SP + 12];
 * R2 = M[R1];
 * R3 = M[SP + 8];
 * M[R3] = R2;
 *
 * R1 = M[SP];
 * R2 = M[SP + 12];
 * M[R2] = R1
 *
 * SP = SP + 4;
 * RET
 */

void foo(){
  int x;
  int y;

  x = 11;
  y = 17;
  swap(&x, &y);
}

/**
 * SP = SP - 8;
 * M[SP + 4] = 11; 
 * M[SP] = 17;
 * R1 = SP; // &y
 * R2 = SP + 4; // &x
 * SP = SP - 8;
 * M[SP] = R2;
 * MP[SP + 4] = R1;
 * CALL <swap>
 *
 * SP = SP + 8;
 * RET
 *
 */
