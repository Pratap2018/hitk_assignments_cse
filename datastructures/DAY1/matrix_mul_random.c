#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c=0;

int ** input_mat(int **matrixOne,int m,int n){
    int i,j;
     matrixOne=(int **)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++){
        matrixOne[i]=(int*)malloc(sizeof(int)*n);
    }    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
           matrixOne[i][j]=rand()%10;
        }
    }
return matrixOne;
}
void display(int **matrixOne,int m,int n){
    int i,j;
    printf("\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("  %d  ",matrixOne[i][j]);
        }
        printf("\n");
    }
}

int **mat_mul(int **matrixOne,int m,int n,int **matrixTwo,int p,int q){
    int **matrixThree;
    int i,j,k;
     matrixThree=(int **)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++){
        matrixThree[i]=(int*)malloc(sizeof(int)*q);
    }    
    for(i=0;i<m;i++){
        for ( j = 0; j < q; j++)
        {
        matrixThree[i][j]=0;
        for(k=0;k<n;k++){
            matrixThree[i][j]+=matrixOne[i][k]*matrixTwo[k][j];
            c++;
        }
        }
        
    }
return matrixThree;
}

int main()
{
    srand(time(0));
    int i,j,m,n,p,q;
    int **matrixOne,**matrixTwo,**matrixThree;
    printf("\nEnter the dimension of the 1 st matrix :");
    scanf("%d%d",&m,&n);
    printf("\nEnter the dismenssion of the second matrix :");
    scanf("%d%d",&p,&q);
    if(n!=p){
        printf("\nMultiplication is not possible ");
        exit(0);
    }
    printf("Enter the elements of the first matrix :");    
    matrixOne=input_mat(matrixOne,m,n);
    printf("Enter the elements of second matrix :");
    matrixTwo=input_mat(matrixTwo,p,q);
    printf("\nDisplaying the 1st matrix ");
    display(matrixOne,m,n);
    printf("\nDisplaying the second matrix ");
    display(matrixTwo,p,q);
    printf("\n Result : ");
    matrixThree=mat_mul(matrixOne,m,n,matrixTwo,p,q);
    display(matrixThree,m,q);
    if(m==q){
        printf("\nTHE INPUT SIZE %dX%d  \nTHE ITTRETUION TO OBTAIN OUTPUT %d :",n,n,c);
    }
    return 0;
}
