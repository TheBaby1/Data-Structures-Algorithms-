#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fName[20];
    char lName[20];
} studName;

typedef struct {
    int month;
    int year;
} bday;

typedef struct {
    studName name;
    bday birthdate;
    int age;
    int idNum;
} studentInfo;

typedef struct {
    studentInfo studArray[20];
    int studCount;
} classRecord;

void insertAtFront(classRecord *record, studentInfo student) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    for (int i = record->studCount; i > 0; i--) {
        record->studArray[i] = record->studArray[i - 1];
    }
    record->studArray[0] = student;
    record->studCount++;
}

void insertAtRear(classRecord *record, studentInfo student) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    record->studArray[record->studCount] = student;
    record->studCount++;
}

void insertAtPosition(classRecord *record, studentInfo student, int position) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    if (position < 0 || position > record->studCount) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = record->studCount; i > position; i--) {
        record->studArray[i] = record->studArray[i - 1];
    }
    record->studArray[position] = student;
    record->studCount++;
}

void insertSortedByAge(classRecord *record, studentInfo student) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    int i = 0;
    while (i < record->studCount && record->studArray[i].age <= student.age) {
        i++;
    }
    insertAtPosition(record, student, i);
}

void deleteAtFront(classRecord *record) {
    if (record->studCount <= 0) {
        printf("Class is empty.\n");
        return;
    }
    for (int i = 0; i < record->studCount - 1; i++) {
        record->studArray[i] = record->studArray[i + 1];
    }
    record->studCount--;
}

void deleteAtRear(classRecord *record) {
    if (record->studCount <= 0) {
        printf("Class is empty.\n");
        return;
    }
    record->studCount--;
}

void deleteAtPosition(classRecord *record, int position) {
    if (record->studCount <= 0) {
        printf("Class is empty.\n");
        return;
    }
    if (position < 0 || position >= record->studCount) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < record->studCount - 1; i++) {
        record->studArray[i] = record->studArray[i + 1];
    }
    record->studCount--;
}

void printClassRecord(classRecord *record) {
    for (int i = 0; i < record->studCount; i++) {
        printf("Student yeah %d: %s %s, Age: %d, ID: %d, Birthdate: %d/%d\n",
               i + 1,
               record->studArray[i].name.fName,
               record->studArray[i].name.lName,
               record->studArray[i].age,
               record->studArray[i].idNum,
               record->studArray[i].birthdate.month,
               record->studArray[i].birthdate.year);
    }
}

int main(void) {
    classRecord myClass = {.studCount = 0};
    studentInfo student1 = {{"John", "Doe"}, {5, 2000}, 24, 1};
    studentInfo student2 = {{"Jane", "Smith"}, {7, 1999}, 25, 2};
    studentInfo student3 = {{"Emily", "Jones"}, {12, 2001}, 22, 3};

    insertAtFront(&myClass, student1);
    insertAtRear(&myClass, student2);
    insertSortedByAge(&myClass, student3);
    
    printf("Class Record after insertions:\n");
    printClassRecord(&myClass);

    deleteAtFront(&myClass);
    printf("\nClass Record after deleting at front:\n");
    printClassRecord(&myClass);

    deleteAtRear(&myClass);
    printf("\nClass Record after deleting at rear:\n");
    printClassRecord(&myClass);

    insertAtRear(&myClass, student2);
    insertAtRear(&myClass, student1);
    deleteAtPosition(&myClass, 1);
    printf("\nClass Record after deleting at position 1:\n");
    printClassRecord(&myClass);

    return 0;
}
