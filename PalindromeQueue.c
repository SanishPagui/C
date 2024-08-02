#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
struct node *insert(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Overflow\n");
        return rear;
    }
    temp->info=data;
    temp->link=NULL;
    if(front==rear)
        front=temp;
    else    
        rear=rear->link;
    rear=temp;
}
void delete(){
    struct node *temp;
    int key;
    if(front==NULL){
        printf("Underflow\n");
        return;
    }
    key=front->info;
    temp=front;
    front=front->link;
    free(temp);
}
void creatList(){
    int data,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    if(n==0)
        return;
    printf("Enter the elements\n");
    printf("Element 1: ");
    scanf("%d",&data);
    rear=insert(data);
    for(int i=2;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        rear=insert(data);
    }
}
void display(){
    
}
int main(){
    creatList();
}