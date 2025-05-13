#include<stdio.h>
struct node {
    int data;
    struct node * next;
};

struct node * createNode(int data){
    struct node * newNode =  (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node * insertAtFirst(struct node * head,int data){
    struct node * newNode = createNode(data);
    if(head == NULL){
        return newNode;
    } else {
        newNode->next = head;
        return newNode;
    }   

}

void insertAtFirst(struct node ** headAddress,int data){

}

int main(){
    struct node * head = NULL;
    head = inserAtFirst(&head,10);
}

/*
1) Insert at First
2) Insert at Last
3) Insert At Specific Position
4) Delete at First
5) Delete at Last
6) Delete at Specific Position
7) Read
*/