#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
	pid_t pid = fork();
	if(pid == 0){
		printf("Child is running...\n");
		int i;
		for(i=1; i<=5; i++){
			printf("\t%d ", i);
		}
		printf("\n");
	}
	else if(pid > 0){
		printf("Parent in running...\n");
		printf("Parent PID: %d\n", getpid());
		printf("Child PID: %d\n", pid);
	}
	return 0;
}
