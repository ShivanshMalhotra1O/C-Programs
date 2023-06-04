#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int power;
    struct Node *next;
};

struct Node *insertValue(struct Node *head, int value, int power)
{
    struct Node *temp;
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = value;
    new->power = power;
    new->next = NULL;

    
    if (head == NULL || power > head->power)
    {
        new->next = head;
        head = new;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->power >= power)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    return head;
}

struct Node *create(struct Node *head)
{
    int n, i;
    int value;
    int power;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the term %d: ", i);
        scanf("%d", &value);
        printf("Enter the power of variable %d: ", i);
        scanf("%d", &power);
        head = insertValue(head, value, power);
    }
    return head;
}

void triverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("No polynomial was added.");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d x^%d", temp->data, temp->power);
            temp = temp->next;
            if (temp != NULL)
            {
                printf("+");
            }
        }
    }
}

void polyAdd(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    struct Node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->power == ptr2->power)
        {
            head3 = insertValue(head3, ptr1->data + ptr2->data, ptr1->power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->power > ptr2->power)
        {
            head3 = insertValue(head3, ptr1->data, ptr1->power);
            ptr1 = ptr1->next;
        }
        else if (ptr1->power < ptr2->power)
        {
            head3 = insertValue(head3, ptr2->data, ptr2->power);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insertValue(head3, ptr1->data, ptr1->power);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = insertValue(head3, ptr2->data, ptr2->power);
        ptr2 = ptr2->next;
    }
    printf("After addition: ");
    triverse(head3);
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    printf("Enter the first polynomial\n");
    head1 = create(head1);
    printf("\nEnter the second polynomial\n");
    head2 = create(head2);
    polyAdd(head1, head2);
    return 0;
}   