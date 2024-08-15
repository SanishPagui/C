#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int expo;
    struct node *link;
};
struct node *insert(struct node *start,float co,int ex){
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=co;
    temp->expo=ex;
    if(start==NULL || start->expo<ex){
        temp->link=start;
        start=temp;
    }
    else{
        ptr=start;
        while(ptr->link!=NULL && ptr->link->expo>ex)
            ptr=ptr->link;
        temp->link=ptr->link;
        ptr->link=temp;
    }
    return start;
}
struct node *insertNew(struct node *start,float co,int ex){
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=co;
    temp->expo=ex;
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else{
        ptr=start;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=temp;
    }
    return start;
}
struct node *add(struct node *start1,struct node *start2){
    struct node *start3=NULL,*p=start1,*q=start2;
    while(p!=NULL && q!=NULL){
        int sum;
        if(p->expo==q->expo){
            sum=p->coeff+q->coeff;
            start3=insertNew(start3,sum,p->expo);
            p=p->link;
            q=q->link;
        }
        else if(p->expo>q->expo){
            start3=insert(start3,p->coeff,p->expo);
            p=p->link;
        }
        else{
            start3=insert(start3,q->coeff,q->expo);
            q=q->link;
        }
    }
    while(p!=NULL){
        start3=insert(start3,p->coeff,p->expo);
        p=p->link;
    }
    while(q!=NULL){
        start3=insert(start3,q->coeff,q->expo);
        q=q->link;
    }
    return start3;
}
struct node *createList(struct node *start){
    int n,i,ex,co;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Coefficient: ");
        scanf("%d",&co);
        printf("Exponent: ");
        scanf("%d",&ex);
        start=insert(start,co,ex);
    }
    return start;
}
void display(struct node *start){
    struct node *p=start;
    while(p!=NULL){
        printf("%dx^%d",p->coeff,p->expo);
        if(p->link==NULL)
            break;
        printf(" + ");
        p=p->link;
    }
    printf("\n");
}
int main(){
    struct node *start1=NULL,*start2=NULL,*result=NULL;
    start1=createList(start1);
    start2=createList(start2);
    display(start1);
    display(start2);
    result=add(start1,start2);
    display(result);
}
