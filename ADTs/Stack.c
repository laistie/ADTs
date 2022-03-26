#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/*A LIST WITH THE RESTRICTION THAT INSERTION AND DELETION CAN ONLY BE PERFORMED FROM ONE END (TOP)*/
/*LAST IN, FIRST OUT*/

struct Node{
    int data;
    struct Node* link;
};
struct Node* top = NULL;

void main(){
    Push(1);
    Push(2);
    Push(3);
    Print_Stack();
    Pop();
    Print_Stack();
}

void Push(int data){
    struct Node* cell = (struct Node*)malloc(sizeof(struct Node*));
    cell->data = data;
    cell->link = top;
    top = cell;
}

void Pop(){
    struct Node* cell;
    if(top == NULL){
        return;
    }
    cell = top;
    top = top->link; /*TOP POINTS TO NEXT NODE IN STACK*/
    free(cell); /*FREEING MEMORY ALLOCATED TO CELL THAT'S CURRENTLY ON TOP*/
}

void Print_Stack(){
    struct Node* cell = top;
    printf("Stack: ");
    while(cell != NULL){
        printf("%d ", cell->data);
        cell = cell->link;
    }
    printf("\n");
}