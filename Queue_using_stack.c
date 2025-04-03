#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int top;
    int *arr;
    int size;
}stack;


stack * createStack(int size){
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = size;
    s->arr = (int *)malloc(size * sizeof(int));
    return s;
}


int isFull(stack *s){
    if(s->top == s->size - 1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(stack *s, int data){
    if(isFull(s)){
        printf("Stack is full\n");
        return;
    }else{
        s->arr[++s->top] = data;
    }
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }else{
        return s->arr[s->top--];
    }
}

void enqueue(stack *s1,int data){
    push(s1,data);
}

int dequeue(stack * s1,stack *s2){
    if(isEmpty(s1) && isEmpty(s2)){
        printf("Queue is empty\n");
        return -999;
    }
    while(!isEmpty(s1)){
        push(s2,pop(s1));
    }
    int val = pop(s2);
    while(!isEmpty(s2)){
        push(s1,pop(s2));
    }
    return val;
}

void display(stack *s){
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main(){
    int size;
    int val;
    int choice;
    stack *s1 = NULL;
    stack * s2 = NULL;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    s1 = createStack(size);
    s2 = createStack(size);
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d",&val);
                enqueue(s1,val);
                printf("Queue after enqueue: ");
                display(s1);
                break;
            case 2:
                val = dequeue(s1,s2);
                if(val != -999){
                    printf("Dequeued value: %d\n",val);
                }
                printf("Queue after dequeue: ");   
                display(s1);
                break;
            case 3:
                printf("Queue: ");
                display(s1);
                break;
            case 4:
                printf("Exiting...\n");
                break;
        }
    }while(choice >=1 && choice <= 3);
    return 0;
}