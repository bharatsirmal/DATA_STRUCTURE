#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;
int size;
void push(char item)
{
}
void infixTopostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item, x;
    push('(');
    strcat(infix_exp, ")");
    i = 0;
    j = 0;
    item = infix_exp[i];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_opeartor(item) == 1)
        {
            x = pop();
            while (is_opeartor(x) == 1 && (precendence(x) >= precendence(item)))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
        }
        else if (item = ')')
        {
            x = pop();
            while (x != '(')
                postfix_exp[j] = x;
            j++;
            x = pop();
        }
        else
        {
        }
        i++;
        item = infix_exp[i];
    }
    postfix_exp = '\0';
}

