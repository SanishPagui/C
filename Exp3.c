#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node *CreateList(struct node *);
struct node *AddAtBeg(struct node *,int);
struct node *AddAtEnd(struct node *,int);
int Equal(struct node *,int);
struct node *Union(struct node *,struct node *);
struct node{
    int info;
    struct node *link;
};
struct node *CreateList(struct node *start){
    int n,data;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;
    printf("Enter the element to be inserted:");
    scanf("%d",&data);
    start=AddAtBeg(start,data);
    for(int i=2;i<=n;i++){
        printf("Enter the element to be inserted:");
        scanf("%d",&data);
        start=AddAtEnd(start,data);
    }
    return start;
}
struct node *AddAtBeg(struct node *start,int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
};
struct node *AddAtEnd(struct node *start, int data){
        if(Equal(start,data))
            return start;
        struct node *p=start,*temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=NULL;
        if(start==NULL)
            return temp;
        if (start->info>data){
            temp->link=start;
            return temp;
        }
        while(p->link!=NULL && p->link->info<data)
            p=p->link;
        temp->link=p->link;
        p->link=temp;
        return start;
}
struct node *Union(struct node *start1,struct node *start2){
    struct node *p=start1,*temp=NULL;
    while(p!=NULL){
        temp=AddAtEnd(temp,p->info);
        p=p->link;
    }
    p=start2;
    while(p!=NULL){
        temp=AddAtEnd(temp,p->info);
        p=p->link;
    }
    return temp;
}
struct node *Intersection(struct node *start1, struct node *start2) {
    struct node *temp=NULL,*p=start1,*q;
    while(p!=NULL){
        q=start2;
        while(q!=NULL) {
            if(p->info==q->info){
                temp=AddAtEnd(temp,p->info);
                break;
            }
            q=q->link;
        }
        p=p->link;
    }
    return temp;
}
struct node *Subtraction(struct node *start1, struct node *start2){
    struct node *temp=NULL,*p1=start1,*p2;
    int found;
    while (p1!=NULL){
        p2=start2;
        found=0;
        while(p2!=NULL){
            if(p1->info==p2->info){
                found=1;
                break;
            }
            p2=p2->link;
        }
        if(!found){
            temp=AddAtEnd(temp, p1->info);
        }
        p1=p1->link;
    }
    return temp;
}
void Display(struct node *start){
    struct node *p;
    if(start==NULL){
        printf("List is Empty");
        return;
    }
    p=start;
    printf("{");
    while(p!=NULL){
        printf("%d",p->info);
        if(p->link==NULL)
            break;
            printf(",");
        p=p->link;
    }
    printf("}");
}
int Equal(struct node *start, int data){
    struct node *p = start;
    while (p != NULL){
        if (p->info == data){
            return 1;
        }
        p = p->link;
    }
    return 0;
}
int main(){
    struct node *start1=NULL,*start2=NULL,*result=NULL;
    int choice,n;
    char wish;
    printf("List 1\n");
    start1=CreateList(start1);
    printf("List 2\n");
    start2=CreateList(start2);
    printf("\nList 1: ");
    Display(start1);
    printf("\nList 2: ");
    Display(start2);
    printf("\n\nL1 u L2: ");
    result=Union(start1,start2);
    Display(result);
    printf("\n\nL1 n L2: ");
    result=Intersection(start1,start2);
    Display(result);
    printf("\n\nSubtraction(L1-L2): ");
    result=Subtraction(start1,start2);
    Display(result);
    printf("\n\nSubtraction(L2-L1): ");
    result=Subtraction(start2,start1);
    Display(result);
    
}
