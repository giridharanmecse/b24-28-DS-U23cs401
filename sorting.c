#include<stdio.h>
#include<stdlib.h>


int * createArray(int size){
    return (int *)malloc(size * sizeof(int));
}

/*
scanf("%d",&a)
scanf("%f",&b);


arr+i = &arr[i];

*(arr+i) = arr[i]; // Value from that address

100x+(0*2)	100x+0	100x
100x+(1*2)	100x+2	102x
100x+(2*2)	100x+4	104x
100x+(3*2)	100x+6	106x
100x+(4*2)	100x+8	108x
100x+(5*2)	100x+10	110x
*/

void getValues(int * arr,int size){
    for(int i=0;i<size;i++){
        scanf("%d",arr+i);
    }
}

void displayArray(int * arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void swap(int *arr,int i,int j){
    int temp = *(arr+i); // temp = arr[i]
    *(arr+i) = *(arr+j); // arr[i] = arr[j]
    *(arr+j) = temp; // arr[j] = temp
}

void bubbleSort(int * arr,int size){
    printf("Bubble Sort\n");
    printf("Array before sorting\n");
    displayArray(arr,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j] > arr[j+1]){                
                printf("Swapping %d and %d\n",arr[j],arr[j+1]);
                swap(arr,j,j+1);
                printf("Array after swapping\n");
                displayArray(arr,size);
            }
        }
    }
}

void selectionSort(int * arr,int size){
    printf("Selection Sort\n");
    printf("Array before sorting\n");
    displayArray(arr,size);
    for(int i=0;i<size;i++){
        //int val = *(arr+i);
        for(int j=i+1;j<size;j++){
            if(arr[j] < arr[i]){
                printf("Swapping %d and %d\n",arr[i],arr[j]);
                swap(arr,i,j);
                printf("Array after swapping\n");
                displayArray(arr,size);
            }
        }
    }
}


void insertionsort(int * arr,int size){
    printf("Insertion Sort\n");
    printf("Array before sorting\n");
    displayArray(arr,size);
    for(int i=1;i<size;i++){
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            printf("Copying %d to %d\n",arr[j],arr[j+1]);
            arr[j+1] = arr[j];
            j--; 
            printf("Array after copying\n");
            displayArray(arr,size);
        }
        printf("Inserting %d at %d\n",temp,j+1);
        arr[j+1] = temp;   
        printf("Array after inserting\n");
        displayArray(arr,size);
    }
}


int main(){
    int size;
    int choice;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    int * arr = createArray(size);
    printf("Enter the values of the array\n");
    getValues(arr,size);
    printf("The values of the array are\n");
    displayArray(arr,size);
    do{
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                bubbleSort(arr,size);
                printf("The values of the array after sorting are\n");
                displayArray(arr,size);
                break;
            case 2:
                selectionSort(arr,size);
                printf("The values of the array after sorting are\n");
                displayArray(arr,size);
                break;
            case 3:
                insertionsort(arr,size);
                printf("The values of the array after sorting are\n");
                displayArray(arr,size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }   
    } while(choice >=1 && choice <= 3);
    free(arr);
    return 0;
}