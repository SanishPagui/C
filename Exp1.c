#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *CreateList(struct node *start);
struct node *AddAtBeg(struct node *start, int data);
struct node *AddAtEnd(struct node *start, int data);
struct node *DeleteNode(struct node *start, int data);
void Display(struct node *start);
struct node *InsertAtPosition(struct node *start,int data,int loc);
struct node *CreateList(struct node *start){
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    start=NULL;
    if(n==0) return start;
    for(int i=1;i<=n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",&data);
        start=AddAtEnd(start,data);
    }
    return start;
}
struct node *AddAtBeg(struct node *start, int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
}
struct node *AddAtEnd(struct node *start, int data){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(start==NULL) return temp;
    p=start;
    while(p->link!=NULL) p=p->link;
    p->link=temp;
    return start;
}
struct node *InsertAtPosition(struct node *start,int data,int loc){
    struct node *temp,*p=start;
    int i;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(loc==1){
        start=AddAtBeg(start,temp->info);
        return start;
    }
    for(i=2,p=start;p!=NULL;p=p->link,i++){
        if(i==loc){
            temp->link=p->link;
            p->link=temp;
            return start;
        }
    }
    AddAtEnd(start,temp->info);
    return start;
}
struct node *AddBefore(struct node *start,int data,int key){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(start->info==key){
        start=AddAtBeg(start,temp->info);
        return start;
    }
    for(p=start;p!=NULL;p=p->link){
        if(p->link->info==key){
            temp->link=p->link;
            p->link=temp;
            return start;
        }
    }
}
struct node *AddAfter(struct node *start,int data,int key){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    for(p=start;p->link!=NULL;p=p->link){
        if(p->info==key){
            temp->link=p->link;
            p->link=temp;
            return start;
        }
    }
    start=AddAtEnd(start,temp->info);
    return start;
}
void Search(struct node *start,int data){
    struct node *p=start;
    int loc=1;
    while(p!=NULL){
        if(p->info==data){
            printf("%d found at location %d\n",data,loc);
            return;
        }
        loc++;
        p=p->link;
    }
    printf("Not found\n");
}
void Count(struct node *start){
    struct node *p=start;
    int count=0;
    while(p!=NULL){
        p=p->link;
        count++;
    }
    printf("The elements in the list are: %d\n",count);
}
struct node *DeleteNode(struct node *start, int data){
    struct node *temp,*p;
    if(start==NULL){
        printf("List is empty\n");
        return start;
    }
    if(start->info==data){
        temp=start;
        start=start->link;
        free(temp);
        return start;
    }
    p=start;
    while(p->link!=NULL){
        if(p->link->info==data){
            temp=p->link;
            p->link=temp->link;
            free(temp);
            return start;
        }
        p=p->link;
    }
    printf("Node not found\n");
    return start;
}
void Display(struct node *start){
    struct node *p;
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    p=start;
    printf("List:\n");
    while(p!=NULL){
        printf("%d",p->info);
        p=p->link;
        if(p!=NULL) 
            printf(", ");
    }
    printf("\n");
}
int main(){
    struct node *start=NULL;
    int choice,data,loc;
    do{
        printf("\n1. Create List\n2. Display List\n3. Delete Node\n4. Add at End\n5.Add at Beginning\n6.Add at Position\n7.Search\n8.Count\n9.Add Before a node\n10.Add After a node\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                start=CreateList(start);
                break;
            case 2: 
                Display(start); 
                break;
            case 3: 
                printf("Enter the data to delete: "); 
                scanf("%d",&data); 
                start=DeleteNode(start,data); 
                break;
            case 4: 
                printf("Enter the data to insert at end: "); 
                scanf("%d",&data); 
                start=AddAtEnd(start,data); 
                break;
            case 5: 
                printf("Enter the data to insert at beginning: "); 
                scanf("%d",&data); 
                start=AddAtBeg(start,data); 
                break;
            case 6:
                printf("Enter the data to insert at a position: ");
                scanf("%d",&data);
                printf("Enter the location: ");
                scanf("%d",&loc);
                start=InsertAtPosition(start,data,loc);
                break;
            case 7:
                printf("Enter the data you want to search for: ");
                scanf("%d",&data);
                Search(start,data);
                break;
            case 8:
                Count(start);
                break;
            case 9:
                printf("Enter the data: ");
                scanf("%d",&data);
                printf("Enter the element to put the data before this element: ");
                scanf("%d",&loc);
                AddBefore(start,data,loc);
                break;
            case 10:
                printf("Enter the data: ");
                scanf("%d",&data);
                printf("Enter the element to put the data after this element: ");
                scanf("%d",&loc);
                AddAfter(start,data,loc);
                break;
            case 11: 
                exit(1);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }while(1);
    return 0;
}
