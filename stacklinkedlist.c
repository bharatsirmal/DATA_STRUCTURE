#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *stack;

void push(int x)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = stack;
    stack = new;
}

int pop()
{
    int x;
    struct node *ptr;
    if (stack == NULL)
    {
        printf("stack is full");
    }
    else
    {
        x = stack->data;
        ptr = stack;
        stack = stack->next;
        free(ptr);
        return x;
    }
}

void display()
{
    struct node *temp = stack;
    if (stack == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("stack elements :\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int ch, x;
    while (1)
    {
        printf("1.push \n");
        printf("2.pop \n");
        printf("3.display \n");
        printf("4. exit \n");
        printf("Enter your choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element \n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            printf("element is popped from the stack is %d \n", x);

            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}