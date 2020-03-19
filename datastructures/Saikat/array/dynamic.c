#include<stdio.h>
#include<stdlib.h>
int main(){
int n,*arr,i;
printf("Enter the size of array : ");
scanf("%d",&n);
arr=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        for(i=0;i<n;i++)
                printf("%d ",arr[i]);
return 0;
}

