#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char FName[20];
    char LName[20];
    char MI;
    int ID;
    int yearLevel;
} Studrec;

typedef struct {
    Studrec student;
    int next;
} Node;

typedef struct {
    Node NODES[MAX];
    int avail;
} VirtualHeap;

typedef int LIST;

void initializeVHeap(VirtualHeap *VH);
void insertLast(VirtualHeap *VH, LIST *list, Studrec *S);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);
void displayList(VirtualHeap VH, LIST *list);
void deleteNode(VirtualHeap *VH, LIST *list, int index);

int main(){

    VirtualHeap VH;
    LIST list = 0;
    Studrec S1 = {"Nikko", "Ensomo", 'B', 20101049, 3};
    Studrec S2 = {"Valerie", "Serohijos", 'B', 1234423, 4};
    Studrec S3 = {"Marcelo", "Meneses", 'C', 3243242, 4};
    Studrec S4 = {"Dominic", "Dagale", 'O', 43423411, 3};

    initializeVHeap(&VH);

    insertLast(&VH, &list, &S1);
    insertLast(&VH, &list, &S2);
    insertLast(&VH, &list, &S3);
    insertLast(&VH, &list, &S4);

    displayList(VH, &list);

    return 0;
}

void initializeVHeap(VirtualHeap *VH){

    VH->avail = 0;

    for (int i = 0; i < MAX; i++){

        if (i == MAX - 1){
            VH->NODES[i].next = -1;
        } else {
            VH->NODES[i].next = i + 1;
        }
    }
}

int allocSpace(VirtualHeap *VH){

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

void insertLast(VirtualHeap *VH, LIST *list, Studrec *S){

    LIST *trav, temp;

    for (trav = list; *trav != -1; trav = &VH->NODES[*trav].next){}

    temp = allocSpace(VH);

    if (temp != -1){
        VH->NODES[temp].student = *S;
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

void displayList(VirtualHeap VH, LIST *list){

    LIST trav;

    for (trav = *list; trav != -1; trav = VH.NODES[trav].next){
        printf("%s %5s %c %5d %5d\n", VH.NODES[trav].student.FName, VH.NODES[trav].student.LName, VH.NODES[trav].student.MI, VH.NODES[trav].student.ID, VH.NODES[trav].student.yearLevel);
    }
}