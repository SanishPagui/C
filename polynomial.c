#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
struct node* create(struct node *start){
    struct node *t,*q=NULL;
    int n,i;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Enter the coeff and exp of each term:\n");
    t=(struct node *)malloc(sizeof(struct node));
    scanf("%d %d",&t->coeff,&t->exp);
    t->next=NULL;
    start=t;
    q=start;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        scanf("%d %d",&t->coeff,&t->exp);
        t->next=NULL;
        while (q->next!=NULL && q->next->exp>t->exp){
            q=q->next;
        }
        t->next=q->next;
        q->next=t;
        q=start;
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
        struct node *t=(struct node *)malloc(sizeof(struct node));
        if(p->exp>q->exp){
            t->coeff=p->coeff;
            t->exp=p->exp;
            p=p->next;
        }
        else if(p->exp<q->exp){
            t->coeff=q->coeff;
            t->exp=q->exp;
            q=q->next;
        }
        else{
            t->coeff=p->coeff + q->coeff;
            t->exp=p->exp;
            p=p->next;
            q=q->next;
        }
        t->next=NULL;
        if (result == NULL){
            result=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
    while (p != NULL){
        struct node *t=(struct node *)malloc(sizeof(struct node));
        t->coeff=p->coeff;
        t->exp=p->exp;
        t->next=NULL;
        last->next=t;
        last=t;
        p=p->next;
    }
    while (q != NULL){
        struct node *t=(struct node *)malloc(sizeof(struct node));
        t->coeff=q->coeff;
        t->exp=q->exp;
        t->next=NULL;
        last->next=t;
        last=t;
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
