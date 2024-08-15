#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node *CreateList(struct node *);
struct node *AddAtBeg(struct node *, int);
struct node *AddAtEnd(struct node *, int);
struct node *Delete(struct node *, int);
struct node *InsertAtPosition(struct node *, int, int);
void Display(struct node *);
void Count(struct node *);
struct node *Reverse(struct node *);
void Search(struct node *, int);
struct node {
    int info;
    struct node *link;
};
struct node *CreateList(struct node *start) {
    int n, data;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the element to be inserted:");
    scanf("%d", &data);
    start = AddAtBeg(start, data);
    for (int i = 2; i <= n; i++) {
        printf("Enter the element to be inserted:");
        scanf("%d", &data);
        start = AddAtEnd(start, data);
    }
    return start;
}
struct node *AddAtBeg(struct node *start, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    start = temp;
    return start;
}
struct node *AddAtEnd(struct node *start, int data) {
    struct node *temp, *p = start;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;
    if(start == NULL){
        start=temp;
        return start;
    }
    while (p->link != NULL)
        p = p->link;
    p->link = temp;
    return start;
}
struct node *InsertAtPosition(struct node *start, int data, int loc) {
    struct node *temp, *p = start;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    if (loc == 1) {
        temp->link = start;
        start = temp;
        return start;
    }
    for (int i = 1; i < loc - 1 && p != NULL; i++)
        p = p->link;
    if (p == NULL) {
        printf("Less elements than position %d\n", loc);
        return start;
    }
    temp->link = p->link;
    p->link = temp;
    return start;
}
struct node *Delete(struct node *start, int data) {
    struct node *temp, *p = start;
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    if (start->info == data) {
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    while (p->link != NULL) {
        if (p->link->info == data) {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return start;
        }
        p = p->link;
    }
    printf("Element not found\n");
    return start;
}
struct node *Reverse(struct node *start) {
    struct node *prev = NULL, *next, *ptr = start;
    while (ptr != NULL) {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
}
void Count(struct node *start) {
    struct node *p = start;
    int count = 0;
    while (p != NULL) {
        p = p->link;
        count++;
    }
    printf("The number of elements in the list are %d\n", count);
}
void Display(struct node *start) {
    struct node *p;
    if (start == NULL) {
        printf("List is Empty\n");
        return;
    }
    p = start;
    while (p != NULL) {
        printf("%d\t", p->info);
        p = p->link;
    }
    printf("\n");
}
void Search(struct node *start, int key) {
    struct node *p = start;
    int pos = 1;
    while (p != NULL) {
        if (p->info == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Element is not present in the list\n");
}
int main() {
    struct node *start1 = NULL, *result = NULL;
    int data, choice, n, loc;
    do {
        printf("\n1. Create A List");
        printf("\n2. Display The List");
        printf("\n3. Count The Elements In The List");
        printf("\n4. Search An Element In The List");
        printf("\n5. Insert In The Beginning");
        printf("\n6. Insert At The End");
        printf("\n7. Insert At A Specific Position");
        printf("\n8. Deletion of An Element");
        printf("\n9. Reverse A List");
        printf("\n10. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start1 = CreateList(start1);
                break;
            case 2:
                Display(start1);
                break;
            case 3:
                Count(start1);
                break;
            case 4:
                printf("Enter the element: ");
                scanf("%d", &data);
                Search(start1, data);
                break;
            case 5:
                printf("Enter the element: ");
                scanf("%d", &data);
                start1 = AddAtBeg(start1, data);
                break;
            case 6:
                printf("Enter the element: ");
                scanf("%d", &data);
                start1 = AddAtEnd(start1, data);
                break;
            case 7:
                printf("Enter the element: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &loc);
                start1 = InsertAtPosition(start1, data, loc);
                break;
            case 8:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                start1 = Delete(start1, data);
                break;
            case 9:
                start1 = Reverse(start1);
                break;
            case 10:
                exit(1);
            default:
                printf("\nWrong Input");
        }
        
    } while (1);
    return 0;
}
