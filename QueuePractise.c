#include<stdio.h>
#define MAX 4
int front=-1;
int rear=-1;
int queue[MAX];
void display(){
    for(int i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
    printf("\n");
}
void insert(int data){
    if(rear==MAX-1){
        printf("Overflow\n");
        return;
    }
    if(front==-1)
        front=0;
    queue[++rear]=data;
    display();
}
void delete(){
    if(front==-1  || front==rear+1){
        printf("Underflow\n");
        return;
    }
    int data=queue[front++];
    printf("Deleted %d\n",data);
    display();
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    delete();
    delete();
    insert(5);
    insert(6);
    delete();
    insert(7);
    delete();
    delete();
    delete();
}
