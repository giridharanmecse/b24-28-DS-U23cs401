#include<stdio.h>
#include<stdlib.h>
/*structr user{
	int id;
	char name[50];
	char email[50];
	struct user * next;
}*/

struct node{
	int data;
	struct node * next;
};
/*//CRUD ->Create|Read|Update|Delete//
1) Create A node - completed
2) Inset at first - completed
3) insert At last - completed
3) Insert at Spercific Position - completed
4) Delete at First - Completed
5) Delete at Last - Completed
6) Delete at Specific Position - Completed
7) Display - Completed
8) update data - Completed
9) count node - completed*/
struct node * createNode(int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct node * insertAtFirst(struct node * head, int data){
	struct node *  nn = createNode(data);
	if(head == NULL){
		return nn;
	} else {
		nn->next = head;
		return nn;
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

	}
	return head;
}
struct node * insertAtSpecificPosition(struct node * head, int data , int pos){
	//struct node * nn = createNode(data);
	int count = 0;
	struct node * temp = head;
	struct node * prev = NULL;
	if(head == NULL && pos >1){
		return NULL;
	} else if(pos == 1){
		return insertAtFirst(head,data);
	} else{
		while(temp!=NULL){
			count++;
			if(count == pos){
				struct node * nn = createNode(data);
				nn->next = temp;
				prev->next = nn;
				return head;
			}
			prev = temp;
			temp = temp->next;
		}
		if(count+1 == pos){
			struct node * nn = createNode(data);
			prev->next = nn;
			//return insertAtLast(head,data);
		}	
		return head;
	}
}

struct node * deleteAtFirst(struct node * head){
	if(head == NULL){
		return NULL;
	} else {
		return head->next;
	}
}


struct node * deleteAtLast(struct node * head){
	if(head == NULL){
		return NULL;
	} else if(head ->next == NULL){
		return NULL;
	} else {
		struct node * prev = NULL;
		struct node * temp = head;
		while(temp->next != NULL){
			prev = temp;
			temp = temp->next;
		}
		if(prev == NULL){
			return NULL;
		} else {
			prev->next = NULL;
			return head;
		}
		
	}
}

struct node * deleteAtSpecificPosition(struct node * head,int pos){
	if(head==NULL){
		return NULL;
	} else if( pos == 1){
		return head->next;
	} else {
		int count=0;
		struct node * prev = NULL;
		struct node * temp = head;
		while(temp!=NULL){
			count++;
			if(count == pos){
				prev->next = temp->next;
				return head;
			}
			prev = temp;
			temp = temp->next;

		}
	}
}


int updateValue(struct node * head,int searchKey,int updatedValue){
	if(head == NULL){
		return 0;
	} else{
		struct node * temp = head;
		while(temp!=NULL){
			if(temp->data == searchKey){
				temp->data = updatedValue;
				return 1;
			}
			temp = temp->next;
		}
		return 0;
	}
}
void display(struct node * head){
	if(head == NULL){
		return;
	} else {
		struct node * temp = head;
		while(temp != NULL){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}	


int main(){
	struct node * head = NULL;
	int data,choice,pos,searchKey,updatedValue,status;
	do{
		printf("1) Insert At First\n");
		printf("2) Insert At Last\n");
		printf("3) Insert At Specific Position\n");
		printf("4) Delete At First\n");
		printf("5) Delete At Last\n");
		printf("6) Delete At Specific Position\n");
		printf("7) Update value\n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the Data To be Inserted:\n");
				scanf("%d",&data);
				head = insertAtFirst(head,data);
				printf("List after inserting:\n");
				display(head);
				break;				
			case 2:
				printf("Enter the Data To be Inserted:\n");
				scanf("%d",&data);
				head = insertAtLast(head,data);
				printf("List after inserting:\n");
				display(head);
				break;
			case 3:
				printf("Enter the Data To be Inserted:\n");
				scanf("%d",&data);
				printf("Enter the position to be inserted:\n");
				scanf("%d",&pos);
				head = insertAtSpecificPosition(head,data,pos);
				printf("List after inserting:\n");
				display(head);
				break;
			case 4:				
				printf("Before Deleting\n");
				display(head);
				head = deleteAtFirst(head);
				printf("After Deleting:\n");
				display(head);
				break;
			case 5:
				printf("Before Deleting\n");
				display(head);
				head = deleteAtLast(head);
				printf("After Deleting:\n");
				display(head);
				break;
			case 6:
				printf("Enter the position to be Deleted:\n");
				scanf("%d",&pos);
				printf("Before Deleting\n");
				display(head);
				head = deleteAtSpecificPosition(head,pos);
				printf("After Deleting:\n");
				display(head);
				break;
			case 7:
				printf("Enter the SearchKey:\n");
				scanf("%d",&searchKey);
				printf("Enter the Valur to be updated:\n");
				scanf("%d",&updatedValue);
				printf("Before Updating\n");
				display(head);
				status = updateValue(head,searchKey,updatedValue);
				if(status == 1){
					printf("After Updating:\n");
					display(head);
				} else {
					printf("List not Updated:\n");
					display(head);
				}				
				break;
		}
	} while(choice >=1 && choice <=7);
	return 0;
}
			
