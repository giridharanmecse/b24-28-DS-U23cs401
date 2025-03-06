#include<stdio.h>
#include<stdlib.h>
//Creating user defined data type node
struct node {
    int data;
    struct node * next;
};


struct node * createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node * insertAtFirst(struct node ** headAddress,struct node ** tailAddress,int data){
    struct node * newNode = createNode(data);
    struct node * head = headAddress;
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }else {

    }
}



int main(){
    struct node * head = NULL;
    struct node * tail = NULL;
    head = insertAtFirst(&head,&tail, 10);
}
