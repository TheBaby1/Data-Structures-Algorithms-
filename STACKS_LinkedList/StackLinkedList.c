#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "StackLinkedList.h"

void initStack(StackLinkedList **head){

    *head = NULL;
}

bool isEmpty(StackLinkedList *head){

    return (head == NULL);
}

void push(StackLinkedList **head, int elem){

    StackLinkedList *current = malloc(sizeof(struct node));

    if (isEmpty(*head)){
        current->data = elem;
        current->next = NULL;
        *head = current;
    } else {
    	current->data = elem;
    	current->next = *head;
    	*head = current;
	}

}


void pop(StackLinkedList **head){

    StackLinkedList *temp;

    if (isEmpty(*head)){
        printf("Stack is Empty.\n");
    } else {
    	temp = *head;
    	*head = (*head)->next;
    	free(temp);
	}
	
}


int peek(StackLinkedList *head){

    StackLinkedList *current = head;

    if (isEmpty(head)){
        printf("Stack is Empty.\n");
    }

    return current->data;
}

void displayStack(StackLinkedList *head){

    StackLinkedList *newStack;
    initStack(&newStack);

    while (!isEmpty(head)){
        int top = peek(head);
        push(&newStack, top);
        pop(&head);
    }

    printf("Display Stack: \n");
    while (!isEmpty(newStack)){
        int top = peek(newStack);
        printf("%d \n", top);
        push(&head, top);
        pop(&newStack);
    }
    
    printf("\n");
}

void visualizeStack(StackLinkedList *head){

    StackLinkedList *current = head;
	int top = peek(head);

    printf("Visualize Stack: \n");
    while (current != NULL){
        printf("%d ", current->data);
        if (current->data == top){
        	printf("%s", "<--- Top");
		}
        current = current->next;
        
        printf("\n");
    }

    printf("\n");
}

StackLinkedList getEven(StackLinkedList **head){
	
	StackLinkedList *tempStack;
	StackLinkedList *newStack;
	
	initStack(&tempStack);
	initStack(&newStack);
	
	while (!isEmpty(*head)){
		int top = peek(*head);
		pop(head);
		
		if (top % 2 == 0){
			push(&newStack, top);
		} else {
			push(&tempStack, top);
		}
	}
	
	while (!isEmpty(tempStack)){
		push(head, peek(tempStack));
		pop(&tempStack);
	}
	
	return newStack;
}


