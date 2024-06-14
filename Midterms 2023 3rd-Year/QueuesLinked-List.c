#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} nodeType, *nodePtr;

typedef struct {
    nodePtr front, rear;
} Queue;

void initializeQueue(Queue *Q);
void enQueue(Queue *Q, int data);
void deQueue(Queue *Q);
void displayQueue(Queue Q);
int front(Queue Q);

int main(){

    Queue Q;
    int retVal = 0;

    initializeQueue(&Q);

    enQueue(&Q, 2);
    enQueue(&Q, 4);
    enQueue(&Q, 6);
    enQueue(&Q, 8);

    retVal = front(Q);
    printf("\nFront: %d\n", retVal);

    displayQueue(Q);

    deQueue(&Q);
    deQueue(&Q);

    printf("\n\n");
    displayQueue(Q);

    retVal = front(Q);
    printf("\nFront: %d\n", retVal);

    return 0;
}

void initializeQueue(Queue *Q){

    Q->front = Q->rear = NULL;
}

void enQueue(Queue *Q, int data){

    nodePtr temp;
    temp = (nodePtr)malloc(sizeof(nodeType));

    if (temp != NULL){
        temp->data = data;

        if (Q->front == NULL){
            Q->front = Q->rear = temp;
        } else {
            Q->rear->next = temp;
            Q->rear = temp;
        }
    }
    Q->rear->next = NULL;
}

void deQueue(Queue *Q){

    nodePtr temp;

    if (Q->front != NULL){
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
}

int front(Queue Q){

    return (Q.front != NULL) ? Q.front->data : 0;
}

void displayQueue(Queue Q){

    nodePtr trav;

    for (trav = Q.front; trav != NULL; trav = trav->next){
        printf("%d", trav->data);
        
        if (trav->next != NULL){
            printf("-->");
        }
    }
}