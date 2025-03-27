#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node * next;
}Node;

typedef struct queue{    
    Node * front;
    Node * rear;
}Queue;

Node * createNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue * createQueue(){
    Queue * q = (Queue *) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueu(Queue * q,int data){
    Node * newNode = createNode(data);
    if(q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int isEmpty(Queue * q){
    if(q->front ==NULL){
        return 1;
    } else {
        return 0;
    }
    
}

int dequeue(Queue * q){
    if(isEmpty(q)){
        return -99999;
    } else {
        Node * temp = q->front;
        q->front = q->front->next;
        if(q->front == NULL){
            q->rear = NULL;
        }
        free(temp);
        return temp->data;
    }
}
  
int getFirst(Queue * q){
    if(isEmpty(q)){
        return -99999;
    } else {
        return q->front->data;
    }
}


int getLast(Queue * q){
    if(isEmpty(q)){
        return -99999;
    } else {
        return q->rear->data;
    }
}


void display(Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    } else {
        Node * temp = q->front;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main(){
    Queue * q = createQueue();
    int val;
    int choice;
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get First\n");
        printf("4. Get Last\n");
        printf("5. Display\n");
        printf("6. isEmpty\n");
        printf("7. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d",&val);
                enqueu(q,val);
                display(q);
                break;
            case 2:
                val = dequeue(q);
                if(val == -99999){
                    printf("Queue is empty\n");
                } else {
                    printf("Dequeued value is %d\n",val);
                }
                display(q);
                break;
            case 3:
                val = getFirst(q);
                if(val == -99999){
                    printf("Queue is empty\n");
                } else {
                    printf("First value is %d\n",val);
                }
                break;
            case 4:
                val = getLast(q);
                if(val == -99999){
                    printf("Queue is empty\n");
                } else {
                    printf("Last value is %d\n",val);
                }
                break;
            case 5:
                display(q);
                break;
            case 6:
                if(isEmpty(q)){
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 7:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice >= 1 && choice <= 6);
    return 0;
}