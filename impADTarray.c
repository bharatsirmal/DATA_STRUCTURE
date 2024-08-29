#include <stdio.h>
#include <stdlib.h>
static int stack[100], n = 10, top = -1;
int x;
void push(int);
int pop();
void display();
void push(int x)
{
    if (top == n - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("Stack is empty:\n");
        return -1;
    }
    x = stack[top];
    top--;
    return x;
}
void display()

{
    if (top == -1)
    {
        printf("Empty");
    }
    printf("Stcak is:\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
}
void main()
{
    int choice;
    while (1)
    {
        printf("\n 1.PUSH \n");
        printf("\n 2.POP \n");
        printf("\n 3.DISPLAY \n");
        printf("\n 4.EXIT \n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            printf("Poped elements is: %d", x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}