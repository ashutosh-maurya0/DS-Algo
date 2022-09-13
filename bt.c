#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

//macro
#define link "                                                    |\n"

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int i = 0, l = 0;
int in = 0,     inl =0;

struct print {
    int call;
    int add;
    char cond;
    int root_data;
    int root_l;
    int root_r;
    struct print * next;
};

struct print * temp = NULL;

// function to trace the recursive call
void recv(struct print *trace){   
    printf("                        |----------------|\n");
    printf("                        |     Call %d     |    \n",trace->call);
    printf("                        |----------------|\n");
    printf("preorder root           |     add 0x%d    |\n",trace->add);
    printf("                        |----------------|\n");
    printf("cond                    |       %c        |\n",trace->cond);
    printf("                        |----------------|\n");
    if(trace->root_data <9) {
        printf("root->data              |       %d        |\n",trace->root_data);
    }
    else {
        printf("root->data              |       %d       |\n",trace->root_data);
    }
    printf("                        |----------------|\n");
    printf("preorder root->left     |      0x%d       |",trace->root_l);
    printf("----------|\n");
    printf("                        |----------------|");
    printf("          |\n");
    printf("preorder root->right    |      0x%d       |          |\n",trace->root_r);
    printf("                        |----------------|          |\n");
    printf(link);
    printf("                                          ----------|");
    printf("\n");
    
}


struct node* createNode(int data) {
    // this function will return the pointer for the new node
    struct node *newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data= data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function for preorder traversing
void preorder(struct node *root) {
    struct print *trace = malloc(sizeof(struct print));
    trace->call = ++l;
    trace->add = ++i;

    if (root != NULL) {
        trace->cond = 'T';
        trace->root_data = root->data;
        if(root->left != NULL) {
            trace->root_l = i+1;
            trace->root_r = i+2;
        }
        else {
            trace->root_l = 0;
            trace->root_r = 0;
        }
        recv(trace);
        preorder(root->left);
        
        trace->root_r = i+1;
        if(root->left != NULL)
            trace->root_r = i+1;
        else
            trace->root_r = 0;
        recv(trace);
        preorder(root->right);
    }
    else {
        trace->add = --i;
        trace->cond = 'F';
        trace->root_l = 0;
        trace->root_r = 0;
        recv(trace);
        return;
    }
    recv(trace);
    temp = trace;
}


void inorder(struct node *root) {

    if(root != NULL) {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
    else
        return;
}

void postorder(struct node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
    else
        return;
}

void main() {
    struct node *root= createNode(5);  // create root node

    // children of root node
    root->left= createNode(7);
    root->right= createNode(9);

    // grandchildren of root node
    root->left->left= createNode(11);
    root->left->right= createNode(12);
    root->right->left= createNode(19);
    root->right->right= createNode(18);
    //root->left->right->left= createNode(4);

    printf("PRE-ORDER: \n");
    printf("calling (main()) function");
    printf("---------------->\n                                         |\n                                         |\n                                         |\n                                         v\n");
    preorder(root);
    //printf("returned to the")

    //printf("IN-ORDER: \n");
    //inorder(root);

    //printf("POST-ORDER: \n");
    //postorder(root);
}