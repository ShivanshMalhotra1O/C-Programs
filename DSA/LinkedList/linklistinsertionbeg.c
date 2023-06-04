#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

void travel(struct node *trav)
{
    while (trav != NULL)
    {
        printf("%d\t", trav->data);
        trav = trav->ptr;
    }
}

struct node *begin(struct node *start, int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if (start == NULL)
    {
        temp->ptr = NULL;
    }
    else
    {
        temp->ptr = start;
    }
    return temp; 
}

void main()
{
    struct node *start;
    struct node *second;
    struct node *third;

    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    start->data = 56;
    start->ptr = second;

    second->data = 78;
    second->ptr = third;

    third->data = 94;
    third->ptr = NULL;

    printf("\n\n");

    printf("Linklist before insertion:\t");

    travel(start);

    start = begin(start, 9);

    printf("\n\n");

    printf("Linklist after insertion at begining:\t");

    travel(start);

    printf("\n\n");
    
}
