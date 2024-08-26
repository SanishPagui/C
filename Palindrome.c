#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct node {
    char info;
    struct node* link;
};
struct node* top = NULL,* front = NULL,* rear = NULL;
struct node;
struct node;
void push(char item) {
    struct node* tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    tmp->info = item;
    tmp->link = top;
    top = tmp;
}
char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return CHAR_MIN;
    }
    char item = top->info;
    struct node* p = top;
    top = top->link;
    free(p);
    return item;
}
void insert(char data) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    tmp->info = data;
    tmp->link = NULL;
    if (front == NULL) {
        front = tmp;
    } else {
        rear->link = tmp;
    }
    rear = tmp;
}
char delete() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return CHAR_MIN;
    }
    struct node* tmp = front;
    char data = tmp->info;
    front = front->link;
    free(tmp);
    return data;
}
int palindrome(const char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        insert(str[i]);
        push(str[i]);
        i++;
    }
    while(top!=NULL && front!=NULL){
        char a=pop();
        char b=delete();
        if (a!=b){
            return 0;   
        }
    }
    return 1;
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
            printf("__%c|__NULL__|",p->info); 
            break;
        }
        printf("_%c_|%lx|-->|",p->info,p->link);
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
            printf("_%c_|__NULL__|",p->info);
            break;
        }
        printf("|");
        printf("_%c_|%lx|-->",p->info,p->link);
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
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int i=0;
    while (str[i] != '\0') {
        insert(str[i]);
        push(str[i]);
        i++;
    }
    printf("STACK:\n");
    displayStack(str);
    printf("Queue:\n");
    displayQueue(str);
    while(top!=NULL && front!=NULL){
        char a=pop();
        char b=delete();
    }
    if (palindrome(str)){
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
}
