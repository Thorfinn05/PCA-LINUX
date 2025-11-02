#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main(){
	int id;
	printf("\tProcess ID of Parent and Child\n");
	id=fork();
	if(id==0){
		printf("Child Process is calling. Child PID: %d.\n", getpid());
	}
	else{
		printf("Parent Process is calling. Parent PID: %d\n", getppid());
	}
	return 0;
}
