#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int stack[50], top = -1;

void sum();
void diff();
void mult();
void Div();
void power();

void main()
{
    char str[30];
    int i;

    printf("Enter the postfix:");
    scanf("%[^\n]s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            switch (str[i])
            {
            case '+':
                sum();
                break;
            case '-':
                diff();
                break;
            case '*':
                mult();
                break;
            case '/':
                Div();
                break;
            case '^':
                power();
                break;
            default:
                top++;
                stack[top] = str[i] - 48;
            }
        }
    }
    printf("\nThe result is=%d", stack[top]);
}

void sum()
{
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op1 + op2;
    top++;
    stack[top] = res;
}
void diff()
{
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op1 - op2;
    top++;
    stack[top] = res;
}
void mult()
{
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op1 * op2;
    top++;
    stack[top] = res;
}
void Div()
{
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op1 / op2;
    top++;
    stack[top] = res;
}
void power()
{
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = pow(op2, op1);
    top++;
    stack[top] = res;
}