/* STACK: This program illustrate how to implement the
 * PUSH and POP.
 * Here, we use array to store the stack elements.
 * 
 * Here, are basic operation on a stack.
 *
 * init() ----> s:Stack, empty stack
 * isEmpty(s) ----> b:Boolean
 * top(s) ----> v:Data, if s is not empty otherwise error
 * push(s,v) ----> t:stack
 * pop(s) ----> t:Stack, if s is not empty otherwise error
 * display();      // displays the element in stack
 *
 */


//standard files will be declared here
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//macro
#define MAXSIZE 20


//global variables which are going to used throughout the program.
int TOP = -1;       // TOP of the stack it always store the value of top most element in stack.
int s[MAXSIZE];     // array to store all the elements in stack.
int v = 0;          // to store the value of new element.

//function prototype
int init();
int isEmpty();
int top();
void push(int v);    // this function push new element in stack and returns the TOP.
void pop();          // this function used to pop element from top of the stack and updates the TOP.
void display();      // displays the element in stack

//function definition
int init(){
    for(int i = 0; i<MAXSIZE; i++){
        s[i] = 0;                          //s[i] = (long int)NULL;
    }
    return 1;
}

// this function returns that whether the function empty or not.
int isEmpty(){
    if(TOP == -1)
        return 1;
    else 
        return 0;
}

// function to find the top of the stack.
int top(){
    if(TOP == -1)
        isEmpty();
    else
        return s[TOP];
}

// function to push the element in stack.
void push(int v){
    if(TOP == MAXSIZE-1)
        printf("Stack is full.\n\n");
    else {
        TOP += 1;
        s[TOP] = v;
    }
}

// function to pop the element in stack.
void pop(){ 
    if(!isEmpty())  {
        printf("\n%d is poped.\n\n",s[TOP]);
        TOP -= 1;
    }
    else
        printf("Stack is Empty");
}

// display the stack elements
void display()  {
    if(!isEmpty())
        for(int counter = TOP; counter >= 0; counter--) {
            printf("            ----------\n");
            printf("            |%4d    |\n",s[counter]);
            printf("            ----------\n");
        }
    else
        printf("\n\nStack is empty.\n\n");
}

int main()  {
    int opt;
    while(opt != 8) {
    printf("\n\n          Operation: \n\n");
    printf("1- Initialize the stack.\n");
    printf("2- Stack is empty or not.\n");
    printf("3- TOP\n");
    printf("4- PUSH\n");
    printf("5- POP\n");
    printf("6- Print stack elements.\n");
    printf("7- Exit.\n\n");

    printf("Please choose the operation: ");

    scanf("%d",&opt);
        
    switch(opt){
        case 1: init();
                break;

        case 2: if(!isEmpty())
                    printf("List is not empty.\n\n");
                else
                    printf("List is empty.\n\n");
                break;

        case 3: printf("TOP = %d\n\n",top());
                break;

        case 4: printf("Enter the element. ");
                int temp;
                scanf("%d",&temp);
                push(temp);
                break;

        case 5: pop();
                break;

        case 6: printf("\n\n        Elements of the stack.\n\n");
                display();
                break;
        
        case 7: exit(1);

        default: printf("Please choose the correc option.\n");

        }   
    }
}