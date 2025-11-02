#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int isPalindrome(int num){
	int org = num;
	int rev = 0;
	while(num > 0){
		int dig = (num%10);
		rev = (rev*10+dig);
		num = (num/10);
	}
	if(org == rev)
		return 1;
	else
		return 0;
}

int main(){
	int fd1[2], fd2[2];
	int num, result;
	pid_t pid;
	if(pipe(fd1) == -1 || pipe(fd2) == -1){
		perror("pipe failed");
		exit(1);
	}
	pid = fork();
	if(pid == 0){
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0], &num, sizeof(num));
		result = isPalindrome(num);
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
		if(result)
			printf("%d is Palindrome\n", num);
		else
			printf("%d is not a Palindrome\n", num);
		close(fd1[1]);
		close(fd2[0]);
	}
	return 0;
} 
