#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
} * head, *temp;

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void enqueue(int value, int priority)
{

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->priority = priority;

    if (head == NULL)
    {
        newnode->next = NULL;
        head = temp = newnode;
    }

    else if (head->priority < newnode->priority)
    {
        newnode->next = head;
        head = newnode;
    }

    else if (head->priority > newnode->priority)
    {
        temp = head;
        while (temp->next != NULL && temp->next->priority > newnode->priority)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void dequeue()
{
    temp = head;
    head = head->next;
    free(temp);
}

void peek()
{
    printf("%d\n", head->data);
}

int main()

{
    int value, priority, i;
    int order;

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter the value: ");
        scanf("%d", &value);
        printf("Enter the priority: ");
        scanf("%d", &priority);
        enqueue(value, priority);
    }

    printf("\nQueue is :");
    display();
    printf("\n");
    printf("\n");
    printf("highest priority value is : ");
    peek();
    printf("\n");
    printf("After dequeue hightest order value are : ");
    dequeue();
    display();
    printf("\n");
    return 0;
} 