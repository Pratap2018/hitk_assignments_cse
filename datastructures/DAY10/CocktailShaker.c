
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void Cock_tail(int arr[],int n){
    int swapped=1;
    int start=0,end=n-1;
    while (swapped)
    {
        swapped=0;
        for(int i=start;i<end;i++){
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
                swapped=1;
            }            
        }
        if(!swapped)
            break;
        swapped=0;
        --end;
        for(int i=end-1;i>=start;i--){
             if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
                swapped=1;
            }   
        }
        ++start;
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
Cock_tail(arr,n);
print_arr(arr,n);
}