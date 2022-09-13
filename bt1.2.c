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
    printf("\n                        |----------------|\n");
    printf("                        |     Call %d     |    \n",trace->call);
    printf("                        |----------------|\n");
    printf("inorder root            |     add 0x%d    |\n",trace->add);
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
    printf("inorder root->left      |      0x%d       |",trace->root_l);
    printf("----------|\n");
    printf("                        |----------------|");
    printf("          |\n");
    printf("inorder root->right     |      0x%d       |          |\n",trace->root_r);
    printf("                        |----------------|          |\n");
    printf(link);
    printf("                                         <----------|");
   // printf("\n");
    
}


struct node* createNode(int data) {
    // this function will return the pointer for the new node
    struct node *newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data= data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct node *root) {
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
        
        inorder(root->left);
        trace->root_data = root->data;
        
        //printf("%d",root->data);
        trace->root_r = i+1;
        if(root->left != NULL)
            trace->root_r = i+1;
        else
            trace->root_r = 0;
        
        recv(trace);
        inorder(root->right);
    }   
    else {
       trace->add = --i;
        trace->cond = 'F';
        trace->root_l = 0;
        trace->root_r = 0;
        recv(trace);
        return;
    }
    temp = trace;
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
    struct print *trace = malloc(sizeof(struct print));
    // children of root node
    root->left= createNode(7);
    root->right= createNode(9);

    // grandchildren of root node
    root->left->left= createNode(11);
    root->left->right= createNode(12);
    root->right->left= createNode(19);
    root->right->right= createNode(18);

    printf("IN-ORDER: \n");
    printf("calling (main()) function");
    printf("---------------->\n                                         |\n                                         |\n                                         |\n                                         v");
    inorder(root);
    printf("\n\n");

    //printf("POST-ORDER: \n");
    //postorder(root);
}