#include<stdio.h>
#include<stdlib.h>

// self-referential structure
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// node creation 
struct node *createNode(int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// inserting node
struct node *insert(struct node * root, int data){
    if(root == NULL)
        return createNode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}

// tree traversal
void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

// main function 
int main(){
    struct node * root = NULL;
    root = insert(root, 8);
    insert(root, 4);
    insert(root, 5);
    insert(root, 3);
    insert(root, 32);
    insert(root, 13);
    insert(root, 16);
    insert(root, 2);

    inorder(root);
    printf("\n");
}