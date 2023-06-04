// C Program for Iterative Tower of Hanoi
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct node
{
    int capacity;
    int top;
    int *array;
};

// function to create a stack of given capacity.
struct node *createStack(int capacity)
{
    struct node *stack =
        (struct node *)malloc(sizeof(struct node));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array =
        (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct node *stack)
{
    return (stack->top == stack->capacity - 1); 
}

// Stack is empty when top is equal to -1
int isEmpty(struct node *stack)
{
    return (stack->top == -1);
}

// Function to add an item to stack. It increases
// top by 1
void push(struct node *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack. It
// decreases top by 1
int pop(struct node *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to show the movement of disks
void moveDisk(char fromPole, char toPole, int disk)
{
    printf("Move the disk %d from \'%c\' to \'%c\'\n",
           disk, fromPole, toPole);
}

// Function to implement legal movement between
// two poles
void moveDisksBetweenTwoPoles(struct node *p1,
                              struct node *p2, char s, char d)
{
    int pole1TopDisk = pop(p1);
    int pole2TopDisk = pop(p2);

    // When pole 1 is empty
    if (pole1TopDisk == INT_MIN)
    {
        push(p1, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }

    // When pole2 pole is empty
    else if (pole2TopDisk == INT_MIN)
    {
        push(p2, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }

    // When top disk of pole1 > top disk of pole2
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(p1, pole1TopDisk);
        push(p1, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }

    // When top disk of pole1 < top disk of pole2
    else
    {
        push(p2, pole2TopDisk);
        push(p2, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

// Function to implement TOH puzzle
void tohIterative(int disks, struct node *src, struct node *aux,
                  struct node *dest)
{
    int i, moves;
    char s = 'S', d = 'D', a = 'A';

    // If number of disks is even, then interchange
    // destination pole and auxiliary pole
    if (disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    moves = pow(2, disks) - 1; // pow is the power function x^y

    // Larger disks will be pushed first
    for (i = disks; i >= 1; i--)
        push(src, i);

    for (i = 1; i <= moves; i++)
    {
        if (i % 3 == 1)
            moveDisksBetweenTwoPoles(src, dest, s, d);

        else if (i % 3 == 2)
            moveDisksBetweenTwoPoles(src, aux, s, a);

        else if (i % 3 == 0)
            moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

// Driver Program
int main()
{
    int disks ;
    printf("Enter the Number of disks:");
    scanf("%d",&disks);
    

    struct node *src, *dest, *aux;

    // Create three stacks of size 'disks'
    // to hold the disks
    src = createStack(disks);
    aux = createStack(disks);
    dest = createStack(disks);

    tohIterative(disks, src, aux, dest);
    return 0;
}
     