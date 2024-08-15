#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
void display(){
    struct node *p;
    printf(" ________    ");
    for(p=front;p!=NULL;p=p->link)
        printf(" ___ ________    ");
    printf("\n|");
    printf("%lx|-->|",front);
    for(p=front;p!=NULL;p=p->link){
        if(p->link==NULL){
            printf("__%d|__NULL__|-->",p->info,p->link); 
            break;
        }
        if(p->info>=0 && p->info<10)
            printf("__%d|%lx|-->|",p->info,p->link); 
        else if(p->info>=10 && p->info<100)
            printf("_%d|%lx|-->|",p->info,p->link); 
        else
            printf("%d|%lx|-->|",p->info,p->link);
    }
    printf("NULL\n");
    int i=0;
    while(i<13){
        printf(" ");
        i++;
    }
    p=front;
    while(p!=NULL){
        printf("   ");
        printf("%lx",p);
        printf("      ");
        p=p->link;
    }
    printf("\n");
}
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
    display();
}
// int peek(){
//     if(front==NULL){
//         printf("Queue Underflow");
//         exit(1);
//     }
//     return front->info;
// }
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
    printf("\nThe deleted element is %d\n",key);
    display();
}
int main(){
    insert(85);
    insert(107);
    insert(105);
    insert(25);
    insert(23);
    delete();
    delete();
    insert(57);
    delete();
    delete();
    delete();
    delete();
    insert(13);
    delete();
    delete();
}