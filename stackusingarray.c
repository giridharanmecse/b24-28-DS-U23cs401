#include<stdio.h>
#include<stdlib.h>
/*
1) push()-> insert at Top
2) pop() ->delete at top
3) peek() ->view at top
4) isFull() ->check stack is full or not
5) isEmpty() ->check stack is empty or not
*/

struct stack{
    int * arr;
    int size;
    int top;
};


struct stack * creatStack(int size){
    struct stack * newStack = (struct stack *)malloc(sizeof(struct stack));
    newStack->size = size;
    newStack->top = -1;
    newStack->arr = (int *)malloc(sizeof(int)*size);
    return newStack;
}

/*
isEmpty ()
0 -> stack is not empty
1 - Stack is Empty
*/


int isEmpty(struct stack * s){
    if(s->top == -1){
        return 1;
    } else {
        return 0;
    }

}

/*
isfull()
0 -> stack is not full
1 -> stack is full
*/

int isFull(struct stack * s){
    if(s->top==s->size-1){
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack * s,int val){
    if(isFull(s)){
        printf("Stack is full\n");
    } else {
        s->arr[++s->top] = val;
    }
}

int pop(struct stack * s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -9999;
    } else {
        return s->arr[s->top--]; 
    }
}

int peek(struct stack * s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -9999;
    } else {
        return s->arr[s->top];
    }
}

void display(struct stack * s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    } else {
        for(int i=s->top;i>=0;i--){
            printf("%d ",s->arr[i]);
        }
    }
}




int main(){
    struct stack * s = NULL;
    int size,choice,val;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    s = creatStack(size);
    do{
        printf("\nStack Operations\n");
        printf("1) push\n");
        printf("2) pop\n");
        printf("3) peek\n");
        printf("4) isEmpty\n");
        printf("5) isFull\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d",&val);
                push(s,val);
                printf("After pushing %d the stack is: ",val);
                display(s);
                break;
            case 2:
                val = pop(s);
                if(val != -9999){
                    printf("The Poped Element is : %d\n",val);
                }
                printf("After pop the stack looks like : ");
                display(s);
                break;
            case 3:
                val = peek(s);
                if(val != -9999){
                    printf("The peek Element is : %d\n",val);
                }
                printf("The Elements in the stack looks like : ");
                display(s);
                break;                
            case 4:
                val = isEmpty(s);
                val==1?printf("Stack is Empty\n"):printf("The Stack is not empty\n");
                break;
            case 5:
                val = isFull(s);
                val == 1? printf("The Stack is Full\n"):printf("The stack is not Full\n");
        }

    }while(choice >=1 && choice <=5);
}