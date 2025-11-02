#include<stdio.h>
int main(){
	int pid[15];
	int bt[15];
	int n;
	printf("Enter no. of processes: ");
	scanf("%d", &n);
	printf("Enter process id of all processes: ");
	for(int i=0; i<n; i++){
		scanf("%d", &pid[i]);
	}
	printf("Enter burst time of all processes: ");
	for(int i=0; i<n; i++){
		scanf("%d", &bt[i]);
	}
	int i, wt[n];
	wt[0]=0;
	for(int i=1; i<n; i++){
		wt[i] = wt[i-1] + bt[i-1];
	}
	printf("PID  BT  WT  TAT\n");
	float twt = 0.0;
	float tat = 0.0;
	for(int i=0; i<n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], bt[i]+wt[i]);
		twt += wt[i];
		tat += (wt[i]+bt[i]);
	}
	printf("Avg WT: %2f", twt/n);
	printf("Avg TAT: %2f", tat/n);
	return 0;
}
