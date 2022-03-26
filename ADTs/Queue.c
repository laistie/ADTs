#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*LIST WITH THE RESTRICTION THAT INSERTION CAN BE PERFORMED AT ONE END (REAR) AND DELETION CAN PÉRFORMED AT OTHER END (FRONT)*/
/*FIRST IN, FIRST OUT*/

struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void main(){
    Enqueue(1);
    Enqueue(2);
    Print_Queue();
    Enqueue(3);
    Print_Queue();
    Dequeue();
    Print_Queue();
}

void Enqueue(int data){
    struct Node* cell = (struct Node*)malloc(sizeof(struct Node*));
    cell->data = data;
    cell->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = cell;
        return;
    }
    rear->next = cell;
    rear = cell;
}

void Dequeue(){
    struct Node* cell = front;
    if(front == NULL){
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    free(cell);
}

void Print_Queue(){
    struct Node* cell = front;
    printf("Queue: ");
    while(cell != NULL){
        printf("%d ", cell->data);
        cell = cell->next;
    }
    printf("\n");
}