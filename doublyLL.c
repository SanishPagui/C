#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start;
struct node *addAtBeg(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL){
        temp->prev=NULL;
        temp->next=NULL;
    }
    temp->prev=NULL;
    temp->next=start;
    start=temp;
    return start;
}
struct node *addAtEnd(int data){
    struct node *temp,*p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    while(p->next!=NULL)
        p=p->next;
    p->next=temp;
    temp->prev=p;
    temp->next=NULL;
    return start;
}
struct node *insertBefore(int loc,int data){
    struct node *temp,*p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    for(int i=1;i<loc-1 && p!=NULL;i++)
        p=p->next;
    temp->next=p->next;
    p->next=temp;
    temp->prev=p;
    return start;
}
struct node *insertAfter(int loc,int data){
    struct node *temp,*p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    for(int i=1;i<loc && p!=NULL;i++)
        p=p->next;
    temp->next=p->next;
    p->next=temp;
    temp->prev=p;
    return start;
}
struct node *createList(){
    int n,data;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    if(n==0)
        return start;
    printf("Enter the elments\nElement 1: ");
    scanf("%d",&data);
    start=addAtBeg(data);
    for(int i=2;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        start=addAtEnd(data);
    }
    return start;
}
void display(){
    struct node *p=start;
    if(start==NULL){
        printf("List is empty");
        return ;
    }
    while(p!=NULL){
        printf("%d\t",p->info);
        p=p->next;
    }
    printf("\n");
}
int main(){
    createList();
    display();
    display(insertBefore(3,10));
    display(insertAfter(3,11));
}