#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 26

typedef struct {
    char fName[20];
    char lName[20];
    char MI;
    int idNumber;
    char course[5];
} studRec;

typedef struct node {
    studRec S;
    struct node *next;
} nodeType, *nPtr;

typedef nPtr Dictionary[SIZE];

void initialize(Dictionary D);
void insert(Dictionary D, studRec S);
int hash(char lastName[]);
bool isMember(Dictionary D, studRec S);
void display(Dictionary D);
void deleteRec(Dictionary D, studRec S);

int main(){

    Dictionary D;
    initialize(D);

    studRec A[] = {{"Nikko", "Ensomo", 'B', 20101049, "BSIT"},
                   {"Marcelo", "Meneses", 'C', 19203042, "BSCS"},
                   {"Dominic", "Dagale", 'O', 10342453, "BSN"},
                   {"Kyran", "Tiu", 'T', 20423413, "BSCE"}
                   };

    insert(D, A[0]);
    insert(D, A[1]);
    insert(D, A[2]);
    insert(D, A[3]);
    
    display(D);

    return 0;
}

void initialize(Dictionary D){

    for (int i = 0; i < SIZE; i++){
        D[i] = NULL;
    }
}

int hash(char lastName[]){

    return lastName[0] - 'A';
}

bool isMember(Dictionary D, studRec S){

    int hashValue;
    nPtr trav;

    hashValue = hash(S.lName);

    for (trav = D[hashValue]; trav != NULL && trav->S.idNumber!= S.idNumber; trav = trav->next){}

    return (trav != NULL) ? 1 : 0;
}

void insert(Dictionary D, studRec S){

    nPtr temp, *trav;
    int hashValue;
    
    hashValue = hash(S.lName);
    if (D[hashValue] == NULL){
        D[hashValue] = malloc(sizeof(nodeType));
        D[hashValue]->S = S;
        D[hashValue]->next = NULL;
    } else {
        if (isMember(D, S) == 0){
            for (trav = &D[hashValue]; *trav != NULL && strcmp((*trav)->S.lName, S.lName) < 0; trav = &(*trav)->next){}
            temp = malloc(sizeof(nodeType));

            if (temp != NULL){
                temp->S = S;
                temp->next = D[hashValue];
                D[hashValue] = temp;
            }
        }
    }
}

void deleteRec(Dictionary D, studRec S){

    nPtr *trav, temp;
    int hashValue;

    hashValue = hash(S.lName);

    if (isMember(D, S) == 1){
        for (trav = &D[hashValue]; *trav != NULL && (*trav)->S.idNumber != S.idNumber; trav = &(*trav)->next){}
        temp = (*trav);
        (*trav) = temp->next;
        free(temp);
    } else {
        printf("Element not in the set!\n");
    }
}

void display(Dictionary D){

    nPtr temp;

    printf("INDEX\tFIRST NAME\tLAST NAME\tMI\tCOURSE\tID NUMBER\n");
    printf("-----\t----------\t---------\t--\t------\t---------\n\n");

    for (int i = 0; i < SIZE; i++){
        printf("%d", i);
        temp = D[i];

        while (temp != NULL){
            printf("\t%s\t%s\t\t%c\t%s\t%d", temp->S.fName, temp->S.lName, temp->S.MI, temp->S.course, temp->S.idNumber);
            temp = temp->next;

            if (temp == NULL){
                printf("->NULL");
            }
        }
        printf("\n");
    }
}