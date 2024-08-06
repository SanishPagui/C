#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start=NULL;
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
    temp->next=NULL;
    while(p->next!=NULL)
        p=p->next;
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
    struct node *p;
    printf(" ________    ");
    for(p=start;p!=NULL;p=p->next)
        printf(" ___ ________    ");
    printf("\n|");
    printf("%lx|-->|",start);
    for(p=start;p!=NULL;p=p->next){
        if(p->next==NULL){
            printf("__%d|__NULL__|-->",p->info,p->next); 
            break;
        }
        if(p->info>=0 && p->info<10)
            printf("__%d|%lx|-->|",p->info,p->next); 
        else if(p->info>=10 && p->info<100)
            printf("_%d|%lx|-->|",p->info,p->next); 
        else
            printf("%d|%lx|-->|",p->info,p->next);
    }
    printf("NULL\n");
    int i=0;
    while(i<13){
        printf(" ");
        i++;
    }
    p=start;
    while(p!=NULL){
        printf("   ");
        printf("%lx",p);
        printf("      ");
        p=p->next;
    }
    printf("\n");
}
void swapping(){
    struct node *p=start,*prev=NULL,*q=start->next;
    while(q!=NULL){
        p->next=q->next;
        if(p->next!=NULL)
            p->next->prev=p;
        q->prev=prev;
        q->next=p;
        p->prev=q;
        if(prev==NULL)
            start=q;
        else
            prev->next=q;
        prev=p;
        p=p->next;
        if(p!=NULL)
            q=p->next;
        else
            q=NULL;
    }
    if(p!=NULL)
        p->next=NULL;
}
int main(){
    createList();
    printf("The Linked list before swapping\n");
    display();
    printf("The Linked list after swapping\n");
    swapping();
    display();
}