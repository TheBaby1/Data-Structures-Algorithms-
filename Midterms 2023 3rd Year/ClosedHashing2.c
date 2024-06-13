#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define DELETED -1
#define EMPTY -2

typedef int Data;
typedef Data Dictionary[MAX];

void initializeDictionary(Dictionary D);
void insertData(Dictionary D, int data);
void populateDictionary(Dictionary D);
void displayDictionary(Dictionary D);
int hash(int data);
int isMember(Dictionary D, int data);
void deleteData(Dictionary D, int data);

int main(){

    Dictionary D;

    initializeDictionary(D);

    populateDictionary(D);

    displayDictionary(D);

    printf("Is Member 43: %d\n", isMember(D, 43));
    printf("Is Member 68: %d\n", isMember(D, 232));
    printf("Is Member 23: %d\n", isMember(D, 23));

    deleteData(D, 114);

    printf("\nAfter Deleting 114\n");
    displayDictionary(D);

    return 0;
}

void initializeDictionary(Dictionary D){

    for (int i = 0; i < MAX; i++){
        D[i] = EMPTY;
    }
}

int hash(int data){

    return data % MAX;
}

void insertData(Dictionary D, int data){

    int index, i = 0;

    for (index = hash(data); D[index] != DELETED && D[index] && D[index] != EMPTY && i < MAX; index = (index + 1) % MAX, i++){}

    if (i < MAX){
        D[index] = data;
    } else {
        printf("Dictionary is Full\n");
    }
}

void populateDictionary(Dictionary D){

    insertData(D, 43);
    insertData(D, 23);
    insertData(D, 14);
    insertData(D, 79);
    insertData(D, 230);
    insertData(D, 114);
    insertData(D, 791);
}

void deleteData(Dictionary D, int data){

    int index, i = 0;

    for (index = hash(data); D[index] != DELETED && D[index] != EMPTY && D[index] != data; index = (index + 1) % MAX, i++){}

    if (i < MAX){
        D[index] = DELETED;
    } else {
        printf("Data not found!\n");
    }
}

void displayDictionary(Dictionary D){

    for (int i = 0; i < MAX; i++){
        printf("Index %d: ", i);

        if (D[i] == EMPTY){
            printf("Empty\n");
        } else if (D[i] == DELETED){
            printf("Deleted\n");
        } else {
            printf("%d \n", D[i]);
        }
    }
}

int isMember(Dictionary D, int data){

    int index, i = 0;

    for (index = hash(data); i < MAX && D[index] != EMPTY && D[index] != DELETED && D[index] != data; index = (index + 1) % MAX, i++){}

    return (D[index] == data) ? 1 : 0;
}