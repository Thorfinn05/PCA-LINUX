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
	int tat[n];
	for(int i=1; i<n; i++){
		tat[i] = wt[i] + bt[i];
	}
	printf("PID  BT  WT  TAT\n");
	float twt = 0.0;
	float ttat = 0.0;
	for(int i=0; i<n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
		twt += wt[i];
		ttat += tat[i];
	}
	printf("Avg WT: %2f", twt/n);
	printf("Avg TAT: %2f", ttat/n);
	return 0;
}
