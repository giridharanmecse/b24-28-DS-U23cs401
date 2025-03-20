#include<stdio.h>
#include<stdlib.h>
struct stack {
    char * arr;
    int size;
    int top;
};

struct stack * createStack(int size){
    struct stack * stack = (struct stack *)malloc(sizeof(struct stack));
    stack->arr = (char *)malloc(size * sizeof(char));
    stack->size = size;
    stack->top = -1;
}
int priority(char ch){
    if(ch == '^'){
        return 3;
    } else if(ch == '*' || ch == '/'){
        return 2;
    } else if(ch == '+' || ch == '-'){
        return 1;
    } else {
        return -1;
    }
}

int isEmpty(struct stack * s){
    if(s->top == -1){
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct stack * s){
    if(s->top == s->size-1){
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack * s,char ch){
    if(isFull(s)){
        printf("Stack Overflow\n");
    } else {
        s->arr[++s->top] = ch;
    }
}

char pop(struct stack * s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return '$';
    } else {
        return s->arr[s->top--];
    }    
}

char peek(struct stack * s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return '$';
    } else {
        return s->arr[s->top];
    }   
}


int main(){
    struct stack * s = NULL;
    char arr[100];    
    int size;
    char ch;
    int j =0 ;
    scanf("%s%n",arr,&size);
    char postfix[size+1];
    s = createStack(size);
    for(int i=0;i<size;i++){
        ch = arr[i];
        if(ch>='a' && ch<='z'){
            postfix[j++] = ch;
        }else if(ch =='('){
            push(s,ch);
        } else if(ch == ')'){
            while(peek(s)!='('){
                postfix[j++] = pop(s);
            }
            pop(s);
        } else {
            while(!isEmpty(s) && priority(peek(s))>priority(ch)){
                postfix[j++] = pop(s);
            }
            push(s,ch);
        }
    }
    while(!isEmpty(s)){
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    printf("%s\n",postfix);

}