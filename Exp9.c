#include<stdio.h>
#include<stdlib.h>
struct node {
    char info;
    struct node *link;
};
struct node *top=NULL;
struct node *disp=NULL;
void display(){
    struct node *p=disp;
    printf(" ________    ");
    while(p!=NULL){
        p=p->link;
        if(p==NULL){
            printf(" ___ _______");
            break;
        }
        printf(" ___ ________    ");
    }
    p=disp;
    printf("\n|");
    printf("%.6x|-->",p);
    while(p!=NULL){
        if(p==NULL)
            printf("NULL");
        if(p->link==NULL){
            printf("|");
            printf("_%c_|___%lx___|",p->info,p->link);
            break;
        }
        printf("|");
        printf("_%c_|%lx|-->",p->info,p->link);
        p=p->link;  
    }
    printf("\n");
    int i=0;
    while(i<13){
        printf(" ");
        i++;
    }
    p=disp;
    while(p!=NULL){
        printf("   ");
        printf("%lx",p);
        printf("      ");
        p=p->link;
    }
    printf("\n");
}
void disppush(char data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=disp;
    disp=temp;
}
void push(char data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=top;
    top=temp;
}
void pop(){
    struct node *temp;
    if (top==NULL){
        printf("Stack is empty\n");
        return;
    }
    temp=top;
    char c=temp->info;
    top=top->link;
    free(temp);
}
int isBalanced(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
            disppush(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==NULL)
                return 0;
            char removal=top->info;
            if((exp[i]==')' && removal!='(') || (exp[i]=='}' && removal!='{') || (exp[i]==']' && removal!='['))
                return 0;
            disppush(exp[i]);
            pop();
        }
    }
    display();
    return top==NULL;
}
int main(){
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s",exp);
    if (isBalanced(exp))
        printf("\n\nBalanced\n");
    else
        printf("\nNot Balanced\n");
}