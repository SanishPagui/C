#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
void display(){
    struct node *p=front;
    while(p!=NULL){
        printf("%d\t",p->info);
        p=p->link;
    }
    printf("\n");
}
void insert(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Queue Overflow\n");
        return;
    }
    temp->info=data;
    temp->link=NULL;
    if(front==NULL)
        front=temp;
    else
        rear->link=temp;
    rear=temp;
    display();
}
void delete(){
    if(front==NULL){
        printf("Empty\n");
        return;
    }
    struct node *temp;
    temp=front;
    front=front->link;
    printf("The deleted element is %d\n",temp->info);
    free(temp);
    display();
}
int main(){
    insert(85);
    insert(107);
    insert(105);
    insert(25);
    insert(23);
    delete();
    delete();
    insert(57);
    delete();
    delete();
    delete();
    delete();
    insert(13);
    delete();
    delete();
}