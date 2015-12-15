#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define N 10

struct node{
	int datum;
	struct node* next;
};

struct node* prepend(struct node*, int);
struct node* append(struct node*, int);
struct node* delete(struct node*, int);
void deleteAll(struct node*);
int check(struct node*, int);
int count(struct node*);
void print_list(struct node*);
int getInput(int, int);
void printMenu();
void clearScreen();

int main(){
	int choice, checkVal;
	struct node* list;

	list = NULL;

	do{
	clearScreen();
	printMenu();
	choice = getInput(1, 7);

	switch (choice){
		case 1:
			//prepend
			clearScreen();
			printf("Enter an integer between -1000 and 1000\n");
			list = prepend(list, getInput(-1000, 1000));
			break;
		case 2:
			//append
			clearScreen();
			printf("Enter an integer between -1000 and 1000\n");
			list = append(list, getInput(-1000, 1000));
			break;
		case 3:
			//delete
			clearScreen();
			printf("Enter an integer between -1000 and 1000\n");
			list = delete(list, getInput(-1000, 1000));
			break;
		case 4:
			//check
			clearScreen();
			printf("Enter an integer between -1000 and 1000\n");
			checkVal = getInput(-1000, 1000);
			if (check(list, checkVal)){
				printf("The number %d was found\n", checkVal);
			} else {
				printf("The number %d was not found\n", checkVal);
			}
			sleep(1);
			break;
		case 5:
			//count
			clearScreen();
			printf("There are %d nodes in the list\n", count(list));
			sleep(1);
			break;
		case 6:
			//print
			print_list(list);
			printf("\n");
			sleep(1);
			break;
		case 7:
			//quit
			deleteAll(list);
			return 0;
		default:
			printf("ERROR");
			return 0;
	}
	} while(1);
}

struct node* prepend(struct node* head, int val){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->datum = val;
	newNode->next = head;
	head = newNode;
	return head;
}

struct node* append(struct node* head, int val){
	if (head == NULL){
		printf("%p\n", head);
		head = (struct node*)malloc(sizeof(struct node));
		printf("%p\n", head);
		head->datum = val;
		head->next = NULL;
		return head;
	} else {
		struct node* start = head;
		while (head->next != NULL){
			head = head->next;
		}
		head->next = (struct node*)malloc(sizeof(struct node));
		head->next->datum = val;
		head->next->next = NULL;
		return start;
	}
}

struct node* delete(struct node* head, int val){
	struct node* newStart = head;
	if (head->datum == val){
		newStart = head->next;
		free(head);
	} else {
		while (head->next->datum != val && head->next->next != NULL){
			head = head->next;
		}
		if (head->next->datum == val){
			struct node* deleteNode = head->next;
			head->next = head->next->next;
			free(deleteNode);
		} else {
			printf("Value: %d not found in list\n", val);
		}
	}
	return newStart;
}

void deleteAll(struct node* head){
	struct node* nextNode;
	if (head == NULL){
		return;
	}
	while(head->next != NULL){
		nextNode = head->next;
		free(head);
		head = nextNode;
	}

}

int check(struct node* head, int val){
	while(head->datum != val && head->next != NULL){
		head = head->next;
	}
	return head->datum == val;
}

int count(struct node* head){
	int count = 0;
	while (head != NULL){
		head = head->next;
		count ++;
	}
	return count;
}

void print_list(struct node* head){
	//printf("%p", head);
	if (head == NULL){
		printf("NULL");
	} else {
		printf("\%d->", head->datum);
		print_list(head->next);
	}
}

int getInput(int lower, int upper){
	int * choice = malloc(sizeof(int));
	int x;
	scanf("%d", choice);

	while (*choice < lower || *choice > upper){
		printf("Invalid input. Enter an integer between 1-7\n");
		scanf("%d", choice);
	}

	x = *choice;
	return x;
}

void printMenu(){
	printf("Select an operation to perform:\n");
	printf("[1] Prepend an item\n");
	printf("[2] Append an item\n");
	printf("[3] Delete an item\n");
	printf("[4] Check for an item\n");
	printf("[5] Count the number of items\n");
	printf("[6] Print the list\n");
	printf("[7] Quit\n");
}

void clearScreen(){
	int x;
	for (x = 0; x < 30; x++)
		printf("\n");
}
