#include<stdio.h>
#include<stdlib.h>

int * createArray(int size){
    int * arr = (int *)malloc(size*sizeof(int));
    return arr;
}

void getValue(int *arr,int size){
    printf("Enter the Array Values:\n");
    for(int i=0;i<size;i++){
        scanf("%d",arr+i);
    }
}

void printArray(int * arr,int size){
    printf("The Array is:\n");
    for(int i=0;i<size;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

int binarySearch(int *arr,int size,int key){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(*(arr+mid) == key){
            return mid;
        }
        else if(*(arr+mid) < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1; // Not found
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int * arr = createArray(size);
    getValue(arr,size);
    printArray(arr,size);
    int key;
    printf("Enter the key to search: ");
    scanf("%d",&key);
    int result = binarySearch(arr,size,key);
    if(result != -1){
        printf("Key found at index: %d\n",result);
    }
    else{
        printf("Key not found in the array.\n");
    }
    return 0;
}