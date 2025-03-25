#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int * arr;
    int capacity;
    int front;
    int rear;
}queue;

queue * createQueue(int capacity){
    queue * q = (queue *)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(sizeof(int) * capacity);
    return q;
}

int isFull(queue * q){
    if(q->rear == q->capacity-1){
        return 1;
    } else {
        return 0;
    }
}

void enqueue(queue * q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    } else {
        if(q->rear == -1){
            q->front = 0;
            q->rear = 0;
            q->arr[q->rear] = val;            
        } else {
            q->arr[++q->rear] = val;
        }
    }
}

int isEmpty(queue * q){
    if(q->front == -1){
        return 1;
    } else {
        return 0;
    }
}


int dequeue(queue * q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -99999;
    } else {
        int val = q->arr[q->front];
        if(q->front == q->rear){
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return val;
    }
}

int getFront(queue * q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -99999;
    } else {
        return q->arr[q->front];
    }
}

int getRear(queue * q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -99999;
    } else {
        return q->arr[q->rear];
    }
}

void display(queue * q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    } else {
        for(int i = q->front; i <= q->rear; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    queue * q = NULL;
    int capacity ;
    int choice;
    int val;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);
    q = createQueue(capacity);
    do{
        printf("1. Enquque\n");
        printf("2. Dequeue\n");
        printf("3. Get Front\n");
        printf("4. Get Rear\n");
        printf("5. isEmpty\n");
        printf("6. isFull\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &val);
                enqueue(q, val);
                display(q);
                break;
            case 2:
                val = dequeue(q);
                if(val != -99999){
                    printf("Dequeued value: %d\n", val);
                }
                display(q);
                break;
            case 3:
                val = getFront(q);
                if(val != -99999){
                    printf("Front value: %d\n", val);
                }
                break;
            case 4:
                val = getRear(q);
                if(val != -99999){
                    printf("Rear value: %d\n", val);
                }
                break;
            case 5:
                if(isEmpty(q)){
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 6:
                if(isFull(q)){
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 7:
                break;
        }
    }while(choice >= 1 && choice <= 6);
    return 0;
}