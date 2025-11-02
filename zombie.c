#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pd = fork();
	if(pd == 0){
		printf("Child exiting...\n");
		exit(0);
	}
	else if (pd > 0){
		printf("Parent is sleeping, Child is now Zombie...\n");
		sleep(10);
		printf("Parent exiting...\n");
	}
	return 0;
}
