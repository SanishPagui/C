#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top=-1;
void Push(char);
char Pop();
int OperatorPrecedence(char);
void InfixToPostfix(char *,char *);
int EvaluatePostfix(char *);
void Push(char c){
    if(top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[top]=c;
}
char Pop(){
    if (top==-1){
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
int OperatorPrecedence(char c){
    if (c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if (c=='+' || c=='-')
        return 1;
    else
        return -1;
}
void InfixToPostfix(char *infix,char *postfix){
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isdigit(infix[i]) || isalpha(infix[i])){
            postfix[j++]=infix[i];
        } 
        else if(infix[i]=='('){
            Push(infix[i]);
        }
        else if(infix[i]==')'){
            while (stack[top]!='(') {
                postfix[j++]=Pop();
            }
            Pop();
        } 
        else{
            while(top!= -1 && OperatorPrecedence(stack[top])>=OperatorPrecedence(infix[i])) {
                postfix[j++]=Pop();
            }
            Push(infix[i]);
        }
        i++;
    }
    while(top!= -1){
        postfix[j++]=Pop();
    }
    postfix[j]='\0';
}
int EvaluatePostfix(char *postfix){
    int stack[MAX];
    int top= -1;
    for (int i=0;postfix[i]!='\0'; i++) {
        if(isdigit(postfix[i])){
            stack[++top]=postfix[i]-'0';
        }
        else{
            int val1=stack[top--];
            int val2=stack[top--];
            switch(postfix[i]){
                case '+':
                stack[++top]=val2+val1;
                break;
                case '-':
                stack[++top]=val2-val1;
                break;
                case '*':
                stack[++top]=val2*val1;
                break;
                case '/':
                stack[++top]=val2/val1;
                break;
            }
        }
    }
    return stack[top];
}
int main() {
    char infix[MAX],postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s",infix);
    InfixToPostfix(infix,postfix);
    printf("Postfix expression: %s\n",postfix);
    printf("Evaluation of postfix expression: %d\n",EvaluatePostfix(postfix));
    return 0;
}
