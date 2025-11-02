#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int isPrime(int n){
	if (n<2)
		return 0;
	for(int i=2; i<=n/2; i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
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
	if (pid == 0){
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], &num, sizeof(num));
		result = isPrime(num);
		write(fd2[1], &result, sizeof(result));
		close(fd1[0]);
		close(fd2[1]);
	}
	else{
		close(fd1[0]);
		close(fd2[1]);
		printf("Enter number: ");
		scanf("%d", &num);
		write(fd1[1], &num, sizeof(num));
		read(fd2[0], &result, sizeof(result));
		if(result)
			printf("%d is Prime.\n", num);
		else
			printf("%d is not a PRime.\n", num);
		close(fd1[1]);
		close(fd2[0]);
	}
	return 0;
}
