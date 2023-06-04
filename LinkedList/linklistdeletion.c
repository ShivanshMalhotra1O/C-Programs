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

struct node *delete (struct node *start, int value)
{
    struct node *trav, *pretrav;
    if (start == NULL)
    {
        printf("underflow");
    }
    else
    {
        trav = start;
        while (trav->data != value && trav->ptr != NULL)
        {
            pretrav = trav;
            trav = trav->ptr;
        }
        if (trav == start)
        {
            start = start->ptr;
            printf("Element to be deleting:\t\t%d", trav->data);

            free(trav);
        }
        else if (trav->data == value)
        {
            pretrav->ptr = trav->ptr;
            printf("Element to be deleting:\t\t%d", trav->data);

            free(trav);
        }
        else
        {
            printf("node not found");
        }
    }
    return start;
}

int main()
{
    struct node *start;
    struct node *second;
    struct node *third;

    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    start->data = 5;
    start->ptr = second;

    second->data = 26;
    second->ptr = third;

    third->data = 50;
    third->ptr = NULL;

    printf("\n\n");

    printf("Linklist before deletion:\t");

    travel(start);

    printf("\n\n");

    start = delete (start, 50);

    printf("\n\n");

    printf("Linklist after deletion:\t");

    travel(start);

    printf("\n\n");
    
    return 0;
}