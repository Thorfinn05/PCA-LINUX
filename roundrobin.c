#include <stdio.h>

int main() {
    int n, qt;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], rt[n], wt[n], tat[n];
    printf("Enter process IDs: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }

    printf("Enter Burst Times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // remaining time
        wt[i] = 0;     // initialize waiting time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &qt);

    int time = 0;
    int done;

    // Round Robin scheduling loop
    do {
        done = 1; // assume all done

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0; // there is still a process remaining

                if (rt[i] > qt) {
                    time += qt;
                    rt[i] -= qt;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while (!done);

    // Turnaround time = waiting time + burst time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display results
    printf("\nPID\tBT\tWT\tTAT\n");
    float twt = 0, ttat = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
        twt += wt[i];
        ttat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", twt / n);
    printf("\nAverage Turnaround Time: %.2f\n", ttat / n);

    return 0;
}
