#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
} * start, *last, *temp;

void create(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    if (start == NULL)
    {

        start = last = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else
    {
        last->next = newNode;

        newNode->previous = last;

        newNode->next = NULL;

        last = newNode;
    }
}
void display()
{

    struct node *trav = start;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (trav != NULL)
    {

        printf("%d ", trav->data);
        trav = trav->next;
    }
}
void begin()
{
    temp = start;
    start = start->next;
    start->previous = NULL;
    free(temp);
    printf("Node is deleted \n");
}
void end()
{
    temp = last;
    last->previous->next = NULL;
    last = last->previous;
    free(temp);
    printf("Node is deleted \n");
}
void position()
{
    int pos, i = 1;
    printf("enter the position:");
    scanf("%d", &pos);
    temp = start;
    if (pos == 0 || pos > 4)
    {
        printf("Invalid position\n");
    }
    else if (pos == 1)
    {
        begin();
    }
    else if (pos == 4)
    {
        end();
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        free(temp);
    }
}
void main()
{

    create(10);
    create(2);
    create(9);
    create(11);
    printf("Element of doubly linked list: \n");
    display();
    printf("\n\n");
    position();
    display();
    
}