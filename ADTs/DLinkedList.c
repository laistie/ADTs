#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

/*EACH NODE WILL HAVE TWO LINKS: ONE TO NEXT AND OTHER TO PREVIOUS*/

struct Node{
    int data;
    struct Node* next;
    struct Node* previous;
};
struct Node* head; /*GLOBAL VAR, POINTER TO HEAD NODE*/

void main(){
    InsertB_List(1);
    InsertB_List(2);
    InsertB_List(3);
    Print_List();
    Reverse_Print();
}

void New_List(){
    head = NULL;
}

struct Node* New_Node(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertB_List(int data){
    struct Node* cell = New_Node(data);
    if(head == NULL){
        head = cell;
        return;
    }
    head->previous = cell;
    cell->next = head;
    head = cell;
}

void Print_List(){
    struct Node* cell = head;
    printf("List: ");
    while(cell != NULL){
        printf("%d ", cell->data);
        cell = cell->next;
    }
    printf("\n");
}

void Reverse_Print(){
    struct Node* cell = head;
    if(cell == NULL){ /*IN CASE OF EMPTY LIST*/
        return;
    }
    while(cell->next != NULL){ /*GOING TO LAST NODE*/
        cell = cell->next;
    }
    printf("Reversed List: ");
    while(cell != NULL){ /*TRAVERSING BACKWARD USING PREVIOUS POINTER*/
        printf("%d ", cell->data);
        cell = cell->previous;
    }
    printf("\n");
}