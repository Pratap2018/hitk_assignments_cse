#include<stdio.h>
#include<stdlib.h>
int main(){
int n,m,**arr,i,j;
printf("Enter the Dimension[n*m] of array : ");
scanf("%d %d",&n,&m);
arr=(int**)malloc(sizeof(int*)*n);
        for(i=0;i<n;i++)
                arr[i]=(int*)malloc(sizeof(int)*m);
for(i=0;i<n;i++)
        for(j=0;j<m;j++)
                scanf("%d",&arr[i][j]);     
                
for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                printf("%d ",arr[i][j]);  
       }
       printf("\n");
       }
return 0;
}


