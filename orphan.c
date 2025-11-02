#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pd = fork();
	if(pd > 0){
		printf("parent process exiting, PID: %d\n", getpid());
		exit(0);
	}
	else{
		printf("Child started, PID: %d, Parent PID: %d\n", getpid(), getppid());
		sleep(5);
		printf("Child now orphaned, new parent PID: %d\n", getppid());
		exit(0);
	}
	return 0;
}
