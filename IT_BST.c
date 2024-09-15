#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node {
    struct node *left;
    bool lthread;
    int info;
    struct node *right;
    bool rthread;
};
struct node* successor(struct node *ptr) {
    if (ptr->rthread == true)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->lthread == false)
        ptr = ptr->left;
    return ptr;
}
struct node* predecessor(struct node *ptr) {
    if (ptr->lthread == true)
        return ptr->left;
    ptr = ptr->left;
    while (ptr->rthread == false)
        ptr = ptr->right;
    return ptr;
}
struct node* insert(struct node *root, int key) {
    struct node *ptr = root, *par = NULL, *temp;
    int found = 0;
    while (ptr != NULL) {
        if (ptr->info == key) {
            found = 1;
            break;
        }
        par = ptr;
        if (key < ptr->info) {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        } else {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    } 
    if (found) {
        printf("Duplicate key!\n");
    } else {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info = key;
        temp->lthread = true;
        temp->rthread = true;      
        if (par == NULL) {
            root = temp;
            temp->left = NULL;
            temp->right = NULL;
        } else if (key < par->info) {
            temp->left = par->left;
            temp->right = par;
            par->lthread = false;
            par->left = temp;
        } else {
            temp->left = par;
            temp->right = par->right;
            par->rthread = false;
            par->right = temp;
        }
    }
    return root;
}
struct node* create(struct node *root) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0)
        return root;
    printf("Enter the elements:\n");
    for (int i = 1; i <= n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &data);
        root = insert(root, data);
    }
    return root;
}
void inorder(struct node *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    struct node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = successor(ptr);
    }
    printf("\n");
}
void search(struct node *root, int key) {
    struct node *ptr = root;
    while (ptr != NULL) {
        if (ptr->info == key) {
            printf("Found\n");
            return;
        }
        if (key < ptr->info) {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        } else {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    printf("Not found\n");
}
struct node* deleteNode(struct node* root, int key) {
    struct node *par = NULL, *ptr = root, *child = NULL;
    int found = 0;
    while (ptr != NULL) {
        if (ptr->info == key) {
            found = 1;
            break;
        }
        par = ptr;
        if (key < ptr->info) {
            if (!ptr->lthread) {
                ptr = ptr->left;
            } else {
                break;
            }
        } else if (key > ptr->info) {
            if (!ptr->rthread) {
                ptr = ptr->right;
            } else {
                break;
            }
        }
    }
    if (!found) {
        printf("Key not found\n");
        return root;
    }
    if (ptr->lthread && ptr->rthread) {
        if (par == NULL) {
            root = NULL;
        } else if (ptr == par->left) {
            par->left = NULL;
            par->lthread = true;
        } else {
            par->right = NULL;
            par->rthread = true;
        }
        free(ptr);
    }
    else if (ptr->lthread) {
        if (par == NULL) {
            root = ptr->right;
        } else if (ptr == par->left) {
            par->left = ptr->right;
        } else {
            par->right = ptr->right;
        }
        child = successor(ptr);
        child->left = ptr->left;
        free(ptr);
    } else if (ptr->rthread) {
        if (par == NULL) {
            root = ptr->left;
        } else if (ptr == par->left) {
            par->left = ptr->left;
        } else {
            par->right = ptr->left;
        }
        child = predecessor(ptr);
        child->right = ptr->right;
        free(ptr);
    }
    else {
        struct node* succ = successor(ptr);
        int successorData = succ->info;
        root = deleteNode(root, successorData);
        ptr->info = successorData;
    }
    return root;
}
int main() {
    int choice, data;
    struct node *root = NULL;
    root=create(root);
    inorder(root);
    printf("Enter the element you want to search: ");
    scanf("%d", &data);
    search(root, data);
    printf("Enter the number you want to delete: ");
    scanf("%d", &data);
    root=deleteNode(root, data);
    inorder(root);
}