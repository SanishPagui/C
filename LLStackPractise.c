#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
void display(struct node *top){
    struct node *p=top;
    if(top==NULL){
        printf("Empty\n");
        exit(1);
    }
    while(p!=NULL){
        printf("%d\t",p->info);
        p=p->link;
    }
    printf("\n");
}
struct node *push(struct node *top,int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=top;
    top=temp;
    return top;
}
struct node *pop(struct node *top){
    struct node *temp;
    if(top==NULL){
        printf("Empty\n");
        exit(1);
    }
    temp=top;
    top=top->link;
    printf("Popped element: %d\n",temp->info);
    free(temp);
    display(top);
    return top;
}
struct node *createList(struct node *top){
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n==0)
        return top;
    printf("Enter the elements\n");
    for(int i=1;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        top=push(top,data);
        display(top);
    }
    return top;
}
int main() {
    struct node *top=NULL;
    top=createList(top);
    top=pop(top);
    top=push(top,10);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
}