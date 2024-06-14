#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} nodeType, *List;

typedef List Dictionary[MAX];

void initializeDictionary(Dictionary D);
void displayDictionary(Dictionary D);
int hash(int data);
void insertData(Dictionary D, int data);
void populate(Dictionary D);
int isMember(Dictionary D, int data);
void deleteMember(Dictionary D, int data);


int main(){

    Dictionary D;

    initializeDictionary(D);

    displayDictionary(D);

    populate(D);
    displayDictionary(D);

    printf("%d \n", isMember(D, 23));
    printf("%d \n", isMember(D, 13));
    printf("%d \n", isMember(D, 32));



    return 0;
}

void initializeDictionary(Dictionary D){

    for (int i = 0; i < MAX; i++){
        D[i] = NULL;
    }
}

int hash(int data){

    return data % 10;
}

void insertData(Dictionary D, int data){

    List *trav, temp;
    int key;
    key = hash(data);

    for (trav = &D[key]; *trav != NULL && (*trav)->data < data; trav = &(*trav)->next){}

    if (*trav == NULL || (*trav)->data != data){

        temp = (List)malloc(sizeof(nodeType));
        if (temp != NULL){
            temp->data = data;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void populate(Dictionary D){

    insertData(D, 0);
    insertData(D, 23);
    insertData(D, 12);
    insertData(D, 32);
    insertData(D, 14);
    insertData(D, 68);
    insertData(D, 2);
    insertData(D, 8);
}

void displayDictionary(Dictionary D){

    List trav;

    for (int i = 0; i < MAX; i++){

        printf("Group %d: ", i);
        for (trav = D[i]; trav != NULL; trav = trav->next){
            printf("%d", trav->data);
            if (trav->next != NULL){
                printf("-->");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isMember(Dictionary D, int data){

    List trav;
    int key;
    key = hash(data);

    for (trav = D[key]; trav != NULL && trav->data < data; trav = trav->next){}

    return (trav != NULL && trav->data == data) ? 1 : 0;
}

void deleteMember(Dictionary D, int data){

    List *trav, temp;
    int key;
    key = hash(data);

    for (trav = &D[key]; *trav != NULL && (*trav)->data < data; trav = &(*trav)->next){}

    if (*trav != NULL && (*trav)->data == data){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}