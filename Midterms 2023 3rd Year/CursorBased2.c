#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 8

typedef struct {
    int data;
    int next;
} node;

typedef struct {
    node NODES[MAX];
    int avail;
} VHeap;

typedef int Head;

void initializeVHeap(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);
void insertFirst(VHeap *V, Head head, int data);
void display(VHeap *V, Head head);

int main(){

    VHeap *V = (VHeap*)malloc(sizeof(VHeap));
    Head head = -1;

    initializeVHeap(V);
    insertFirst(V, head, 3);
    insertFirst(V, head, 5);
    insertFirst(V, head, 8);
    insertFirst(V, head, 10);
    insertFirst(V, head, 12);

    display(V, head);

    return 0;
}

void initializeVHeap(VHeap *V){

    V->avail = 0;

    for (int i = 0; i < MAX; i++){
        V->NODES[i].next = i + 1;
        if (i == MAX - 1){
            V->NODES[i].next = -1;
        }
    }
}

int allocSpace(VHeap *V){

    int retVal = -1;

    if (V->avail != -1){
        retVal = V->avail;
        V->avail = V->NODES[retVal].next;
    } 

    return retVal;
}

void deallocSpace(VHeap *V, int index){

    V->NODES[index].next = V->avail;
    V->avail = index;   
}

void insertFirst(VHeap *V, Head head, int data){

    head = allocSpace(V);

    if (head == 0){
        V->NODES[head].data = data;
        V->NODES[head].next = -1;
    } else {
        V->NODES[head].data = data;
        V->NODES[head - 1].next = head;
        V->NODES[head].next = -1;
    }
}

void display(VHeap *V, Head head){

    head = 0;
    int i = 0;

    while (V->NODES[head].next != -1){
        printf("%d  [%d]  [%d]\n", i, V->NODES[head].data, V->NODES[head].next);
        i++;
        head = V->NODES[head].next;

        if (V->NODES[head].next == -1){
            printf("%d [%d]  [%d]\n", i, V->NODES[head].data, V->NODES[head].next);
        }
    }
}