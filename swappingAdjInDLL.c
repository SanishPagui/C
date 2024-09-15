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
        exit(1);
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
    printf(" ____    ");
    for(p=start;p!=NULL;p=p->next)
        printf(" ____ ___ ____    ");
    printf("\n|");
    printf("    |   ");
    for(p=start;p!=NULL;p=p->next){
        if(p->next==NULL){
            printf("|    |   |    |   ");
            break;
        }
        printf("|    |   |    |-->");
    }
    printf("\n|");
    printf("%04hhX|-->|",start);
    for(p=start;p!=NULL;p=p->next){
        if(p->prev==NULL){
            printf("NULL|%3d|%04hhX|   |",p->info,p->next); 
            continue;
        }
        if(p->next==NULL){
            printf("%04hhX|%3d|NULL|   ",p->prev,p->info); 
            break;
        }
        if(p->info>=0 && p->info<10)
            printf("%04hhX|%3d|%04hhX|   |",p->prev,p->info,p->next); 
        else if(p->info>=10 && p->info<100)
            printf("%04hhX|%d|%04hhX|   |",p->prev,p->info,p->next); 
        else
            printf("%02hhX|%d|%02hhX|   |",p->prev,p->info,p->next);
    }
    printf("\n|");
    printf("____|");
    for(p=start;p!=NULL;p=p->next){
        if(p->prev==NULL){
            printf("   |____|___|____|");
            continue;
        }
        printf("<--|____|___|____|");
    }
    printf("\n");
    int i=0;
    while(i<9){
        printf(" ");
        i++;
    }
    p=start;
    while(p!=NULL){
        printf("     ");
        printf("%04hhX",p);
        printf("         ");
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