#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
void insert(int key){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Queue Overflow\n");
        return;
    }
    temp->info=key;
    temp->link=NULL;
    if(front == NULL)
        front=temp;
    else
        rear->link=temp;
    rear=temp;
}
int peek(){
    if(front==NULL){
        printf("Queue Underflow");
        exit(1);
    }
    return front->info;
}
void delete(){
    struct node *temp;
    int key;
    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }
    key=front->info;
    temp=front;
    front=front->link;
    free(temp);
    printf("The deleted element is %d",key);
}
void display(){
    if(front==NULL){
        printf("Queue Underflow");
        return;
    }
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d\t",temp->info);
        temp=temp->link;
    }
}
int main(){
    int choice,data;
    do {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong Input");
        }
    } while (1);
}