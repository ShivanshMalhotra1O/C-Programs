#include <stdio.h>

void sjf(int burstTime[], int n)
{
    int waitingTime[n], turnaroundTime[n], completionTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Calculate completion time for each process
    completionTime[0] = burstTime[0];
    for (int i = 1; i < n; i++)
    {
        completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        waitingTime[i] = completionTime[i] - burstTime[i];
        turnaroundTime[i] = completionTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    sjf(burstTime, n);

    return 0;
}
