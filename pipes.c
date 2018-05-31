#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>

char *message = "This is a message!!!";
void main(){
	char buf[1024];
	int fd[2];
	int fd2[2];
	pipe(fd);/*Create a pipe*/
	if(fork()!=0){
		write(fd[1],message,strlen(message)+1);
		read(fd2[0],buf,1024);
		printf("Got this from Child!!%s\n",buf);
	}else{
		read(fd[0],buf,1024);
		printf("Got this from parent!!%s\n",buf);
		write(fd2[1],message,strlen(message)+1);
	}
}
