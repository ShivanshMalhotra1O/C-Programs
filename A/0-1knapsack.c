#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, int no_items, int weight[], int value[])
{

    int i, item;
    int knap[no_items + 1][capacity + 1];
    for (i = 0; i <= no_items; i++)
    {
        for (item = 0; item <= capacity; item++)
        {
            if (i == 0 || item == 0)
                knap[i][item] = 0;
            else if (weight[i - 1] <= item)
                knap[i][item] = max(value[i - 1] + knap[i - 1][item - weight[i - 1]], knap[i - 1][item]);
            else
                knap[i][item] = knap[i - 1][item];
        }
    }
    return knap[no_items][capacity];
}

void main()
{
    int weight[20], value[20];
    int i, no_items, capacity, profit;

    printf("Enter the capacity of the knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter weight and value of each product:\n");
    for (i = 0; i < no_items; i++)
    {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }

    profit = knapsack(capacity, no_items, weight, value);

    printf("Profit:\t%d\n", profit);
}
