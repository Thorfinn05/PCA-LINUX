#include<stdio.h>
int main(){
	int pid[15], bt[15];
	int n;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	printf("Enter process id of all the processes: ");
	for(int i=0;i<n;i++){
		scanf("%d",&pid[i]);
	}
	printf("Enter Burst Time: ");
	for(int i=0; i<n; i++){
		scanf("%d", &bt[i]);
	}
	int temp;
	printf("Sorting Burst Time:");
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n;j++){
			if(bt[i] > bt[j]){
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
			}
		}
	}
	int wt[n];
	wt[0]=0;
	for(int i=1; i<n; i++){
		wt[i] = wt[i-1] + bt[i-1];
	}
	int tat[n];
	for(int i=0; i<n; i++){
		tat[i] = wt[i] + bt[i];
	}
	float twt=0, ttat=0;
	float avg_wt=0, avg_tat=0;
	printf("PID  BT  WT  TAT\n");
	for(int i=0; i<n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
		twt += wt[i];
		ttat += tat[i];
	}
	printf("\nAverage WT: %2f\n", twt/n);
	printf("Average TAT: %2f\n", ttat/n);
	return 0;
}
