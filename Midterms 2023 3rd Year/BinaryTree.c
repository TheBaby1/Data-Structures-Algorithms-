#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *BST, nodeType;

typedef enum {
    TRUE,
    FALSE,
} Boolean;

Boolean isMember(BST Tree, int data);

int main(){

    


    return 0;
}

Boolean isMember(BST tree, int data){

    BST trav = tree;

    while (trav != NULL && trav->data != data){
        if (data < trav->data){
            trav = trav->left;
        }

        if (data > trav->data){
            trav = trav->right;
        }
    }

    return (trav != NULL) ? TRUE : FALSE;
}

void insertData(BST tree, int data){

    BST newNode, trav;
    newNode = malloc(sizeof(nodeType));
    newNode->data = data;

    if (tree == NULL){
        newNode->left = NULL;
        newNode->right = NULL;
        trav = newNode;
    } else {
        for (trav = tree; trav != NULL && trav->data != data;){
            if (trav->data < data){
                trav = trav->left;
            }

            if (trav->data > data){
                trav = trav->right;
            }
        }

        newNode->left = NULL;
        newNode->right = NULL; 
        trav->left = newNode;
    }

}