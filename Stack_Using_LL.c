#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};

struct stack{
    struct node * head;
    // int size;
    // struct node * top;
};

struct stack * createStack(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->head = NULL;
    return s;
}

struct node * creatNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct stack * s, int data){
    struct node * newNode = creatNode(data);
    if(s->head == NULL){
        s->head = newNode;
    } else {
        newNode->next = s->head;
        s->head = newNode;
    }
}