#include<sys/shm.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int seg_id;
	double *data;
	seg_id = shmget(IPC_PRIVATE,sizeof(double),IPC_CREAT|0666);
	if(seg_id == -1){
		printf("Errot: Failed to create a memory segment");
		exit(-1);
	}else{
		printf("Segment ID is %d\n",seg_id);
	}
	data = shmat(seg_id,NULL,0);
	*data = 300.5;
	shmdt(data);
	shmctl(seg_id,IPC_RMID,0);
	return 0;
}
