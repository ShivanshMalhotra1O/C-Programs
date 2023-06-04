#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
} * front, *temp;

void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

struct node*enqueue(int value, int priority)
{

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->priority = priority;

    if (front == NULL)
    {
        newnode->next = NULL;
        front = temp = newnode;
    }
    else
    {
        if (temp->priority > newnode->priority)
        {
            temp->next = newnode;
            newnode->next = NULL;
            ;
        }
        else if (temp->priority < newnode->priority)
        {
            newnode->next = temp;
            temp = newnode;
            
        }
    }
    return newnode;
}

int main()

{
    int value, priority, i;
    struct node * queue;

    

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter the value: ");
        scanf("%d", &value);
        printf("Enter the priority: ");
        scanf("%d", &priority);
        queue = enqueue(value, priority);
    }

    printf("\nQueue is :");
    printf("\n");
    display(queue);
    return 0;
}