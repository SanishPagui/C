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
void swapping(){
    struct node *p=start;
    int temp;
    if(p->next==NULL){
        printf("Only one element");
        return;
    }
    while(p!=NULL){
        temp=p->info;
        p->info=p->next->info;
        p->next->info=temp;
        p=p->next->next;
    }
    display();
}
int main(){
    createList();
    pritnf("The Linked list before swapping\n");
    display();
    pritnf("The Linked list after swapping\n");
    swapping();
}