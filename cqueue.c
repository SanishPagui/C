#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int front=-1;
int rear=-1;
int queue[MAX];
int isFull(){
    return ((rear+1)%MAX==front);
}
void display(){
    for(int i=0;i<MAX;i++){
        printf(" [%d]",i);
    }
    printf("\n");
    for(int i=0;i<MAX;i++){
        printf(" ___");
    }
    printf("\n|");
    for(int i=0;i<MAX;i++){
        if((i>=front && i<=rear) || (front>rear && ((i>=front || i<=rear)))){
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
    printf("Front=%-6d",front);
    printf("Rear=%d\n",rear);
}
int isEmpty(){
    return (front == -1);
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
    printf("\nInsert(%d)\n",key);
    printf("The Queue is:\n");
    display();
}
void del(){
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
    printf("\nDelete(%d)\n",key);
    printf("The deleted element is: %d\n",key);
    printf("The Queue is:\n");
    display();
}
int main(){
    insert(74);insert(27);insert(64);insert(20);del();del();del();insert(41);insert(109);insert(84);del();insert(102);del();del();del();
}