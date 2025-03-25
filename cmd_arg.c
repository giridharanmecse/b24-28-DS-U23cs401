#include<stdio.h>
int main(int n, char * ch[]){
   // printf("welcome %s\n",ch);
    for(int i=0;i<n;i++){
        printf("%s\n", ch[i]);
    }
    /*int a = (int)ch[0];
    int b = (int)ch[1];
    int c = (int)ch[2];
    printf("%d %d %d\n", a, b, c);*/
    return 0;
}