#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 6

typedef int LIST;

typedef struct {
    char data;
    int next;
} node;

typedef struct{
    node NODES[MAX];
    int avail;
} VirtualHeap;

void traverse(VirtualHeap VH, LIST L);
void initialize(VirtualHeap *VH, LIST *L);
void insertAvail(VirtualHeap *VH, LIST *L, char data);
void insertLast(VirtualHeap *VH, LIST *L, char data);
void deleteData(VirtualHeap *VH, LIST *L, char data);

int main(){

    VirtualHeap VH;
    LIST L;

    initialize(&VH, &L);
    insertAvail(&VH, &L, 'Z');
    insertAvail(&VH, &L, 'D');
    insertAvail(&VH, &L, 'O');

    traverse(VH, L);

    return 0;
}

void initialize(VirtualHeap *VH, LIST *L){

    int i, lim = MAX - 1;
    VH->avail = 0;

    for (i = 0; i < lim; i++){
        VH->NODES[i].next = i + 1;
    }

}

void insertAvail(VirtualHeap *VH, LIST *L, char data){

    LIST temp;

    if (VH->avail != -1){
        temp = VH->avail;
        VH->NODES[temp].data = data;
        VH->avail = VH->NODES[VH->avail].next;
        VH->NODES[temp].next = *L;
        *L = temp;
    }
}

void insertLast(VirtualHeap *VH, LIST *L, char data){

    LIST *trav, temp;

    for (trav = L; *trav != -1; trav = &(VH->NODES[*trav].next)){}

    if (VH->avail != -1){
        temp = VH->avail;
        VH->NODES[temp].data = data;
        VH->avail = VH->NODES[temp].next;
        VH->NODES[temp].next = *trav;
        *trav = temp;
    }
}

void deleteData(VirtualHeap *VH, LIST *L, char data){

    LIST *trav, temp;

    for (trav = L; *trav != -1 && VH->NODES[*trav].data != data; trav = &VH->NODES[*trav].next){}

    temp = *trav;
    (*trav) = VH->NODES[*trav].next;
    VH->NODES[temp].next = VH->avail;
    VH->avail = temp;
}

void traverse(VirtualHeap VH, LIST L){

    LIST trav;

    for(trav = L; trav != -1; trav = VH.NODES[trav].next){
        printf("%c ", VH.NODES[L].data);
        printf("%d \n", VH.NODES[L].next);
    }
}