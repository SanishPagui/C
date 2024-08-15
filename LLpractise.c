#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *insertion(struct node *start,int data){
    struct node *temp,*p=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(start==NULL){
        start=temp;
        return start;
    }
    while(p->link!=NULL)
        p=p->link;
    p->link=temp;
    return start;
}
struct node *delete(struct node *start,int data){
    struct node *p=start,*temp;
    if(start==NULL){
        printf("Empty\n");
        return start;
    }
    if(start->info==data){
        temp=start;
        start=start->link;
        free(temp);
        printf("Deleted element is: %d\n",temp->info);
        return start;
    }
    while(p->link!=NULL){
        if(p->link->info==data){
            temp=p->link;
            p->link=p->link->link;
            printf("Deleted element is: %d\n",temp->info);
            free(temp);
            return start;
        }
        p=p->link;
    }
    printf("Not found");
    return start;
}
struct node *addAfter(struct node *start,int data,int loc){
    struct node *p=start,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    for(int i=1;p->link!=NULL && i<loc;i++)
        p=p->link;
    if(p->link==NULL){
        temp->link=NULL;
        p->link=temp;
        return start;
    }
    temp->link=p->link;
    p->link=temp;
    return start;
}
struct node *addBefore(struct node *start,int data,int loc){
    struct node *p=start,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    if(loc==1){
        temp->link=start;
        start=temp;
        return start;
    }
    for(int i=1;i<loc-1 && p!=NULL;i++)
        p=p->link;
    temp->link=p->link;
    p->link=temp;
    return start;
}
struct node *createList(struct node *start){
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n==0)
        return start;
    printf("Enter the elements\n");
    for(int i=1;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        start=insertion(start,data);
    }
    return start;
}
void count(struct node *start){
    struct node *p=start;
    int count=0;
    while(p!=NULL){
        p=p->link;
        count++;
    }
    printf("\n%d",count);
}
void search(struct node *start,int data){
    struct node *p=start;
    int loc=1;
    while(p!=NULL){
        if(p->info==data){
            printf("\nFound at location %d",loc);
            return;
        }
        loc++;
        p=p->link;
    }
}
void display(struct node *start){
    if(start==NULL){
        printf("Empty");
        return;
    }
    struct node *p=start;
    printf("\nThe list is\n");
    while(p!=NULL){ 
        printf("%d\t",p->info);
        p=p->link;
    }
}
int main(){
    struct node *start1=NULL,*result=NULL;
    start1=createList(start1);
    start1=delete(start1,5);
    display(start1);
    start1=addAfter(start1,5,1);
    display(start1);
    start1=addBefore(start1,0,1);
    display(start1);
    count(start1);
    search(start1,2);
}