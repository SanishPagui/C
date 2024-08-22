#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int stack[MAX];
int top=-1;
void Push(int data){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=data;
}
int Pop(){
    int savepoint;
    if(top== -1){
        printf("Stack Underflow\n");
        return -1;
    }
    savepoint=stack[top--];
    printf("The popped element is %d",savepoint);
    return savepoint;
}
void Peek(){
    if(top== -1){
        printf("Stack is Empty\n");
        return;
    }
    printf("The top element is: %d\n",stack[top]);
    return stack[top];
}
void Display(){
    if(top== -1){
        printf("Stack is Empty\n");
        return;
    }
    printf("Contents of the stack\n");
    for(int i=top;i>=0;i--)
        printf("%d\t",stack[i]);
    printf("\n");
}
int main(){
    int choice,data,top;
    do{
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&data);
                Push(data);
                break;
            case 2:
                Pop();
                break;
            case 3:
                Display(top);
                break;
            case 4:
                Peek(top);
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong Input");
        }
    } while (1);
}