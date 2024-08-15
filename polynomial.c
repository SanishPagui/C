#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
struct node* create(struct node *start){
    struct node *temp,*p=NULL;
    int n,i;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Enter the coeff and exp of each term:\n");
    temp=(struct node *)malloc(sizeof(struct node));
    scanf("%d %d",&temp->coeff,&temp->exp);
    temp->next=NULL;
    start=temp;
    p=start;
    for(i=1;i<n;i++){
        temp=(struct node *)malloc(sizeof(struct node));
        scanf("%d %d",&temp->coeff,&temp->exp);
        temp->next=NULL;
        while (p->next!=NULL && p->next->exp>temp->exp){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
        p=start;
    }
    return start;
}
void display(struct node *p){
    while (p!=NULL){
        if(p->next!=NULL){
            printf("%dx^%d + ",p->coeff,p->exp);
        }
        else{
            printf("%dx^%d",p->coeff,p->exp);
        }
        p=p->next;
    }
    printf("\n");
}
struct node* add(struct node *p, struct node *q){
    struct node *result=NULL,*last=NULL;
    while(p!=NULL && q!=NULL){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        if(p->exp>q->exp){
            temp->coeff=p->coeff;
            temp->exp=p->exp;
            p=p->next;
        }
        else if(p->exp<q->exp){
            temp->coeff=q->coeff;
            temp->exp=q->exp;
            q=q->next;
        }
        else{
            temp->coeff=p->coeff + q->coeff;
            temp->exp=p->exp;
            p=p->next;
            q=q->next;
        }
        temp->next=NULL;
        if (result == NULL){
            result=last=temp;
        }
        else{
            last->next=temp;
            last=temp;
        }
    }
    while (p != NULL){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->coeff=p->coeff;
        temp->exp=p->exp;
        temp->next=NULL;
        last->next=temp;
        last=temp;
        p=p->next;
    }
    while (q != NULL){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->coeff=q->coeff;
        temp->exp=q->exp;
        temp->next=NULL;
        last->next=temp;
        last=temp;
        q=q->next;
    }
    return result;
}
int main(){
    struct node *poly1=NULL, *poly2=NULL, *poly3=NULL;
    poly1=create(poly1);
    poly2=create(poly2);
    printf("First polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);
    poly3=add(poly1, poly2);
    printf("Resultant polynomial: ");
    display(poly3);
    return 0;
}
