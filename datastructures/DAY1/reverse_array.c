#include <stdio.h>
#include<stdlib.h>
int* input_arr(int *arr,int size){
    int i;
    arr=(int *)malloc(sizeof(int)*size);
    printf("\n Enter the elements of the array : \n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    return arr;
}
void display(int * arr,int size){
    printf("\n The array => \n");
    for(int i=0;i<size;i++){
        printf("|%d", arr[i]);
    }
    printf("|\n");
}
int * reverse_arr(int *arr,int size){
    int i=0;
    while (i<size-i-1)
    {
        arr[i]=arr[i]+arr[size-i-1];
        arr[size-i-1]=arr[i]-arr[size-i-1];
        arr[i]=arr[i]-arr[size-i-1];
        i++;
    }
    return arr;
}
int main()
{   
int *arr,size,i;
printf("\n Enter the size of the array : ");
scanf("%d",&size);
arr=input_arr(arr,size);
printf("\n After reverse :");
arr=reverse_arr(arr,size);
display(arr,size);
    
    return 0;
}
