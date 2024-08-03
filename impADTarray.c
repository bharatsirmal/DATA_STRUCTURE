//implemantation ADT of stack using array
#include<stdio.h>
#include<stdlib.h>
static int s[],top=-1;
int x,n=10;
int a;
void main(){
    void push(int);
    int pop();
    void display();
    void exit();
    while(1){
        printf("\n 1. PUSH:\n");
        printf("\n 2. POP:\n");
        printf("\n 3. Display\n");
        printf("\n 4. exit\n");
        printf("Enter your choice\n");
        scanf("%d",&a);
        switch(a){
            case 1:
            printf("the push element is:");
            push(x);
            break;
            case 2:
            printf("\npoped elements is\n");
            x=pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);


        }
    }

}
void push(int x){
    if(top==n-1){
        printf("Stack is full\n");
    }
    else{
        top++;
        s[top]=x;
    }
}
int pop(){
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        x=s[top];
        top--;
        return x;

    }
}
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are:\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d",s[i]);
        }
}}
