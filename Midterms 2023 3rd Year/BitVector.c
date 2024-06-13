#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef int DATA;
typedef DATA SET[SIZE];

void initializeSet(SET A);
void insertElement(SET A, int index);
void deleteElement(SET A, int index);
SET *Union(SET A, SET B);
SET *Intersection(SET A, SET B);
SET *Difference(SET A, SET B);
int isSubset(SET A, SET B);
void displaySet(SET *C);

int main(){

    SET A, B;
    int retVal = 0;

    initializeSet(A);
    initializeSet(B);

    insertElement(A, 1);
    insertElement(A, 4);
    insertElement(A, 5);
    insertElement(A, 7);

    insertElement(B, 1);
    insertElement(B, 2);
    insertElement(B, 5);
    insertElement(B, 7);

    printf("Union: ");
    displaySet(Union(A, B));

    printf("\nIntersection: ");
    displaySet(Intersection(A, B));

    printf("\nDifference: ");
    displaySet(Difference(A, B));

    retVal = isSubset(A, B);
    printf("\nIs A a subset of B?: %d", retVal);

    return 0;
}

void initializeSet(SET A){

    for (int i = 0; i < SIZE; i++){
        A[i] = 0;
    }
}

void insertElement(SET A, int index){

    A[index] = 1;
}

void deleteElement(SET A, int index){

    A[index] = 0;
}

SET *Union(SET A, SET B){

    SET *C = (SET*)malloc(sizeof(SET));

    if (C != NULL){

        for (int i = 0; i < SIZE; i++){

            (*C)[i] = A[i] | B[i];
        }
    }

    return C;
}

SET *Intersection(SET A, SET B){

    SET *C = (SET*)malloc(sizeof(SET));

    if (C != NULL){

        for (int i = 0; i < SIZE; i++){

            (*C)[i] = A[i] & B[i];
        }
    }

    return C;
}

SET *Difference(SET A, SET B){

    SET *C = (SET*)malloc(sizeof(SET));

    if (C != NULL){

        for (int i = 0; i < SIZE; i++){

            (*C)[i] = A[i] & ~B[i];
        }
    }

    return C;
}

int isSubset(SET A, SET B){

    int i;

    for (i = 0; i < SIZE; i++){

        if ((A[i] & ~B[i]) != 0){
            break;
        }
    }

    return (i < SIZE) ? 0 : 1;
}

void displaySet(SET *C){

    for (int i = 0; i < SIZE; i++){

        if ((*C)[i] == 1){
            printf("%d ", i);
        }
    }
}