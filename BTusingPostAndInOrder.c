#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct listNode {
    char info;
    struct listNode *next;
} *postptr = NULL, *inptr = NULL;
struct treeNode {
    struct treeNode *lchild;
    char info;
    struct treeNode *rchild;
};
struct treeNode *construct(struct listNode *postptr, struct listNode *inptr, int n);
void postorderTraversal(struct treeNode *temp);
void inorderTraversal(struct treeNode *temp);
struct listNode *addAtEnd(struct listNode *start, char data);
struct listNode *CreateList(struct listNode *start);
int getLevel(struct treeNode *root);
int count(struct listNode *list);
void levelOrder(struct treeNode *root, char arr[], int size);
void printStructuredTree(char arr[], int size, int levels);
struct treeNode *createNode(int data) {
  struct treeNode *newNode = (struct treeNode *)malloc(sizeof(struct treeNode));
  if (newNode == NULL) {
    printf("Memory allocation failed!");
    exit(1);
  }
  newNode->info = data;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}
struct treeNode *construct(struct listNode *postptr, struct listNode *inptr, int n) {
    if (n == 0 || postptr == NULL || inptr == NULL) {
        return NULL;
    }
    struct listNode *p = postptr;
    for (int i = 1; i < n; i++) {
        p = p->next;
    }
    struct treeNode *tmp = createNode(p->info);
    if (n == 1) {
        return tmp;
    }
    struct listNode *q = inptr;
    int i = 0;
    while (q != NULL && q->info != p->info) {
        i++;
        q = q->next;
    }
    tmp->lchild = construct(postptr, inptr, i);
    struct listNode *postptrRight = postptr;
    for (int j = 0; j < i; j++) {
        postptrRight = postptrRight->next;
    }
    tmp->rchild = construct(postptrRight, q->next, n - i - 1);
    return tmp;
}
int getLevel(struct treeNode *root) {
    if (root == NULL)
        return -1;
    int leftLevel = getLevel(root->lchild);
    int rightLevel = getLevel(root->rchild);
    return (leftLevel > rightLevel ? leftLevel : rightLevel) + 1;
}
struct listNode *addAtEnd(struct listNode *start, char data) {
    struct listNode *temp, *p;
    temp = (struct listNode *)malloc(sizeof(struct listNode));
    temp->info = data;
    temp->next = NULL;
    if (start == NULL)
        return temp;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    return start;
}
struct listNode *CreateList(struct listNode *start) {
    int n;
    char data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the characters in order:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf(" %c", &data);
        start = addAtEnd(start, data);
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
void postorderTraversal(struct treeNode *ptr) {
    if (ptr == NULL)
        return;
    postorderTraversal(ptr->lchild);
    postorderTraversal(ptr->rchild);
    printf("%c ", ptr->info);
}
void inorderTraversal(struct treeNode *ptr) {
    if (ptr == NULL)
        return;
    inorderTraversal(ptr->lchild);
    printf("%c ", ptr->info);
    inorderTraversal(ptr->rchild);
}
int count(struct listNode *list) {
    struct listNode *p = list;
    int c = 0;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
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
int main() {
    printf("Creating the Postorder List:\n");
    postptr = CreateList(postptr);
    printf("\nCreating the Inorder List:\n");
    inptr = CreateList(inptr);
    int c = count(postptr);
    struct listNode *postEnd = postptr;
    while (postEnd->next != NULL)
        postEnd = postEnd->next;
    struct treeNode *root = construct(postptr, inptr, c);
    int level = getLevel(root);
    printf("\nTree Levels: %d\n", level);
    int maxNodes = pow(2, level + 1) - 1;
    char *levelarr = (char *)malloc(maxNodes * sizeof(char));
    levelOrder(root, levelarr, maxNodes);
    printf("\nLevel Order Traversal:\n");
    for (int i = 0; i < maxNodes; i++) {
        if (levelarr[i] != ' ')
            printf("%c ", levelarr[i]);
    }
    char *arr=(char *)malloc(maxNodes * sizeof(char));
    createArray(root,arr,0);
    printf("\n\nPostorder Traversal:\n");
    postorderTraversal(root);
    printf("\n");
    printf("\nInorder Traversal:\n");
    inorderTraversal(root);
    printf("\n");
    printf("\nStructured Tree Representation:\n");
    printStructuredTree(arr, maxNodes, level);
    free(arr);
    return 0;
}
