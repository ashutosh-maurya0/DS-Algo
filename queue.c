#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE_OF_QUEUE 100

int queue[MAXSIZE_OF_QUEUE];
int f = -1, r = -1;
bool x = true, y = false;

bool isEmpty();
bool isFull();
void enequeue(int ele);
int dequeue();
void display();

bool isEmpty(){
	if(f == -1 && r == -1)
		return x;
	else
		return y;
}

bool isFull(){
	if(r == MAXSIZE_OF_QUEUE)
		return x;
	else
		return y;
}

void enqueue(int ele)	{
	if(isFull())	{
		printf("\n\nQueue is full.\n\n");
		exit(1);
	}

	else
		queue[++r] = ele;
}

int dequeue()	{
	if(isEmpty())
		printf("\n\nQueue is empty.\n\n");
	
	else 
		return	queue[++f];
}

void display(){
	if(isEmpty())
		printf("\n\nNothing to show.\n\n");
	else {
		int cnt = f;
		while(cnt != r)
			printf("%d  ",queue[++cnt]);
	}
		
}

int main ()	{
	int sw = 0;

	while(sw != -1){
		printf("\n\n\n1-isEmpty\n2-isFull\n3-Enqueue\n4-Dequque\n5-Display\n6-Exit\n\n\n");	
		printf("Enter the choice: ");
		scanf("%d",&sw);
		
		switch(sw) {
		case 1: if(isEmpty()){
			       printf("\n\nQueue is Empty.\n\n"); continue;}
		        else
			       printf("\n\nQueue is Not Empty.\n\n");
			break;

		case 2: if(isFull())
			       printf("\n\nQueue is Full.\n\n");
		        else
			       printf("\n\nQueue is Not full.\n\n");
			break;

		case 3: int ele;
			printf("\n\nInsert the element: ");
			scanf("%d",&ele);
			enqueue(ele);
			break;

		case 4: printf("Element removed from the queue: %d",dequeue());
			break;

		case 5: printf("\n\nQueue elements\n");
			display();
			break;

		case 6: exit(0);
			break;

		default:
			printf("Please the valid selection.\n\n");

		}
	}
}
