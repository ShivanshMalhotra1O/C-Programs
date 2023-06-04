#include <stdio.h>
#include<stdlib.h>

struct node
{
    int id;
    struct node *next;
} * start, *newnode, *temp;

int main()
{
    int n, i, a, count;

    printf("Enter the number of Players:");
    scanf("%d", &n);

    printf("Enter the postion of the player to be deleted:");
    scanf("%d", &a);

    start = (struct node *)malloc(sizeof(struct node));
    start->id = 1;
    temp = start;

    for (i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->id = i;
        newnode->next = start;
        temp->next = newnode;
        temp = newnode;
    }

    for (count = n; count > 1; count--)
    {
        for (i=0;i<a-1;++i){ 
            temp = temp->next;
        }
        printf("Deleted %d \n",temp->next->id);
        temp ->next = temp->next->next;
    }

    printf("\n");
    printf("Winner is : %d",temp->id);
    return 0;
}