// implement circle queue ADT using array:
#include <stdio.h>
#include <stdlib.h>
#define N 5
int Cqueue[N];
int front = -1, rear = -1;
void enqueue(int x)
{
    if ((rear + 1) % N == front)
    {
        printf("Queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        Cqueue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        Cqueue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        printf("Dequeue is:%d ", Cqueue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeue elements is:%d", Cqueue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is:\n");
        while (i != rear)
        {
            printf("%d\t", Cqueue[i]);
            i = (i + 1) % N;
        }
        printf("%d", Cqueue[rear]);
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
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}