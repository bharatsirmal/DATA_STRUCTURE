// priority Queue order array
#include <stdio.h>
#include <stdlib.h>
int queue[100], rear = -1, front = -1;
int n = 10;

void insertq(int x)
{
    int i;
    if (rear == n - 1)
    {
        printf("Queue is full");
    }
    if (rear == -1)
    {
        rear++;
        queue[rear] = x;
        front++;
    }
    else
    {
        for (i = rear; i >= front; i--)
        {
            if (queue[i] > x)
            {
                queue[i + 1] = queue[i];
            }
            else
            {
                break;
            }
        }
        queue[i + 1] = x;
        rear++;
    }
}

int deletq()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        int x = queue[front];
        if (rear == front)
        {
            rear = front = -1;
        }
        else
        {
            front++;
        }
        return x;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}

void main()
{
    int choice, x;
    while (1)
    {
        printf("\n 1.Enqueue \n");
        printf("\n 2.Dequeue \n");
        printf("\n 3.Display \n");
        printf("\n 4.Exit \n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the elements:");
            scanf("%d", &x);
            insertq(x);
            break;
        case 2:
            x = deletq();
            printf("Deleted elements is:%d", x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}