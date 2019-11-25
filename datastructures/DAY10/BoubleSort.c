#include <stdio.h>
#include <stdlib.h>
void bouble_sort(int arr[],int n){
for(int i=0;i<n-1;i++){
    for (int j = 0; j < n-i-1; j++)
    {
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    
}
}
void print_arr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
}



int main(){
int n,*arr;
printf("\n Enter the size of the array :");
scanf("%d",&n);
arr=(int *)malloc(sizeof(int)*n);
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
bouble_sort(arr,n);
print_arr(arr,n);
}