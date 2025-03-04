/* 
1) Create array - completed
2) getValue - completed
3) Display / view - completed
4) Insert at first - Completed
5) Insert at last - completed
6) Insert at specific position - completed
7) Delete at first - completed
8) Delete at last - completed
9) Delete at specific Position - completed
10) update at specific index - Assignment
*/
#include<stdio.h>
#include<stdlib.h>
int lastIndex = 0;
int * createArray(int size){
	//int * temp;
	return (int *) malloc(sizeof(int)*size);
	//return temp;
} 

void getvalue(int * arr,int size){
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}
}

void display(int * arr){
	for(int i=0;i<lastIndex;i++){
		printf("%d\n",*(arr+i));
	}
}

void insertAtFirst(int * arr,int val){	
	for(int i=lastIndex;i>0;i--){
		arr[i] = arr[i-1];
	}	
	arr[0] = val;	
	lastIndex++;
}
void insertAtLast(int * arr,int val){
	arr[lastIndex] = val;
	lastIndex++;
}


void insertAtSpecificPosition(int * arr, int val,int index){
	if(index>lastIndex){
		printf("I cannot insert at the given position\n");
		return;
	}
	for(int i=lastIndex;i>index;i--){
		arr[i] =arr[i-1];
	}
	arr[index] = val;
	lastIndex++;
}

int deleteAtFirst(int * arr){
	int temp = arr[0];
	for(int i=0;i<lastIndex-1;i++){
		arr[i] = arr[i+1];
	}
	lastIndex--;
	return temp;
}

int deleteAtLast(int * arr){
	return arr[--lastIndex];
}

int deleteAtSpecificPosition(int * arr,int pos){
	int temp = arr[pos];
	for(int i=pos;i<lastIndex-1;i++){
		arr[i] = arr[i+1];
	}
	lastIndex--;
	return temp;
}
void updateValueatIndex(int * arr, int index,int val){
	arr[index] = val;
}

int main(){
	int * arr;//store starting address	
	int size,choice,val,index;	
	printf("Enter the size of the array:\n");
	scanf("%d",&size);
	arr = createArray(size);
	do{
		printf("1) Insert At First\n");
		printf("2) Insert At Last\n");
		printf("3) Insert At Specific Position\n");
		printf("4) Delete At First\n");
		printf("5) Delete At Last\n");
		printf("6) Insert At Specific Position\n");
		printf("Enter your choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the value to be inserted\n");
				scanf("%d",&val);
				insertAtFirst(arr,val);
				printf("After inserting at first my array is:\n");
				display(arr);
				break;
			case 2:
				printf("Enter the value to be inserted\n");
				scanf("%d",&val);
				insertAtLast(arr,val);
				printf("After inserting at first my array is:\n");
				display(arr);
				break;
			case 3:
				printf("Enter the value to be inserted\n");
				scanf("%d",&val);
				printf("Enter the index to be inserted\n");
				scanf("%d",&index);
				insertAtSpecificPosition(arr,val,index);
				printf("After inserting my array is:\n");
				display(arr);
				break;
			case 4:
				val = deleteAtFirst(arr);
				printf("The deleted Value is %d.\n",val);
				printf("Array After Deleting\n");
				display(arr);
				break;
			case 5:
				val = deleteAtLast(arr);
				printf("The deleted Value is %d.\n",val);
				printf("Array After Deleting\n");
				display(arr);
				break;
			case 6:
				printf("Enter the index to be Deleted\n");
				scanf("%d",&index);
				val = deleteAtSpecificPosition(arr,index);
				printf("The deleted Value is %d.\n",val);
				printf("Array After Deleting\n");
				display(arr);
				break;
			case 7:
				printf("Enter the index to be updated\n");
				scanf("%d",&index);
				printf("Enter the value to be updated\n");
				scanf("%d",&val);
				updateValueatIndex(arr,index,val);
				//printf("The deleted Value is %d.\n",val);
				printf("Array After Updating\n");
				display(arr);
				break;
		}
				
	}while(choice >=1 && choice <=7);
	//insertAtFirst(arr,size);
	//getvalue(arr,size);
	display(arr);
	return 0;
}







