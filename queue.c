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
        printf("\nDelete(%d)",key);
        printf("\nQueue Underflow\n");
        exit(1);
    }
    key=queue[front++];
    printf("\nDelete()");
    display();
    printf("The deleted element is: %d\n",key);
    return key;
}

int main(){
    int choice,data;
    insert(85);
    insert(107);
    insert(105);
    insert(25);
    insert(23);
    del();
    del();
    insert(57);
    del();
    del();
    del();
    del();
    insert(13);
    del();
    del();
}