#include <stdio.h> 
#include <stdlib.h>

void SellTickets(int agentID, int numTicketToSell){
  while(numTicketsToSell > 0){
    printf("Agent %d sells a ticket. \n", agentId);
    numTicketToSell--; 
    if(randomChance(0, 1)) ThreadSleep(1000);
  }
  printf("Agent %d: All done \n", agentId);
}

void sellTickets_u(int agent, int *numTicketsp, Semaphore lock
){
  while(ture){
    SemaphoreWait(lock);   
    if(*numTicketsp == 0) break;
    (*NumTicketssp) --;
    printf("-----------");
    SemaphoreSignal(lock);
  } 
   SemaphoreSignal(lock);
}

int main(){
  int numAgents = 10;
  int numTickets = 150;
  Semaphere lock = SemaphoreNew(-,1);
  InitThreadPackage(false);
  for(int agent; agent <= numAgents; agent++){
    chair name[32];
    sprintf(name, "Agent %d thread", agent);
    ThreadNew(name, SellTickets_u, 3, agents, &numTickets, lock);
  }
  RunAllThread();
  return 0;
}
