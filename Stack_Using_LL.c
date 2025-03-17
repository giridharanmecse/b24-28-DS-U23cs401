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

int isEmpty(struct stack * s){
    if(s->head == NULL){
        return 1;
    } else {
        return 0;
    }
}


void pop(struct stack * s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    } else {
        if(s->head->next == NULL){
            s->head = NULL;
        } else {
            s->head = s->head->next;
        }
        
    }
}

struct node * peek(struct stack * s){
    if(isEmpty(s)){
        return NULL;
    } else {
        return s->head;
    }
}


void display(struct stack * s){
    if(isEmpty){
        printf("Stack is empty\n");
    } else {
        struct node * temp = s->head;
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int val,choice;
    struct stack * s = NULL;
    s = createStack();
    do{
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. isEmpty\n");
        printf("6. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the Value to Be added\n");
                scanf("%d",&val);
                push(s,val);
                printf("The elements in stack :");
                display(s);
                break;
            case 2:
                printf("The elements in stack :");
                display(s);
                pop(s);
                printf("The elements in stack :");
                display(s);
                break;
            case 3:
                struct node * n = peek(s);
                if(n == NULL){
                    printf("Stack ks Empty\n");
                } else {
                    printf("The top element is %d\n",n->data);
                }
                break;



    }
}





