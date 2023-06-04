#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
char stack[100];
int top = -1;

void push(int item)
{
    top++;
    stack[top] = item;
}

char pop()
{
    char item;
    item = stack[top];
    top--;
    return item;
}

int infixtopostfix(char postfix[])
{
    int result , op1 , op2;
    char item;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        item = postfix[i];

        if (item == '+' || item == '-' || item == '*' || item == '/')
        {
            op1 = pop();
            op2 = pop();

            switch (item)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }

            push(result);
        }

        else
        {
            push(item-48);  // We have done this because we are taking item as char whearas it is in integer in the push function therefore we are converting char to integer by subtracting 48 from the ASCII valus of temp.
        }
    }

    result = pop();
    printf("%d", result);
}

int main()
{
    char postfix[100];
    printf("enter the postfix expression:\n");
    scanf("%s", postfix);
    printf("Expression after evaluation :\n");
    infixtopostfix(postfix);

    return 0;
}