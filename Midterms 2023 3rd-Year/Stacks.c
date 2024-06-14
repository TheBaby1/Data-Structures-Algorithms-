#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} nodeType, *Stack;

void initializeStack(Stack *S);
void push(Stack *S, int data);
void pop(Stack *S);
int isEmpty(Stack S);
int top(Stack *S);

int main(){

    Stack S;

    initializeStack(&S);

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);

    printf("Top: %d\n", top(&S));

    pop(&S);
    printf("Top: %d\n", top(&S));

    pop(&S);
    printf("Top: %d\n", top(&S));

    return 0;
}

void initializeStack(Stack *S){

    *S = NULL;
}

void push(Stack *S, int data){

    Stack temp;

    temp = (Stack)malloc(sizeof(nodeType));

    if (temp != NULL){
        temp->data = data;
        temp->next = *S;
        *S = temp;
    }
}

void pop(Stack *S){

    Stack temp;

    if (*S != NULL){
        temp = *S;
        *S = (*S)->next;
        free(temp);
    }
}

int isEmpty(Stack S){

    return (S == NULL) ? 1 : 0;
}

int top(Stack *S){

    return (*S)->data;
}
