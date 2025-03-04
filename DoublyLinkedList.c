#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
};

struct node * createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct node * InsertAtFirst(struct node * head,int data){
    struct node * newNode = createNode(data);
    if(head == NULL){
        return newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
}