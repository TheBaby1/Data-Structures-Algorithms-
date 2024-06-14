#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef unsigned int SET;

void initializeSet(SET *A);
void insertElement(SET *A, int elem);
void deleteElement(SET *A, int elem);
void populate(SET *A, int elem[], int count);
void displaySet(SET A);
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);
int isSubset(SET A, SET B);

int main(){

    SET A, B;

    SET elem1[] = {1, 4, 5, 7};
    SET elem2[] = {1, 2, 5, 7};

    initializeSet(&A);
    initializeSet(&B);

    populate(&A, elem1, 4);
    populate(&B, elem2, 4);

    printf("Set A: ");
    displaySet(A);

    printf("\nSet B: ");
    displaySet(B);

    printf("\nUnion: ");
    displaySet(Union(A, B));

    printf("\nIntersection: ");
    displaySet(Intersection(A, B));

    printf("\nDifference: ");
    displaySet(Difference(A, B));

    printf("\nIs A a Subset of B?: %d", isSubset(A, B));

    return 0;
}

void initializeSet(SET *A){

    *A = 0;
}

void insertElement(SET *A, int elem){

    unsigned int mask = 1;

    *A |= mask << elem;
}

void deleteElement(SET *A, int elem){

    unsigned int mask = 1;

    *A |= ~(mask << elem);
}

void populate(SET *A, int elem[], int count){

    for (int i = 0; i < count; i++){

        insertElement(A, elem[i]);
    }
}

void displaySet(SET A){

    unsigned int mask = 1;

    for (int i = 0; i < SIZE; i++){

        if ((A & mask << i) != 0){
            printf("%d ", i);
        }
    }
}

SET Union(SET A, SET B){

    return A | B;
}

SET Intersection(SET A, SET B){

    return A & B;
}

SET Difference(SET A, SET B){

    return A & ~B;
}

int isSubset(SET A, SET B){

    return ((A & ~B) != 0) ? 0 : 1;
}