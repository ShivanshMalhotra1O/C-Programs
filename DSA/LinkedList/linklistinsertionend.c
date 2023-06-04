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

struct node *end(struct node *start, int value)
{
    struct node *temp, *trav;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->ptr = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        trav = start;
        while (trav->ptr != NULL)
        {
            trav = trav->ptr;
        }
        trav->ptr = temp;
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

    start->data = 50;
    start->ptr = second; 

    second->data = 90;
    second->ptr = third;

    third->data = 100;
    third->ptr = NULL;

   printf("Linklist before insertion:\t");
    travel(start);
      printf("\n\n");
         printf("Linklist after insertion:\t");
      travel(start);
    start = end(start, 46);
    travel(start);
 
}