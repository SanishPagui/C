#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *createList(struct node *start){
    int data,n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter the element to be inserted:");
    scanf("%d",&data);
    start=addAtBeg(start, data);
    for (int i=2;i<=n;i++) {
        if(start==NULL)
            return;
        printf("Enter the element to be inserted:");
        scanf("%d",&data);
        start=addAtEnd(start,data);
    }
    return start;
}
void display(struct node *start){
    struct node *p;
    if(start==NULL){
        printf("List is Empty\n");
        return;
    }
    p=start;
    while(p!=NULL){
        printf("%d\t",p->info);
        p=p->next;
    }
}
struct node *addToEmpty(struct node *start,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=NULL;
    temp->prev=NULL;
    start=temp;
    return start;
}
struct node *addAtBeg(struct node *start,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node)),*p;
    temp->info=data;
    p=start;
    while(p->next!=NULL)
        p=p->next;
    temp->next=NULL;
    temp->prev=p;
    p->next=temp;
    return start;
}
