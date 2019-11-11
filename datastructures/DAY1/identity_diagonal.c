#include<stdio.h>
#include<stdlib.h>
int type_mat(int **matrixOne,int m){
int i,j,count=0;
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        if(matrixOne[i][j]!=0){
            if(i==j){
                if(matrixOne[i][j]==1)
                    count++;
            }else
            {
                return 3;
            }
                          
            
        }
    }
}
if(count==m){
    return 1;
}else
{
    return 2;
}

}
int main() {
    int i,j,**matrixOne,m,n;
    printf("\nEnter the dimension of the  matrix (nXn) :");
    scanf("%d",&m);
    n=m;
     matrixOne=(int **)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++){
        matrixOne[i]=(int*)malloc(sizeof(int)*n);
    }    
    printf("\n Enter the elements of the matrix :\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matrixOne[i][j]);
        }
    }
    switch (type_mat(matrixOne,m))
    {
        case 1:printf("\n It is a Identity matrix \n");
            break;
        case 2:printf("\n Diagonal Matrix \n");
           break;
        case 3:printf("\n Non Diagonal matrix \n");
            break;
     }    
    return 0;
}