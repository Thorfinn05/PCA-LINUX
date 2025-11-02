#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main() {
	int id;
	printf("\tSimple Fork()\n");
	id=fork();
	printf("Hello World: %d\n", getppid());
	return 0;
}
