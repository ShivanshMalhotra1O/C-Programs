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
struct node *between(struct node *start, int value)
{
    struct node *temp, *trav, *ti = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;

    if (start == NULL)
    {
        start = temp;
        temp->ptr = NULL;
    }
    else
    {
        trav = start;
        while (trav->data < value && trav != NULL)
        {
            ti = trav;
            trav = trav->ptr;
        }
    }

    if (ti == NULL)
    {
        temp->ptr = start;
        start = temp;
    }
    // else if (trav->ptr == NULL)
    // {
    //     temp->ptr = NULL;
    //     trav->ptr = temp;
    // }

    else
    {
        ti->ptr = temp;
        temp->ptr = trav;
    }
    return start;
}
void main()
{
    struct node *start;
    struct node *second;
    struct node *third;

    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    start->data = 2;
    start->ptr = second;

    second->data = 10;
    second->ptr = third;

    third->data = 200;
    third->ptr = NULL;

    printf("Original Linklist");
    printf("\n");
    travel(start);
    printf("\n");
    printf("Linklist after insertion");
    printf("\n");
    start = between(start, 16);
    travel(start);
}