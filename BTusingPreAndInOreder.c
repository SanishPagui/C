#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct listNode{
    char info;
    struct listNode *next;
} *preptr=NULL,*inptr=NULL;
struct treeNode{
    struct treeNode *lchild;
    char info;
    struct treeNode *rchild;
};
struct treeNode *construct(struct listNode *preptr,struct listNode *inStart,int n);
void preorder(struct treeNode *temp);
void inorder(struct treeNode *temp);
struct listNode *addAtEnd(struct listNode *start,char data);
struct listNode *CreateList(struct listNode *start);
int getLevel(struct treeNode *root);
int count(struct listNode *list);
void levelOrder(struct treeNode *root,char arr[],int size);
void printStructuredTree(char arr[],int size,int levels);

struct treeNode *construct(struct listNode *preptr,struct listNode *inStart,int n) {
    if(n<=0||preptr==NULL)
        return NULL;
    struct treeNode *root=(struct treeNode *)malloc(sizeof(struct treeNode));
    root->info=preptr->info;
    root->lchild=root->rchild=NULL;
    if(n==1)
        return root;
    struct listNode *inn=inStart;
    int leftTreeSize=0;
    while(inn != NULL && inn->info != root->info) {
        inn=inn->next;
        leftTreeSize++;
    }
    if(inn==NULL) {
        printf("Error: Mismatch between preorder and inorder traversals.\n");
        exit(1);
    }
    int rightTreeSize=n - leftTreeSize - 1;
    root->lchild=construct(preptr->next, inStart, leftTreeSize);
    struct listNode *rightInStart=inn->next;
    struct listNode *nextPreptr=preptr;
    for(int i=0;i<=leftTreeSize;i++) {
        nextPreptr=nextPreptr->next;
    }
    root->rchild=construct(nextPreptr,rightInStart,rightTreeSize);
    return root;
}

int getLevel(struct treeNode *root){
    if(root==NULL)
        return -1;
    int leftLevel=getLevel(root->lchild);
    int rightLevel=getLevel(root->rchild);
    return(leftLevel>rightLevel?leftLevel:rightLevel)+1;
}
struct listNode *addAtEnd(struct listNode *start,char data){
    struct listNode *temp,*p;
    temp=(struct listNode *)malloc(sizeof(struct listNode));
    temp->info=data;
    temp->next=NULL;
    if(start==NULL) 
        return temp;
    p=start;
    while(p->next!=NULL)
        p=p->next;
    p->next=temp;
    return start;
}
struct listNode *CreateList(struct listNode *start){
    int n;
    char data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;
    printf("Enter the characters in order:\n");
    for(int i=0;i<n;i++){
        printf("Node %d: ",i+1);
        scanf(" %c",&data);
        start=addAtEnd(start,data);
    }
    return start;
}
void levelOrder(struct treeNode *root,char arr[],int size){
    if(root==NULL)
        return;
    struct treeNode *queue=(struct treeNode *)malloc(size * sizeof(struct treeNode));
    int front=0,rear=0;
    queue[rear++]=*root;
    int n=0;
    while(front<rear && n<size){
        struct treeNode current=queue[front++];
        if(current.info!=' ')
            arr[n++]=current.info;
        else 
            arr[n++]=' ';
        if(current.lchild!=NULL)
            queue[rear++]=*(current.lchild);
        if(current.rchild!=NULL)
            queue[rear++]=*(current.rchild);
    }
    while(n<size)
        arr[n++]=' ';
    free(queue);
}

void printStructuredTree(char arr[],int size,int levels){
    int n=0;
    for(int level=0;level<=levels;level++){
        int nodesInLevel=pow(2,level);
        int spaceBetweenNodes=pow(2,levels-level+1)-1;
        int initialSpace=pow(2,levels-level)-1;
        for(int i=0;i<initialSpace;i++)
            printf(" ");
        for(int i=0;i<nodesInLevel && n<size;i++){
            if(arr[n]!=' '){
                printf("%c",arr[n]);
                if(i<nodesInLevel-1){
                    for(int j=0;j<spaceBetweenNodes;j++)
                        printf(" ");
                }
            } 
            else{
                printf(" ");
                if(i<nodesInLevel-1){
                    for(int j=0;j<spaceBetweenNodes;j++)
                        printf(" ");
                }
            }
            n++;
        }
        printf("\n");
    }
}
void preorder(struct treeNode *ptr){
    if(ptr==NULL)
        return;
    printf("%c ",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(struct treeNode *ptr){
    if(ptr==NULL)
        return;
    inorder(ptr->lchild);
    printf("%c ",ptr->info);
    inorder(ptr->rchild);
}
char *createArray(struct treeNode *root,char *ptr,int i){
    if(root==NULL){
        *(ptr+i)=' ';
        return ptr;
    }
    *(ptr+i)=root->info;
    ptr=createArray(root->lchild,ptr,i*2+1);
    ptr=createArray(root->rchild,ptr,i*2+2);
    return ptr;
}

int count(struct listNode *list){
    struct listNode *p=list;
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int main(){
    printf("Creating the Preorder List:\n");
    preptr=CreateList(preptr);
    printf("\nCreating the Inorder List:\n");
    inptr=CreateList(inptr);
    int c=count(preptr);
    struct treeNode *root=construct(preptr,inptr,c);
    int level=getLevel(root);
    printf("\nTree Levels: %d\n",level);
    int maxNodes=pow(2,level+1)-1;
    char *levelarr=(char *)malloc(maxNodes * sizeof(char));
    levelOrder(root,levelarr,maxNodes);
    printf("\nLevel Order Traversal:\n");
    for(int i=0;i<maxNodes;i++){
        if(levelarr[i]!=' ')
            printf("%c ",levelarr[i]);
    }
    char *arr=(char *)malloc(maxNodes * sizeof(char));
    createArray(root,arr,0);
    printf("\n");
    printf("\nPreorder Traversal:\n");
    preorder(root);
    printf("\n");
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\n");
    printf("\nStructured Tree Representation:\n");
    printStructuredTree(arr,maxNodes,level);
    free(arr);
    return 0;
}
