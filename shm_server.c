#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define SHMSZ 27

void main(){
	char c;
	int shm_id;
	key_t key = 5678;
	char *shm,*s;
	if((shm_id = shmget(key,SHMSZ,IPC_CREAT|0666))<0){
		printf("ERROR: shmget error");
		exit(1);
	}
	if((shm = shmat(shm_id,NULL,0))== (char *)-1){
		printf("ERROR: shmat error");
		exit(1);
	}
	s = shm;
	for(c = 'a';c<='z';c++){
		*s++=c;
	}
		*s='\0';
	while(*shm!='*')
		sleep(1);
	for(s = shm;*s!='\0';s++)
		putchar(*s);
		putchar('\n');
	shmdt(shm);
	shmctl(shm_id,IPC_RMID,0);
	exit(0);
}
