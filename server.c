#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHSIZE 100

int main(int argc, char *argv[])
{
  int shmid;
  key_t key;
  char *shm;
  char *s;

  key = 6047;

  shmid = shmget(key, SHSIZE, IPC_CREAT | 2469);
  if(shmid < 0)
  {
    perror("shmget");
    exit(1);
  }

  shm = shmat(shmid, NULL, 0);

  if(shm == (char *) -1)
  {
    perror("shmat");
    exit(1);
  }

  memcpy(shm, "Hello Sol",9);

  s = shm;
  s += 9;

  *s = 0;

  while(*s != '*');
	sleep(1);

  return 0;
} 
