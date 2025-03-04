#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * prev;
    struct node * next;
};

/*
struct user{
    int id;
    char name[100];
    char email[100];
    int mobile;
    struct user * prev;
    struct user * next;
}
*/
struct node * createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct node * insertAtFirst(struct node * head,int data){
    struct node * newNode = createNode(data);
    if(head == NULL){
        return newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
}

struct node * insertAtLast(struct node * head,int data){
	struct node * nn = createNode(data);
	if(head == NULL){
		return nn;
	} else{
		struct node * temp = head; 
		while(temp->next !=NULL){ 
			temp = temp->next;
		}
		temp->next = nn;
        nn->prev = temp;
	}
	return head;
}




int main(){
    return 0;
}