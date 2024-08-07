#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *last=NULL;
void display(){
    struct node *p;
    if(last==NULL){
        printf("List is empty\n");
        return;
    }
    p=last->link;
    do{
        printf("%d\t",p->info);
        p=p->link;
    }while(p!=last->link);
}
struct node *addToEmpty(int data){
}