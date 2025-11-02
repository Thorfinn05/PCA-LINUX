#include<stdio.h>
int main(){
	int n;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	int bt[n], wt[n], rt[n], tat[n], pid[n];
	printf("Enter Process ID: ");
	for(int i=0; i<n; i++){
		scanf("%d", &pid[i]);
	}
	printf("Enter burst time: ");
	for(int i=0; i<n; i++){
		scanf("%d", &bt[i]);
		rt[i] = bt[i];
		wt[i]=0;
	}
	int qt;
	printf("Enter Quantum Time: ");
	scanf("%d", &qt);
	int time = 0;
	int done;
	do{
		done=1;
		for(int i=0; i<n; i++){
			if(rt[i]>0){
				done = 0;
				if(rt[i]>qt){
					time += qt;
					rt[i] -= qt;
				}
				else{
					time += rt[i];
					wt[i] = time - bt[i];
					rt[i] = 0;
				}
			}
		}
	}
	while (!done);
	for(int i=0; i<n; i++){
		tat[i] = wt[i] + bt[i];
	}
	float twt=0, ttat=0;
	printf("PID  BT  WT  TAT\n");
	for(int i=0; i<n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
		twt += wt[i];
		ttat += tat[i];
	}
	printf("\nAvg WT: %2f", twt/n);
	printf("\nAvg TAT: %2f\n", ttat/n);
	return 0;
}
