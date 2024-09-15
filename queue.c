#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int front=-1;
int rear=-1;
int queue[MAX];
void display(){
    printf("\nQueue is:\n");
    for(int i=0;i<MAX;i++){
        printf(" [%d]",i);
    }
    printf("\n");
    for(int i=0;i<MAX;i++){
        printf(" ___");
    }
    printf("\n|");
    for(int i=0;i<MAX;i++){
        if(i>=front && i<=rear){
            if(queue[i]>=0 && queue[i]<10)
                printf("__%d",queue[i]);
            else if(queue[i]>=10 && queue[i]<100)
                printf("_%d",queue[i]);
            else if(queue[i]>=100)
                printf("%d",queue[i]);
        } 
        else{
            printf("___");
        }
        printf("|");
    }
    printf("\n");
    printf("Front=%d\t    Rear=%d",front,rear);
    printf("\n");
}
void insert(int key){
    if(rear == MAX-1){
        printf("\nInsert(%d)",key);
        printf("\nQueue Overflow\n");
        return;
    }
    if(front== -1)
        front=0;
    queue[++rear]=key;
    printf("\nInsert(%d)",key);
    display();
}
int del(){
    int key;
    if(front == -1 || front==rear+1){
        printf("\nQueue Underflow\n");
        exit(1);
    }
    key=queue[front++];
    printf("\nDelete()");
    display();
    printf("The deleted element is: %d\n",key);
    return key;
}
void peek(){
    if(front==-1){
        printf("Queue Empty\n");
        return;
    }
    printf("The first element in the queue is: %d\n",queue[front]);
}
int main(){
    insert(1);insert(1);insert(1);insert(1);insert(1);insert(1);insert(1);
}