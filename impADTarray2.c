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
    struct node *ptr;
    if (stack == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        int x = stack->data;
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
        printf("stack elements are:\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int choice, x, stack;
    while (1)
    {
        printf("\n 1.push \n");
        printf("\n 2.pop \n");
        printf("\n 3.display \n");
        printf("\n 4.exit \n");
        printf("Enter the your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element:\n");
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