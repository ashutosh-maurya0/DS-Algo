/* Program to convert infix expression to postfix 
 * expression.
 * infix expression: a+b*c/d-f/a^e, (a*b)/c-(d*(r-h)/(h^h))
 * postfix epxression: abc*d/+fae^/-, ab*c/drh-*hh^/-
 */

/* Step 1 : Scan the Infix Expression from left to right.
 * Step 2 : If the scanned character is an operand, append 
 *          it with final Infix to Postfix string.
 * Step 3 : Else,
 * Step 3.1 : If the precedence order of the scanned(incoming) 
 *            operator is greater than the precedence order of 
 *            the operator in the stack (or the stack is empty 
 *            or the stack contains a '(' or '[' or '{'), push it on stack.
 * Step 3.2 : Else, Pop all the operators from the stack which 
 *            are greater than or equal to in precedence than 
 *            that of the scanned operator. After doing that Push 
 *            the scanned operator to the stack. (If you encounter 
 *            parenthesis while popping then stop there and push 
 *            the scanned operator in the stack.)
 * Step 4 : If the scanned character is an '(' or '[' or '{', push 
 *            it to the stack.
 * Step 5 : If the scanned character is an ')' or ']' or '}', pop 
 *          the stack and and output it until a '(' or '[' or '{' 
 *          respectively is encountered, and discard both the parenthesis.
 * Step 6 : Repeat steps 2-6 until infix expression is scanned.
 * Step 7 : Print the output
 * Step 8 : Pop and output from the stack until it is not empty.

*/

// all headers files are written here
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// macro for size of array
#define MAXSIZE 40

// global variable 
char stack[MAXSIZE];
int TOP = -1;

// function prototypes
void push(char ch);
char pop();
int priority(char ch);

// function
void push(char op) {
    stack[++TOP] = op;
}

// function
char pop()  {
    if(TOP == -1)
        return -1;
    else
        return stack[TOP--];
}

// function
int priority(char ch)   {
    if(ch == '(')
        return 1;
    
    if(ch == '+' || ch == '-')
        return 2;
    
    if(ch == '*' || ch == '/')
        return 3;
    
    if(ch == '^')
        return 4;
}

// main function
int main()  {
    char exp[MAXSIZE];
    char *tmp, tmp2;

    printf("Enter the expression = ");
    scanf("%s", exp);
    printf("\nPostfix: ");
    tmp = exp;

    while(*tmp != '\0') {
        if(isalnum(*tmp))
            printf("%c",*tmp);
        else if(*tmp == '(')
            push(*tmp);
        else if(*tmp == ')')
            while(((tmp2 = pop()) != '('))
                printf("%c", tmp2);
        else    {
            while(priority(stack[TOP]) >= priority(*tmp))
                printf("%c", pop());
            push(*tmp);
        }
        tmp++;
    }
    while(TOP != -1)
        printf("%c\n\n", pop());
}