#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int front=-1;
int rear=-1;
int queue[MAX];
int isFull(){
    if((front == 0 && rear==MAX-1) || front==rear+1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(front == -1 || front==rear+1)
        return 1;
    else
        return 0;
}

void peek(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    printf("The first element is: %d",queue[front]);
}

void insert(int key){
    if(isFull()){
        printf("Queue Overflow\n");
        return;
    }
    if(front== -1)
        front=0;
    if(rear==MAX-1)
        rear=0;
    else
        rear++;
    queue[rear]=key;
}

int del(){
    int key;
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    key=queue[front];
    if(front == rear){
        front=-1;
        rear=-1;
    }
    else if(front ==MAX-1)
        front=0;
    else
        front++;
    printf("The deleted element is: %d",key);
    return key;
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue is:\n");
    for(int i=front;i<=rear;i++)
        printf("%d\n",queue[i]);
    printf("\n");
}

int main(){
    int choice,data;
    do {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                del();
                break;
            case 3:
                display(front);
                break;
            case 4:
                peek(front);
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong Input");
        }
        printf("font=%d\trear=%d",front,rear);
        
    } while (1);
}