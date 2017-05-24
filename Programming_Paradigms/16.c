#include <stdio.h>

char buffer[8];
Semaphore emptyBuffers(8);
Semophore fullBuffers(0);

void SellTicket(int agent, int *numTicketsp, Semaphore lock){
   while(true){
     SemaphoreWait(lock);
     if(*numTicketsp == 0) break;
     (*numTicketsp) --;
     SemaphareSignal(lock);
     printf("...\n");
   }
   SemaphoreSignal(lock);
}

void Writer(){
  for(int i = 0; i < 40; i++){
    char c = PrepareRandamChar();
    SemaphoreWait(emptyBuffer);
    buffer[i % 8] = c;
    SemaphoreSignal(fullBuffers)
  }
}

void Reader(){
  for(int i = 0; i < 40; i++){
    SemaphoreWait(fullBuffers);
    char c = buffer[i % 8];
    SemaphoreSignal(emptyBuffers);
    ProcessChar(c)
  }
}

int main(){
  ITP(false);
  ThreadNew("Writer", Writer, 0);
  ThreadNew("Reader", Reader, 0);
  RunAllThread();
}
