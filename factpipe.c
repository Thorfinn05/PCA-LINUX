#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int getFact(int num){
	int f=1;
	for(int i=1; i<=num; i++){
		f=(f*i);
	}
	return f;
}
int main(){
	int fd1[2], fd2[2];
	pid_t pid;
	int num, result;
	if(pipe(fd1) == -1 || pipe(fd2) == -1){
		perror("pipe failed");
		exit(1);
	}
	pid = fork();
	if(pid == 0){
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], &num, sizeof(num));
		result = getFact(num);
		write(fd2[1], &result, sizeof(result));
		close(fd1[0]);
		close(fd2[1]);
	}
	else{
		close(fd1[0]);
		close(fd2[1]);
		printf("Emter number: ");
		scanf("%d", &num);
		write(fd1[1], &num, sizeof(num));
		read(fd2[0], &result, sizeof(result));
		printf("factorial of %d is %d.\n", num, result);
		close(fd1[1]);
		close(fd2[0]);
	}
	return 0;
}
