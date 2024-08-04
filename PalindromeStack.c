#include<stdio.h>
#include<stdlib.h>
void display();
struct node{
    int info;
    struct node *link;
};
struct node *top=NULL;
struct node *push(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=top;
    top=temp;
    return top;
}
void pop(){
    struct node *temp;
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    int key=top->info;
    temp=top;
    top=top->link;
    free(temp);
    printf("The deleted element is %d\n",key);
}
void display(){
    struct node *p=top;
    printf(" ________    ");
    while(p!=NULL){
        p=p->link;
        if(p==NULL){
            printf(" ___ _______");
            break;
        }
        printf(" ___ ________    ");
    }
    p=top;
    printf("\n|");
    printf("%.6x|-->",p);
    while(p!=NULL){
        if(p==NULL)
            printf("NULL");
        if(p->link==NULL){
            printf("|");
            printf("_%d_|___%lx___|",p->info,p->link);
            break;
        }
        printf("|");
        printf("_%d_|%lx|-->",p->info,p->link);
        p=p->link;  
    }
    printf("\n");
    int i=0;
    while(i<13){
        printf(" ");
        i++;
    }
    p=top;
    while(p!=NULL){
        printf("   ");
        printf("%lx",p);
        printf("      ");
        p=p->link;
    }
    printf("\n");
}
int compare(struct node *temp1,struct node *temp2){
    struct node *p=temp1,*q=temp2;
    while(p && q){
        if(p->info!=q->info)
            return 0;
        p=p->link;
        q=q->link;
    }
    if(p==NULL && q==NULL)
        return 1;
    return 0;
}
struct node *reverse(struct node *secondhead){
    struct node *prev=NULL,*p=secondhead,*next;
    while(p!=NULL){
        next=p->link;
        p->link=prev;
        prev=p;
        p=next;
    }
    return prev;
}
int isPalindrome(){
    if(top->link==NULL)
        return 1;
    int num=top->info;
    struct node *p=top,*q=top,*temp=NULL,*secondhalf=NULL,*middle=NULL;
    while(p!=NULL && p->link!=NULL){
        temp=q;
        q=q->link;
        p=p->link->link;
    }
    if(p!=NULL){
        middle=q;
        q=q->link;
    }
    secondhalf=q;
    temp->link=NULL;
    secondhalf=reverse(secondhalf);
    int result=compare(top,secondhalf);
    return result;
}
int main(){
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=1;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        push(data);
    }
    display();
    if(isPalindrome())
        printf("Palindrome");
    else
        printf("Not Palindrome");
}