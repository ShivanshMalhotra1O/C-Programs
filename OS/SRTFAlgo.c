#include <stdio.h>
#include <stdbool.h>

void srtf(int arrivalTime[], int burstTime[], int n)
{
    int remainingTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0;
    int completed = 0;

    while (completed != n)
    {
        int shortestIndex = -1;
        int shortestTime = 9999; // A large value to represent infinity

        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= currentTime && remainingTime[i] < shortestTime && remainingTime[i] > 0)
            {
                shortestIndex = i;
                shortestTime = remainingTime[i];
            }
        }

        if (shortestIndex == -1)
        {
            currentTime++;
            continue;
        }

        // Execute the process for one unit of time
        remainingTime[shortestIndex]--;
        currentTime++;

        if (remainingTime[shortestIndex] == 0)
        {
            completed++;
            int turnaroundTime = currentTime - arrivalTime[shortestIndex];
            int waitingTime = turnaroundTime - burstTime[shortestIndex];
            printf("Process %d: Burst Time = %d, Waiting Time = %d, Turnaround Time = %d\n", shortestIndex + 1,
                   burstTime[shortestIndex], waitingTime, turnaroundTime);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n];
    int burstTime[n];
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }

    srtf(arrivalTime, burstTime, n);

    return 0;
}
