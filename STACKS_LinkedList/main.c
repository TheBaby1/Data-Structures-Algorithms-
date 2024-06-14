#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "StackLinkedList.h"

int main(){

    StackLinkedList *head; 
    initStack(&head);

    push(&head, 32);
    push(&head, 22);
    push(&head, 13);
    push(&head, 65);

    displayStack(head);
    visualizeStack(head);
    
    StackLinkedList newStack = getEven(head);
    displayStack(&newStack);

    return 0;
}
