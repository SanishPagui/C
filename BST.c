#include<stdio.h>
#include<stdlib.h>
struct tree{
    int info;
    struct tree *lchild;
    struct tree *rchild;
};
struct tree *search(struct tree *ptr,int data){
    if(ptr==NULL){
        printf("Not found");
        return NULL;
    }
    else if(data<ptr->info)
        return search(ptr->lchild,data);
    else if(data>ptr->info)
        return search(ptr->rchild,data);
    else
        return ptr;
}
struct tree *insert(struct tree *ptr,int key){
    if(ptr==NULL){
        ptr=(struct tree *)malloc(sizeof(struct tree));
        ptr->info=key;
        ptr->lchild=ptr->rchild=NULL;
    }
    else if(key<ptr->info)
        ptr->lchild=insert(ptr->lchild,key);
    else if(key>ptr->info)
        ptr->rchild=insert(ptr->rchild,key);
    else
        printf("Duplicate\n");
    return ptr;
}
struct tree *min_rec(struct tree *ptr){
    if(ptr==NULL)
        return ptr;
    if(ptr->lchild==NULL)
        return ptr;
    else 
        return min_rec(ptr->lchild);
}
struct tree *max_rec(struct tree *ptr){
    if(ptr==NULL)
        return ptr;
    if(ptr->rchild==NULL)
        return ptr;
    else 
        return max_rec(ptr->rchild);
}
struct tree *del(struct tree *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->info) {
        root->lchild = del (root->lchild, key);
    } else if (key > root->info) {
        root->rchild = del (root->rchild, key);
    } else {
        if (root->lchild == NULL) {
        struct tree *temp = root->rchild;
        free(root);
        return temp;
        } else if (root->rchild == NULL) {
        struct tree *temp = root->lchild;
        free(root);
        return temp;
        }
        struct tree *successor = root->rchild;
        while (successor->lchild != NULL) {
        successor = successor->lchild;
        }
        root->info = successor->info;
        root->rchild = del (root->rchild, successor->info);
    }
    
    return root;
}
int height(struct tree *ptr){
    int lh,rh;
    if(ptr==NULL)
        return 0;
    lh=height(ptr->lchild);
    rh=height(ptr->rchild);
    if(lh>rh)
        return lh+1;
    else
        return rh+1;
}
void display(struct tree *ptr,int level){
    if(ptr==NULL)
        return;
    if(level==1)
        printf("%d ",ptr->info);
    else if(level>1){
        display(ptr->lchild,level-1);
        display(ptr->rchild,level-1);
    }
}
void levelOrder(struct tree *ptr){
    int i,h=height(ptr),n;
    for(i=1;i<=h;i++)
        display(ptr,i);
}
void preorder(struct tree *root){
    if(root!=NULL){
        printf("%d ",root->info);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void inorder(struct tree *root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d ", root->info);
        inorder(root->rchild);
    }
}
void postorder(struct tree *root){
    if(root != NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->info);
    }
}
int main(){
    struct tree *root=NULL;
    int a[100];
    printf("Enter the number of elements: ");
    int n;
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        printf("Element %d: ",i+1);
        scanf("%d",&a[i]);
        root=insert(root,a[i]);
    }
    printf("Height:%d",height(root));
    printf("\nLevel Order:");
    levelOrder(root);
    printf("\nPreorder:");
    preorder(root);
    printf("\nPostorder:");
    postorder(root);
    printf("\nInorder:");
    inorder(root);
    struct tree *min=min_rec(root);
    printf("\nThe minimum number is:%d ",min->info);
    struct tree *max=max_rec(root);
    printf("\nThe maximum number is:%d ",max->info);
    printf("\nEnter the number you want to delete: ");
    scanf("%d",&n);
    del(root,n);
    printf("\nThe tree after deletion:\n");
    printf("Height:%d",height(root));
    printf("\nLevel Order:");
    levelOrder(root);
    printf("\nPreorder:");
    preorder(root);
    printf("\nPostorder:");
    postorder(root);
    printf("\nInorder:");
    inorder(root);
    min=min_rec(root);
    printf("\nThe minimum number is:%d ",min->info);
    max=max_rec(root);
    printf("\nThe maximum number is:%d ",max->info);
}