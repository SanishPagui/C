#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *last=NULL;
struct node *addToEmpty(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    last=temp;
    last->link=last;
    return last;
}
struct node *addAtEnd(int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=last->link;
    last->link=temp;
    last=temp;
    return last;
}
struct node *createList(){
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    printf("Element 1: ");
    scanf("%d",&data);
    last=addToEmpty(data);
    for(int i=2;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        last=addAtEnd(data);
    }
    return last;
}
void display(){
    struct node *p=last->link;
    printf("\n");
    do{
        printf("%d\t",p->info);
        p=p->link;
    }while(p!=last->link);
    printf("\n");
}
void deleteAltNodes(){
    struct node *p,*temp;
    if(last==NULL){
        printf("List Empty\n");
        return;
    }
    p=last->link;
    do{
        temp=p->link;
        p->link=temp->link;
        if(temp==last){
            last=p;
        }
        free(temp);
        p=p->link;
    }while(p!=last->link && p->link!=last->link);
}
int main(){
    createList();
    display();
    deleteAltNodes();
    display();
}