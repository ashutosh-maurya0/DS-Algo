/* LinkedList.c: Program to implement singly linked list
 * and show all the operation which can be performed on
 * the singly linked list.
 *
 * Following are the function list for different purpose:-
 *
 * struct node * CreateNode();
 * 
 * void InsertAtBeg(struct node *, key);
 * void InsertAtEnd(struct node *, key);
 * void InsertAtSpe(struct node *, key);
 *
 * void DeleteBeg();
 * void DeleteEnd();
 * void DeleteSpe(int pos);
 *
 * int Travers(struct node *);
 * void display(struct node * tmp);
 *
 */

#include<stdio.h>
#include<stdlib.h>

// macros
#define ARG "Node added successfully"
#define DEL "Node deleted successfully"
#define MENU "Insert at beginning\n2. Insert at End\n3. Insert at location\n4. Delete at beginning\n5. Delete at End\n6. Delete at location.\n7. Display\n8. Number Of Nodes\n9. Exit\n\nEnter your choice:"

// creating node
struct node {
	int key;			// data field
	struct node * next;		// self-refrential structure
};

// global variable
struct node * head = NULL;
struct node * temp = NULL;
int count = 0;

// function prototype list
struct node * CreateNode();
void InsertAtBeg(struct node * NewNode, int key);
void InsertAtEnd(struct node * NewNode, int key);
void InsertAtSpe(struct node * NewNode, int pos, int key);

void DeleteBeg();
void DeleteEnd();
void DeleteSpe(int pos);

int Travers(struct node *tmp);
void display(struct node *tmp);

// function to create nodes it take one int
// argument and returns pointer to struct node.
struct node * CreateNode() {
	struct node * NewNode = malloc(sizeof(struct node *));
	NewNode->next = NULL;
	return NewNode;
}

// function to insert key at beginning of the list.
// function take two argumnets one is pointer to struct node
// and other one is of int type.
void InsertAtBeg(struct node *NewNode, int key) {
	NewNode->next = head;
	NewNode->key = key;
	head = NewNode;
	puts(ARG);
}

// function to insert node at the end of the list.
// function take two arguments one is struct node pointer
// and other one is key which is of type int.
void InsertAtEnd(struct node *NewNode, int key) {
	temp = head;

	while(temp->next != NULL)
		temp = temp->next;
	
	NewNode->key = key;
	temp->next = NewNode;
	puts(ARG);
}

// function to insert node at the specified location
void InsertAtSpe(struct node * NewNode, int pos, int key) {
	int i = Travers(head);
	int l = 0;
	printf("\n\n       Nodes: %d\n\n",i);
	if(pos > i)
		printf("\n\nInvalid position\n\n");
	else if(i == 0) {
		NewNode->key = key;
		head = NewNode;
		puts(ARG);
	}
	else {
		if(pos == 0){
			NewNode->key = key;
			NewNode->next = head;
			head = NewNode;
			
		}
		else {
			temp = head;
			while(l < pos-2){
				temp = temp->next;
				printf("l = %d  ",l);
				l++;
			}
			NewNode->key = key;
			NewNode->next = temp->next;
			temp->next = NewNode;	
			puts(ARG);
		}	
	}

}

// funtion to delete node from beginning
void DeleteBeg() {
	if(head == NULL)
		printf("List is empty\n");
	else
		head = head->next;
	puts(DEL);	
}

// funtion to delete node from end of the list
void DeleteEnd() {
	if(head == NULL)
		printf("List is empty\n");
	else {
		struct node * temp1;
		temp = head;

		if(head->next == NULL){
			head = NULL;
			puts(DEL);
		}
		else {
			while(temp->next != NULL){
				temp1 = temp;
				temp = temp->next;
			}
			temp1->next = NULL;
			puts(DEL);
		}
		free(temp);
	}
}

// delete the node from specified location in list
void DeleteSpe(int pos){
	int i, flag = 0;
	struct node * temp1;
	temp = head;

	if(pos == 0 && head == NULL)
		printf("\n\nList is empty\n\n");
	if(pos > Travers(temp))
		printf("Invalid position.\n\n");
	
	if(pos == 0 && head != NULL) {
		head = temp->next;
		free(temp);
		puts(DEL);
	}
	else {
		for(i=0;i<pos-1;i++) {
			if(temp->next != NULL) {
				temp1 = temp;
				temp = temp->next;
			}
			else {
				flag = 1;
				break;
			}
		}
	}

}

// traversing the list
int Travers(struct node * tmp) {
	count = 0;
	while(tmp != NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}

// display the keys of the node in the list.
void display(struct node * tmp) {
	if(!Travers(tmp))
		printf("\n\nList is Empty.\n\n");
		while(tmp != NULL) {
		printf("%d  ",tmp->key);
		tmp = tmp->next;
	}
}

// main function
int main() {
	int choice, value, pos;
	struct node * NewNode = NULL;
	while(1) {
		printf("\n\n--------MENU--------\n\n%s",MENU);
		scanf("%d",&choice);
		switch(choice){ 
			case 1: printf("Enter the value: ");
			        scanf("%d",&value);
				NewNode = CreateNode();
				if(head == NULL){
					NewNode->key = value;
					head = NewNode;
				}
				else
					InsertAtBeg(NewNode, value);
				break;

			case 2: printf("Enter the value: ");
				scanf("%d",&value);
				NewNode = CreateNode();
				if(head == NULL) {
					NewNode->key = value;
					head = NewNode;
				}
				else
					InsertAtEnd(NewNode, value);
				break;

			case 3: printf("Enter the position: ");
				scanf("%d",&pos);
				printf("Enter the value: ");
				scanf("%d",&value);
				NewNode = CreateNode();
				InsertAtSpe(NewNode, pos, value);
				break;

			case 4: DeleteBeg();
				break;

			case 5: DeleteEnd();
				break;

			case 6: printf("Enter the position: ");
				scanf("%d",&pos);
				DeleteSpe(pos);
				break;

			case 7: display(head);
				break;
			
			case 8: printf("\n\nCount: %d\n\n",Travers(head));
				break;

			case 9: exit(1);
				break;
			default: printf("\nWrong Input. Please try again!\n\n");
		}
	}
}
