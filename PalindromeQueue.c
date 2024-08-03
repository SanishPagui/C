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
    if(rear==NULL)
        front=temp;
    else    
        rear->link=temp;
    rear=temp;
    return rear;
}
void creatList(){
    int data,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    if(n==0)
        return;
    printf("Enter the elements\n");
    for(int i=1;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        rear=insert(data);
    }
}
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
struct node *reverse(struct node *secondhead){
    struct node *prev=NULL,*p=secondhead,*next;
    while(p!=NULL){
        next=p->link;
        p->link=prev;
        prev=p;
        p=next;
    }
    return prev;
}
int compare(struct node *temp1,struct node *temp2){
    struct node *p=temp1,*q=temp2;
    while(p && q){
        if(q->info == p->info){
            p=p->link;
            q=q->link;
        }
        else
            return 0;
    }
    if(p==NULL && q==NULL)
        return 1;
    return 0;
}
int isPalindrome(){
    if(front->link==NULL)
        return 1;
    struct node *p=front,*firsthalf=front,*temp=front,*secondhalf,*q=front,*middle=NULL;
    while(p!=NULL && p->link!=NULL){   //to find the middle
        temp=q;
        q=q->link;
        p=p->link->link;
    }
    if(p!=NULL){   //for odd length it will not be null
        middle=q;
        q=q->link;
    }
    secondhalf=q;
    temp->link=NULL;
    secondhalf=reverse(secondhalf);
    int result=compare(front,secondhalf);
    return result;
}
int main(){
    creatList();
    printf("Queue is\n");
    display();
    if(isPalindrome())
        printf("Palindrome");
    else
        printf("Not Palindrome");
}
// int isPalindrome(){
//     if(front->link==NULL)
//         return 1;
//     struct node *p=front;
//     int count=0;
//     while(p!=NULL){
//         count++;
//         p=p->link;
//     }
//     int *a=(int *)malloc(count*sizeof(int));
//     p=front;
//     for(int i=0;i<count;i++){
//         a[i]=p->info;
//         p=p->link;
//     }
//     for(int i=0;i<count/2;i++){
//         if(a[i]!=a[count-1-i]){

//             return 0;
//         }
//     }
//     return 1;
// }