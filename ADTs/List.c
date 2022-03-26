#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*STATIC LIST
- CREATING A LIST THAT STORES A GIVEN NUMBER OF ELEMENTS OF A GIVEN DATA-TYPE
- WRITE/MODIFY AN ELEMENT AT A POSITION
- READ ELEMENT AT A POSITION*/

/*DYNAMIC LIST: ACCESS, INSERT, REMOVE, ADD
- EMPTY LIST HAS SIZE 0
- INSERT/REMOVE ELEMENT AT ANY POSITION
- COUNT ELEMENTS
- READ/MODIFY ELEMENT AT ANY POSITION
- SPECIFY DATA-TYPE*/

struct Node{
    int data;
    struct Node* next;
};
struct Node* head; /*GLOBAL VAR, STORES FIRST ADDRESS OF LINKED LIST*/

void main(){
    int i, numbers, aux;
    printf("How many numbers do you wanna allocate? ");
    scanf("%d", &numbers);
    for(i = 0; i < numbers; i++){
        printf("Enter number: ");
        scanf("%d", &aux);
        InsertB_List(aux);
    }
    Print_List();
    InsertN_List(5, 2);
    Print_List();
    DeleteN_List(2);
    Print_List();
    head = Reverse_List(head);
    Print_List();
}

void New_List(){
    head = NULL; /*EMPTY LIST*/
}

void InsertB_List(int n){
    struct Node* cell = (struct Node*)malloc(sizeof(struct Node));
    cell->data = n;
    cell->next = head;
    head = cell;
}

void Print_List(){
    struct Node* cell = head;
    printf("\nList: ");
    while(cell != NULL){
        printf("%d ", cell->data);
        cell = cell->next;
    }
}

void InsertN_List(int data, int position){
    int i;
    struct Node* cellA = (struct Node*)malloc(sizeof(struct Node*)); /*FIRST ALLOCATE NODE YOU'RE GONNA USE*/
    cellA->data = data;
    cellA->next = NULL;
    if(position == 1){ /*IF IT'S FIRST POSITION, LINK FIELD OF NODE A IS HEAD AND HEAD RECEIVES ADDRESS OF NODE A*/
        cellA->next = head; /*RECEIVES NULL*/
        head = cellA; /*HEAD NODE POINTS TO MEMORY OF CELL A*/
        return;
    }
    struct Node* cellB = head; /*NODE B POINTS TO HEAD NODE*/
    for(i = 0; i < position - 2; i++){ /*GO THROUGH LIST UNTIL REACH POSITION - 2*/
        cellB = cellB->next;
    }
    cellA->next = cellB->next;
    cellB->next = cellA;
}

void DeleteN_List(int position){
    int i;
    struct Node* cellA = head;
    for(i = 0; i < position - 2; i++){ /*CELL A POINTS TO (N-1)TH NODE*/
        cellA = cellA->next;
    }
    struct Node* cellB = cellA->next; /*CELL B IS EQUIVALENT TO NTH NODE*/
    cellA->next = cellB->next; /*CELL A STORES (N+1)TH NODE*/
    free(cellB); /*DELETE CELL B*/
}

struct Node* Reverse_List(struct Node* head){
    struct Node* current, *previous, *next;
    current = head;
    previous = NULL;
    while(current != NULL){ /*GETS LAST NODE*/
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}