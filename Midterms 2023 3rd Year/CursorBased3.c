#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 7

typedef struct {
    int data;
    int next;
} Node;

typedef struct {
    Node NODES[MAX];
    int avail;
} VirtualHeap;

typedef int LIST;

void initializeVHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH, LIST *list);
void deallocSpace(VirtualHeap *VH, int index);
void insertLast(VirtualHeap *VH, LIST *list, int data);
void deleteNode(VirtualHeap *VH, LIST *list, int index);
void displayList(VirtualHeap *VH, LIST *list);

int main(){

    VirtualHeap VH;
    LIST list = 0;

    initializeVHeap(&VH);

    insertLast(&VH, &list, 20);
    insertLast(&VH, &list, 45);
    insertLast(&VH, &list, 120);

    displayList(&VH, &list);

    deleteNode(&VH, &list, 0);
    printf("After Deletion: \n\n");
    displayList(&VH, &list);

    insertLast(&VH, &list, 60);
    insertLast(&VH, &list, 14);
    insertLast(&VH, &list, 21);

    printf("After Insertion: \n\n");
    displayList(&VH, &list);

    return 0;
}

void initializeVHeap(VirtualHeap *VH){

    VH->avail = 0;
    
    for (int i = 0; i < MAX; i++){

        if (i == MAX -1){
            VH->NODES[i].next = -1;
        } else {
            VH->NODES[i].next = i + 1;
        }
    }
}

int allocSpace(VirtualHeap *VH, LIST *list){

    int retVal = -1;

    if (VH->avail != -1){
        retVal = VH->avail;
        VH->avail = VH->NODES[retVal].next;
    }

    return retVal;
}

void deallocSpace(VirtualHeap *VH, int index){

    VH->NODES[index].next = VH->avail;
    VH->avail = index;
}

void insertLast(VirtualHeap *VH, LIST *list, int data){

    LIST *trav, temp;

    for (trav = list; *trav != -1; trav = &VH->NODES[*trav].next){}

    temp = allocSpace(VH, list);

    if (temp != -1){
        VH->NODES[temp].data = data;
        VH->NODES[temp].next = -1;
        *trav = temp;
    }
}

void deleteNode(VirtualHeap *VH, LIST *list, int index){

    if (index == *list){
        *list = VH->NODES[index].next;
        deallocSpace(VH, index);
    } else {
        VH->NODES[index - 1].next = VH->NODES[index].next;
        deallocSpace(VH, index);
    }
}

void displayList(VirtualHeap *VH, LIST *list){

    LIST *trav;

    printf("%s %8s %8s\n\n", "INDEX", "DATA", "NEXT");

    for (trav = list; *trav != -1; trav = &VH->NODES[*trav].next){
        printf("%d %10d %8d\n", *trav, VH->NODES[*trav].data, VH->NODES[*trav].next);
    }
}

