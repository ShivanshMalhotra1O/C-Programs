#include <stdio.h>

// Function to calculate waiting time and turn around time
void calculateTimes(int n, int burstTime[], int quantum)
{
    int remainingTime[n];
    int waitingTime[n];
    int turnAroundTime[n];

    // Copy the burst times to the remaining time array
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = burstTime[i];
    }

    int time = 0;      // Current time
    int completed = 0; // Number of processes completed execution

    // Continue until all processes are completed
    while (completed < n)
    {
        // Traverse all processesx`
        for (int i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0)
            {
                // Process is not completed yet

                // Execute the process for the quantum time or remaining time, whichever is smaller
                int executeTime = (remainingTime[i] < quantum) ? remainingTime[i] : quantum;

                // Update the remaining time
                remainingTime[i] -= executeTime;

                // Update the current time
                time += executeTime;

                if (remainingTime[i] == 0)
                {
                    // Process is completed
                    completed++;

                    // Calculate waiting time
                    waitingTime[i] = time - burstTime[i];

                    // Calculate turn around time
                    turnAroundTime[i] = waitingTime[i] + burstTime[i];
                }
            }
        }
    }

    // Calculate average waiting time and average turn around time
    double avgWaitingTime = 0;
    double avgTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        avgWaitingTime += waitingTime[i];
        avgTurnAroundTime += turnAroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnAroundTime /= n;

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }
    printf("Average waiting time: %.2f\n", avgWaitingTime);
    printf("Average turnaround time: %.2f\n", avgTurnAroundTime);
}

// Test the code
int main()
{
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n]; // Burst time for each process

    // Get burst time for each process
    for (int i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]); 
    }

    int quantum; // Time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Calculate waiting time and turn around time using Round Robin algorithm
    calculateTimes(n, burstTime, quantum);

    return 0;
}
