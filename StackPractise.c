#include<stdio.h>
#define MAX 4
int top=-1;
int stack[MAX];
void display(){
    for(int i=top;i>=0;i--)
        printf("%d\t",stack[i]);
    printf("\n");
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    int data=stack[top--];
    printf("Deleted %d\n",data);
    display();
}
void push(int data){
    if(top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=data;
    display();
}
int main(){
    push(1);
    pop();
    push(2);
    push(3);
    pop();
    push(4);
    push(5);
    push(6);
    push(7);
    push(7);
    push(7);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
}