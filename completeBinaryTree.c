#include<stdio.h>
#include<stdlib.h>

int main(){
    int size,choice,val;
    printf("Enter the size of the complete binary tree: ");
    scanf("%d",&size);
    int *arr = (int*)malloc((size+1)*sizeof(int));
    arr[0] = 0;
    for(int i=1;i<=size;i++){
        printf("Enter the value\n");
        scanf("%d",&arr[i]);
    }
    do{
        printf("1 Left Child:\n");
        printf("2 Right Child:\n");
        printf("3 Left & right Child:\n");
        printf("4 Parent:\n");
        printf("5 Exit:\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the Parent Index\n");
                scanf("%d",&val);
                printf("Left child index : %d\n",val*2);
                printf("Left child value : %d\n",arr[val*2]);
                break;
            case 2:
            printf("Enter the Parent Index\n");
            scanf("%d",&val);
            printf("Right child index : %d\n",(val*2)+1);
            printf("Right child value : %d\n",arr[(val*2)+1]);
            break;
        case 3:
            printf("Enter the Parent Index\n");
            scanf("%d",&val);
            printf("Left child index : %d\n",val*2);
            printf("Left child value : %d\n",arr[val*2]);
            printf("Right child index : %d\n",(val*2)+1);
            printf("Right child value : %d\n",arr[(val*2)+1]);
            break;
        case 4:
           printf("Enter the Child Index\n");
           scanf("%d",&val);
           printf("Parent index : %d\n",val/2);
           printf("Parent value : %d\n",arr[val/2]);
           break;
        case 5:
            printf("Exiting...\n");
            break; 
            
        }
    } while(choice >=1 && choice <= 4);
    return 0;
}