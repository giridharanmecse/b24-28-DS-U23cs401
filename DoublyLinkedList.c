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

struct node * insertAtSpecificPosition(struct node * head,int data,intr pos){
    if(head == NULL & pos>1){
        printf("Data cannot be inserted at the Given Position");
        return NULL;
    } else if (pos == 1){
        return insertAtFirst(head,data);
    } else {
        struct node * newNode = createNode(data);
        struct node * temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            if(count == pos-1){
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                newNode->prev = temp;
                return head;
            }
            temp = temp->next;
        }
        if(count==pos-1){
            temp->next = newNode;
            newNode->prev = temp;
        }
        return head;
    }
}

struct node * deleteAtFirst(struct node * head){
    if(head == NULL){
        return NULL;
    } else if(head->next == NULL){
        free(head);
        return NULL;
    }else {
        struct node * temp = head;
        head->next->prev = NULL;
        head = head->next;
        free(temp);
        return head;
        
    }
}

struct node * deleteAtLast(struct node * head){
    if(head == NULL){
        return NULL;
    } else if(head->next == NULL){
        free(head);
        return NULL;
    } else {
        struct node * temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        
        temp->prev->next = NULL;
        free(temp);
        return head;
    }
}


int main(){
    return 0;
}