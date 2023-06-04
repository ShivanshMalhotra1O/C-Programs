#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100
char stack[n];
int top = -1;

void push(int ch)
{
    top++;
    stack[top] = ch;
}

int pop()
{
    int item;
    stack[top] = item;
    top--;
    return item;
}

int main()
{
    char prefix[100];
    char ch;
    int num1, num2;
    int val, result;
    int length;

    printf("Enter the prefix expression: ");
    scanf("%s", prefix);

    length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--)
    {
        ch = prefix[i];

        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {

            num1 = stack[top];
            pop();
            num2 = stack[top];
            pop();

            switch (ch)
            {
            case '*':
                val = num2 * num1;
                break;
            case '/':
                val = num2 / num1;
                break;
            case '+':
                val = num2 + num1;
                break;
            case '-':
                val = num2 - num1;
                break;
            default:
                printf("invalid choice");
                break;
            }
            push(val);
        }
    }
    result = pop();
    printf("Result is %d", result);

    return 0;
}