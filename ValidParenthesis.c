#include<stdio.h>
#include<stdlib.h>
struct node {
    char info;
    struct node *link;
};
struct node *top = NULL;
void push(char data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = top;
    top = temp;
}
void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}
int isBalanced(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==NULL)
                return 0;
            char removal=top->info;
            if((exp[i]==')' && removal!='(') || (exp[i]=='}' && removal!='{') || (exp[i]==']' && removal!='['))
                return 0;
            pop();
        }
    }
    return 1;
}
int main() {
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}



