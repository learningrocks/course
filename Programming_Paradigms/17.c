

Semaphore forks[] = {1, 1, 1, 1, 1};

Semaphore numAllowedToEat(2);

void Philosopher(int id){
  for(int i = 0; i < 3; i++){
    Think();
    SW(numAllowedToEat);
    SW(forks[id]); 
    SW(forks[(id + 1) % 5]);
    EAT(); 
    SS(forks[id]);
    SS(forks[id + 1] % 5);
    SS(numAllowedToEat);
  }
  Think();
}

int DownloadSingleFile(const char *server, const char *path);

void DownloadHelper(const char *server, const char *path, int *numBytesp, Semaphpre lock){
   int bytesDownloaded = DownloadSigleFile(server, path);
   SW(lock);
   (*numBytesP) += bytesDownloaded;
   SS(lock);
}

int DownloadAllFiles(const char* server, const char* fiels[], int n){
   Semaphore childrenDone = 0;
   int totalBytes = 0;
   Semaphore lock = 1; 
   for(int i; i < n; i++){
     ThreadNew(--, DownloadHelper, server, files[i], &totalBytes, lock); 
   }
   for(int i = 0; i < n; i++) SW(childrenDone)
   return totalBytes;   
}


