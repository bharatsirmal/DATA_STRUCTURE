// queue implement using linked list:
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front, *rear;

void insertq(int x)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    if (front == NULL)
    {
        front = rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}
int deletq()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        int x = front->data;
        ptr = front;
        front = front->next;
        free(ptr);
        return x;
    }
}

void display()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is:");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int choice, x;
    while (1)
    {
        printf("\n 1.Insert \n");
        printf("\n 2.Delete \n");
        printf("\n 3.Display \n");
        printf("\n 4.Exit \n");
        printf("Enter your chpice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d", &x);
            insertq(x);
            break;
        case 2:
            x = deletq();
            printf("Deleted element is: %d", x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid !");
        }
    }
}