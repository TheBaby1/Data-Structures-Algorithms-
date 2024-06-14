#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY -1
#define DELETED -99
#define SIZE 8

typedef struct {
    int number;
    char FN[20];
    char LN[20];
    char MI;
    int yearLevel;
} studType;

typedef studType Dictionary[SIZE];

void initialize(Dictionary D);
int hash(int idNumber);
bool isMember(Dictionary D, studType A);
void insert(Dictionary D, studType A);
void delete(Dictionary D);

void display(Dictionary D);

int main(){

    Dictionary D;
    initialize(D);

    studType A[] = {{20101049, "Nikko", "Ensomo", 'B', 3},
                    {23010304, "Marcelo", "Meneses", 'C', 4},
                    {19304234, "Dominic", "Dagale", 'O', 3}
                    };

    insert(D, A[1]);
    insert(D, A[0]);
    insert(D, A[2]);


    display(D);

    return 0;
}

void initialize(Dictionary D){

    for (int i = 0; i < SIZE; i++){
        D[i].number = EMPTY;
        strcpy(D[i].FN, "");
        strcpy(D[i].LN, "");
        D[i].MI = '\0';
        D[i].yearLevel = EMPTY;
    }
}

int hash(int idNumber){

    int sum = 0;

    while (idNumber != 0){
        sum += (idNumber % 10);
        idNumber /= 10;
    }

    return sum % SIZE;
}

void insert(Dictionary D, studType A){

    int hashValue, i, counter = 0;

    hashValue = hash(A.number);

    if (isMember(D, A) == 0){
        if (D[hashValue].yearLevel == EMPTY || D[hashValue].yearLevel == DELETED){
            D[hashValue] = A;
        } else {
            i = (hashValue + 1) % SIZE;

            while (i != hashValue && D[i].yearLevel != EMPTY && D[i].yearLevel != DELETED){
                i = (i + 1) % SIZE;
            }
            D[i] = A;
        }
    } else {
        printf("Already in the dictionary\n");
    }
}

bool isMember(Dictionary D, studType A){

    int i, hashValue = hash(A.number);

    bool retVal = 0;

    if (D[hashValue].number == A.number){
        retVal = 1;
    } else {
        i = (hashValue + 1) % SIZE;

        printf("here: %d %d\n", i, hashValue);

        while (i != hashValue && D[i].number != A.number){
            i = (i + 1) % SIZE;
        }

        retVal = (D[hashValue].number == A.number) ? 1 : 0;
    }

    printf("\n%d %d\n\n", D[i].yearLevel, D[hashValue].yearLevel);

    return retVal;
}

void display(Dictionary D){

    for (int i = 0; i < SIZE; i++){
        printf("Index [%d]: ", i);

        if (D[i].yearLevel == DELETED){
            printf("Deleted Node!");
        } else {
            printf("%s", D[i].LN);
        }

        printf("\n");
    }
}