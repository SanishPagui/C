#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *front=NULL,*rear=NULL,*top=NULL;
struct node* insertQueue(int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
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
struct node* pushStack(int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=top;
    top=temp;
    return top;
}
struct node* reverse(struct node *head){
    struct node *prev=NULL,*current=head,*next;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    return prev;
}
int compare(struct node *list1,struct node *list2){
    struct node *p=list1,*q=list2;
    while(p&&q){
        if(p->info!=q->info)
            return 0;
        p=p->link;
        q=q->link;
    }
    return (p==NULL&&q==NULL);
}
int isPalindrome(struct node *head){
    if(head==NULL||head->link==NULL)
        return 1;
    struct node *second=head,*first=head,*prev=NULL;
    struct node *second_half=NULL,*middle=NULL;
    while(first!=NULL&&first->link!=NULL){
        prev=second;
        second=second->link;
        first=first->link->link;
    }
    if(first!=NULL){
        middle=second;
        second=second->link;
    }
    second_half=reverse(second);
    prev->link=NULL;
    int result=compare(head,second_half);
    second_half=reverse(second_half);
    if(middle!=NULL){
        prev->link=middle;
        middle->link=second_half;
    }else
        prev->link=second_half;
    return result;
}
void displayQueue(){
    struct node *p;
    printf(" ________    ");
    for(p=front;p!=NULL;p=p->link)
        printf(" ___ ________    ");
    printf("\n|");
    printf("%lx|-->|",front);
    for(p=front;p!=NULL;p=p->link){
        if(p->link==NULL){
            printf("__%d|__NULL__|",p->info); 
            break;
        }
        if(p->info>=0 && p->info<10)
            printf("__%d|%lx|-->|",p->info,p->link); 
        else if(p->info>=10 && p->info<100)
            printf("_%d|%lx|-->|",p->info,p->link); 
        else
            printf("%d|%lx|-->|",p->info,p->link);
    }
    printf("\n");
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
void displayStack(){
    struct node *p=top;
    printf(" ________    ");
    while(p!=NULL){
        p=p->link;
        if(p==NULL){
            printf(" ___ ________");
            break;
        }
        printf(" ___ ________    ");
    }
    p=top;
    printf("\n|");
    printf("%lx|-->",p);
    while(p!=NULL){
        if(p->link==NULL){
            printf("|");
            printf("_%d_|__NULL__|",p->info);
            break;
        }
        printf("|");
        printf("_%d_|%lx|-->",p->info,p->link);
        p=p->link;  
    }
    printf("\n");
    int i=0;
    while(i<13){
        printf(" ");
        i++;
    }
    p=top;
    while(p!=NULL){
        printf("   ");
        printf("%lx",p);
        printf("      ");
        p=p->link;
    }
    printf("\n");
}

int main(){
    int n,data;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=1;i<=n;i++){
        printf("Element %d: ",i);
        scanf("%d",&data);
        insertQueue(data);
        pushStack(data);
    }
    printf("The numbers in Queue:\n");
    displayQueue();
    printf("The numbers in Stack:\n");
    displayStack();
    if(isPalindrome(front)&&isPalindrome(top))
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");
}
