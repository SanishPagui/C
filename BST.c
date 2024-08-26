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
        printf("Duplicate");
    return ptr;
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
        printf("%d\t",ptr->info);
    else if(level>1){
        display(ptr->lchild,level-1);
        display(ptr->rchild,level-1);
    }
}
void levelOrder(struct tree *ptr){
    int i,h=height(ptr);
    for(i=1;i<=h;i++)
        display(ptr,i);
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
    levelOrder(root);
}