/*structr user{
	int id;
	char name[50];
	char email[50];
	struct user * next;
}*/

struct node{
	int data;
	struct node * next;
}
/*//CRUD ->Create|Read|Update|Delete//
1) Create A node
2) Inset at first
3) insert At last
3) Insert at Spercific Position
4) Delete at First
5) Delete at Last
6) Delete at Specific Position
7) Display
8) update data*/
struct node * createNode(int data){
	struct node * newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return nn;
}

struct node * insertAtLast(struct node * head,int data){//100x,20
	struct node * nn = creatNode(data);//200x
	if(head == NULL){
		return nn;
	} else{
		struct node * temp = head; // 100x
		while(temp->next !=NULL){ // NULL !=NULL
			temp = temp->next;
		}
		temp->next = nn;//100x->next = 200x

	}
	return head;
}

	


int main{
	struct node * head = NULL;
	int data,choice;
	do{
		printf("1) Insert At First\n");
		printf("2) Insert At Last\n");
		printf("3) Insert At Specific Position"\n");
		printf(""Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				
			case 2:
				head = insertAtLast(head,int data);/100x,20
			case 3:
		}
	} while(choice >=1 && choice <=3);
			
