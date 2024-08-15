#include<stdio.h>
#define MAX 4
int rear=-1;
int front=-1;
int cqueue[MAX];
void display(){
    for(int i=front;i<=rear;i++)
        printf("%d\t",cqueue[i]);
    printf("\n");
}
void insert(int data){
    if(front==(rear+1)%MAX){
        printf("Overflow\n");
        return;
    }
    if(front==-1)
        front=0;
    if(rear==MAX-1)
        rear=0;
    else
        rear++;
    cqueue[rear]=data;
    display();
}
void del(){
    if(front==-1){
        printf("Underflow\n");
        return;
    }
    int data=cqueue[front];
    if(front==rear)
        front=rear=-1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
    printf("Deleted %d\n",data);
    display();
}
int main(){
    insert(74);insert(27);insert(64);insert(20);del();del();del();insert(41);insert(109);insert(84);del();insert(102);del();del();del();
}