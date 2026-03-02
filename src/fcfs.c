#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int pid[100], at[100], bt[100];
    int wt[100], tat[100];

    // Read input
    for (int i = 0; i < n; i++) {
        char pname[20];
        scanf("%s %d %d", pname, &at[i], &bt[i]);
        pid[i] = atoi(pname + 1);   // Convert "P1" -> 1
    }

    // Sort by Arrival Time (FCFS requirement)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int current_time = 0;

    // FCFS calculation
    for (int i = 0; i < n; i++) {

        if (current_time < at[i]) {
            current_time = at[i];  // CPU idle case
        }

        wt[i] = current_time - at[i];
        current_time += bt[i];
        tat[i] = wt[i] + bt[i];
    }

    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Required output format
    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d %d\n", pid[i], wt[i]);
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d %d\n", pid[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
