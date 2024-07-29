#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *top=NULL;
void Push(int data) {
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=top;
    top=temp;
}
void Pop() {
    struct node *temp;
    if (top==NULL) {
        printf("Stack is empty\n");
        return;
    }
    temp=top;
    printf("Popped element: %d\n",temp->info);
    top=top->link;
    free(temp);
}
void Display() {
    struct node *p = top;
    if (top==NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while(p!=NULL) {
        printf("%d\t", p->info);
        p=p->link;
    }
    printf("\n");
}
void Peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->info);
}
int main() {
    int choice,data;
    do {
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
                Pop(top);
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

