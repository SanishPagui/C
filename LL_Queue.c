#include<stdio.h>
#include<stdlib.h>
void display(){
    if(front==NULL){
        printf("Queue Underflow");
        return;
    }
    struct node *temp=front;
    printf("\n");
    for(temp=front;temp!=NULL;temp=temp->link){
        printf(" ___");
    }
    while(temp!=NULL){
        printf("%d\t",temp->info);
        temp=temp->link;
    }
}
struct node{
    int info;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
void insert(int key){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Queue Overflow\n");
        return;
    }
    temp->info=key;
    temp->link=NULL;
    if(front == NULL)
        front=temp;
    else
        rear->link=temp;
    rear=temp;
    display();
}
int peek(){
    if(front==NULL){
        printf("Queue Underflow");
        exit(1);
    }
    return front->info;
}
void delete(){
    struct node *temp;
    int key;
    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }
    key=front->info;
    temp=front;
    front=front->link;
    free(temp);
    printf("\nThe deleted element is %d\n",key);
}
int main(){
    insert(85);insert(107);insert(105);insert(25);insert(23);delete();delete();insert(57);delete();delete();delete();delete();insert(13);delete();delete();
}