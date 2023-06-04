#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *previous;
    int data;
    struct node *next;
} * start, *temp ;


void create(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->previous = NULL;
    newnode->next = NULL;
     
    if (start == NULL)
    {
        start = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->previous = temp;
        temp = newnode;
    }
}
void display()
{
    struct node *temp = start;

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void begin(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->previous = NULL;
    start->previous = newnode;
    newnode->next = start;
    start = newnode;
}

void end(int value)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (start == NULL)
    {
        newnode->previous = NULL;
        newnode->next = NULL;
        start  = newnode;
    }

    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->previous = temp;
        newnode->next = NULL;
    }
}

void position(int value)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    int i = 1;
    int pos;
    printf("Enter the postion :");
    scanf("%d", &pos);

    if (pos == 0 || pos > 4)
    {
        printf("invalid position");
    }
    else if (pos == 1)
    {
        begin(value);
    }
    else if (pos == 4)
    {
        end(value);
    }
    else
    {
        temp = start;
        newnode->data = value;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->previous = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        temp->next->previous = newnode;
    }
}
void main()
{
    create(5);
    create(4);
    create(10);
    create(9);

    int value;
    printf("Element of linked list \n");
    display();

    printf("\n\n");
    printf("Enter the value you want to insert :");
    scanf("%d", &value);

    printf("\n");

    position(value);

    printf("\n");
    display();
    printf("\n\n");
}