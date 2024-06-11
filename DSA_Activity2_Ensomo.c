#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int idNum;
    int age;
} info;

typedef struct node {
    info studentInfo;
    struct node *next;
} Node, *NodePtr;

void initializeList(NodePtr *head);
void insertFront(NodePtr *head, info S);
void insertEnd(NodePtr *head, info S);
void insertPosition(NodePtr *head, info S, int pos);
void displayList(NodePtr head);

int main(){
    
    NodePtr head = NULL; 
    
    info S = {"raynor", 9696, 70};
    info S1 = {"nikko", 1968, 34};
    info S2 = {"lorenz", 2001, 23};
    info S3 = {"kyle", 2002, 12};
    info S4 = {"sarel", 2001, 22};
    
    printf("Insert At Front:\n");
    insertFront(&head, S); 
    insertFront(&head, S1); 
    insertFront(&head, S2);
	displayList(head); 
    
    printf("\nInsert At End:\n");
    insertEnd(&head, S3);
    displayList(head);
    
    printf("\nInsert At Position: 2\n");
    insertPosition(&head, S4, 2);
    displayList(head);
    
    return 0;
}

void initializeList(NodePtr *head){
    *head = NULL; 
}

void insertFront(NodePtr *head, info S){
    NodePtr newNode = malloc(sizeof(Node)); 
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->studentInfo = S;
    newNode->next = *head;
    *head = newNode; 
}
/*
void insertEnd(NodePtr *head, info S){
	
	NodePtr newNode = malloc(sizeof(Node));
	
	if (newNode == NULL){
		printf("Memory allocation failed\n");
		return;
	}
	
	newNode->studentInfo = S;
	newNode->next = NULL;

	if (*head == NULL){
		insertFront(head, S);
	}
	
	NodePtr current = *head;
	
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newNode;

}
*/

void insertEnd(NodePtr *head, info S){
	
	NodePtr newNode = malloc(sizeof(Node));
	
	newNode->studentInfo = S;
	newNode->next = NULL;
	
	while (*head != NULL){
		head = &(*head)->next;
	}
	
	*head = newNode;
}


void insertPosition(NodePtr *head, info S, int pos){
	
	NodePtr newNode = malloc(sizeof(Node));
	int count = 0;
	
	if (*head == NULL){
		printf("Memory allocation failed\n");
	}
	
	newNode->studentInfo = S;
	
	NodePtr current = *head, previous = *head;
	
	while (current->next != NULL && count < pos){
		previous = current;
		current = current->next;
		count++;
	}
	previous->next = newNode;
	newNode->next = current;
}

void displayList(NodePtr head){
    NodePtr trav = head; 
    
    while (trav != NULL){ 
        printf("%10s %10d %10d\n", trav->studentInfo.name, trav->studentInfo.idNum, trav->studentInfo.age);
        trav = trav->next;
    }
}
