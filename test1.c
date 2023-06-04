#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, int n, int weight[], int profit[])
{
    int i, item;
    int knap[n + 1][capacity + 1];
    for (i = 0; i <= n; i++)
    {
        for (item = 0; item <= capacity; item++)
        {
            if (i == 0 || item == 0)
                knap[i][item] = 0;
            else if (weight[i - 1] <= item)
                knap[i][item] = max(profit[i - 1] + knap[i - 1][item - weight[i - 1]], knap[i - 1][item]);
            else
                knap[i][item] = knap[i - 1][item];
        }
    }
    return knap[n][capacity];
}

void main()
{
    int weight[20], profit[20];
    int i, n, capacity, profit;

    printf("Enter the capacity of the knapsack:");
    scanf("%d", &capacity);

    printf("Enter the number of items:");
    scanf("%d", &n);

    printf("Enter weight and profit of each product:\n");
    for(i = 0; i < n; i++)
    {
        printf("Weight[%d]:", i);
        scanf("%d", &weight[i]);
        printf("profit[%d]:", i);
        scanf("%d", &profit[i]);
    }

    value = knapsack(capacity, n, weight, profit);

    printf("Profit is : %d", value);
}