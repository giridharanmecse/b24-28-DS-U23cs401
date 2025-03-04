#include<stdio.h>
int main(){
    int a,b,c,d,e;
    int arr[5];
    printf("a = %p\n",&a);
    printf("b = %p\n",&b);
    printf("c = %p\n",&c);
    printf("d = %p\n",&d);
    printf("e = %p\n",&e);
    for(int i=0;i<5;i++){
        printf("arr[%d] = %p\n",i,&arr[i]);
    }
    return 0;
}