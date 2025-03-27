#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int * arr;
    int size;
    int capacity;
    int front;
} queue;

queue * createQueue(int size){
    queue * q  = (queue *)malloc(sizeof(queue));
    q->size = size;
    q->capacity = 0;
    q->front = -1;
    q->arr = (int *)malloc(sizeof(int)* size);
    return q;
}

int isFull(queue * q){
    return q->capacity == q->size;
}

void enqueue(queue * q,int val){
    if(isFull(q)){
        printf("Queue is full\n");
    } else {
        if(q->front == -1){
            q->front = 0;
            q->arr[q->front] = val;
            q->capacity++;
        } else {
            int rear = (q->front + q->capacity) % q->size;
            q->arr[rear] = val;
            q->capacity++;
        }       
    }
}

int isEmpty(queue * q){
    return q->capacity == 0;
}

int dequeue(queue * q){
    if(isEmpty(q)){
        return -99999;
    } else {
        int val = q->arr[q->front];
        q->front = (q->front + 1) % q->size;
        q->capacity--;
        return val;
    }
}

int getFirst(queue * q){
    if(isEmpty(q)){
        return -99999;
    } else {
        return q->arr[q->front];
    }
}


int getLast(queue * q){
    if(isEmpty(q)){
        return -99999;
    } else {
        int rear = (q->front + q->capacity - 1) % q->size;
        return q->arr[rear];
    }
}

void display(queue * q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    } else {
        for(int i=0;i<q->capacity;i++){
            int index = (q->front+i) % q->size;
            printf("%d ",q->arr[index]);
        }
        printf("\n");
    }
}


int main(){
    queue * q = NULL;
    int size;
    int val;
    int choice;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    q = createQueue(size);
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get First\n");
        printf("4. Get Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d",&val);
                enqueue(q,val);
                display(q);
                break;
            case 2:
                val = dequeue(q);
                if(val == -99999){
                    printf("Queue is empty\n");
                } else {
                    printf("Dequeued value: %d\n",val);
                }
                display(q);
                break;
            case 3:
                val = getFirst(q);
                if(val == -99999){
                    printf("Queue is empty\n");
                } else {
                    printf("First value: %d\n",val);
                }
                break;
            case 4:
                val = getLast(q);
                if(val == -99999){
                    printf("Queue is empty\n");
                } else {
                    printf("Last value: %d\n",val);
                }
                break;
            case 5:
                display(q);
                break;
            case 6:
                printf("Exiting\n");
                break;
        }
    }while(choice >=1 && choice <=5);
    return 0;
}



