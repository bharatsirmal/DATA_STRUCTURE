// priority queue unorder array:
#include <stdio.h>
#include <stdlib.h>
int queue[100], rear = -1, front = -1;
int n = 10;

void enqueue(int x)
{
    if (rear == n - 1)
    {
        printf("Queue is full");
    }
    else
    {
        rear++;
        queue[rear] = x;
        if (front == -1)
        {
            front = 0;
        }
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        int a = front;
        for (int i = front + 1; i <= rear; i++)
        {
            if (queue[i] > queue[a])
            {
                a = i;
            }
        }
        int x = queue[a];
        for (int i = a; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear++;

        if (rear < front)
        {
            rear = -1;
            front = -1;
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
            enqueue(x);
            break;
        case 2:
            x = dequeue();
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