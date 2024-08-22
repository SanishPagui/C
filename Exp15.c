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
    struct node *p;
    printf("    ");
    p=last->link;
    do{
        printf("___ ________     ");
        p=p->link;
    }while(p!=last->link);
    printf("\n-->|");
    p=last->link;
    do{
        if(p->info>=0 && p->info<10)
            printf("__%d|%lx|-->|",p->info,p->link); 
        else if(p->info>=10 && p->info<100)
            printf("_%d|%lx|-->|",p->info,p->link); 
        else
            printf("%d|%lx|-->|",p->info,p->link);
        p=p->link;
    }while(p!=last->link);
    printf("\n|   ");
    p=last->link;
    do{
        p=p->link;
        if(p==last->link){
            printf("   ");
            printf("%lx",p);
            printf("     ");
            break;
        }
        printf("   ");
        printf("%lx",p);
        printf("      ");
    }while(p!=last->link);
    printf("|");
    printf("\n|");
    p=last->link;
    do{
        printf("_________________");
        p=p->link;
    }while(p!=last->link);
    printf("__|\n");
}

int main(){
    int choice;
    while (1){
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                last = createList();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}