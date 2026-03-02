#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int pid[n], at[n], bt[n];
    int ct[n], tat[n], wt[n];

    // Read process details
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    // Sort by Arrival Time (FCFS requirement)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                // swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap pid
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate Completion Time
    int current_time = 0;

    for(int i = 0; i < n; i++) {

        if(current_time < at[i]) {
            current_time = at[i];   // CPU idle case
        }

        ct[i] = current_time + bt[i];
        current_time = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    double total_wt = 0, total_tat = 0;

    for(int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    double avg_wt = total_wt / n;
    double avg_tat = total_tat / n;

    // Print in required format
    printf("Waiting Time:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d %d\n", pid[i], wt[i]);
    }

    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d %d\n", pid[i], tat[i]);
    }

    printf("Average Waiting Time: %.2lf\n", avg_wt);
    printf("Average Turnaround Time: %.2lf\n", avg_tat);

    return 0;
}
