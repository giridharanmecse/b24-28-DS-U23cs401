/*
problem : https://leetcode.com/problems/valid-parentheses/description/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


ex1: 
"()" -> valid 
()( -> Invalid 
({[] -> in valid
{(}) -> ->Invalid 
{[]([]{})} -> valid 
{(){[][](){[][]}}} -> valid
{[()]} -> valid

1) creat a char stack
2) open bracket ->push
3) close ->pop -> if the poped element is a match then we continue

*/
#include<stdio.h>
#include<stdlib.h>
struct stack{
    char * arr;
    int size;
    int top;
};

struct stack * creatStack(int size){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->arr = (char *)malloc(size * sizeof(char));
    return s;
}

int isEmpty(struct stack * s){
    if(s->top == -1){
        return 1;
    } else {
        return 0;
    }
}


int isFull(struct stack * s){
    if(s->top == s->size - 1){
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
        return '*';
    } else {
        return s->arr[s->top--];
    }
}

void viewStack(struct stack * s){
    for(int i = 0; i <= s->top; i++){
        printf("%c ",s->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack * s = NULL;
    char arr[100];
    int size;
    scanf("%s%n",arr,&size);
    s = creatStack(size);
    return 0;
}