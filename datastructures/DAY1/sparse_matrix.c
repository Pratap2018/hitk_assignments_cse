#include<stdio.h>
#include<stdlib.h>
int nz;
int ** input_mat(int **matrixOne,int m,int n){
    int i,j;
     matrixOne=(int **)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++){
        matrixOne[i]=(int*)malloc(sizeof(int)*n);
    }    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matrixOne[i][j]);
        }
    }
return matrixOne;
}

int ** cvt_row_col_rp(int ** mat,int r,int c){
    int **sparse,i,j,k=0;
    sparse=(int**)malloc(sizeof(int *)*nz);
    for(i=0;i<nz;i++){
        sparse[i]=(int*)malloc(sizeof(int)*3);
    }
    for(i=0;i<r;i++){
        for (j=0; j < c; j++){
           if(mat[i][j]!=0){
            sparse[k][0]=i;
            sparse[k][1]=j;
            sparse[k][2]=mat[i][j];
            k++;
           }
        }
    
    }
    return sparse;
}


int chk_sparse(int **mat,int r, int c){
    int i,j,z=0;
    
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            if(mat[i][j]==0)
                z++;
            else
                nz++;
            
                
        }
        
    }
    if(z>nz){
        return 1;
    }else
    {
        return 0;
    }
    
}
void display_r_c(int **sparse){
    printf("\n  ROW\tCOLUMN\tVALUE\n");
    for(int i=0;i<nz;i++){
        for(int j=0;j<3;j++){
            printf("  %d\t",sparse[i][j]);
        }
        printf("\n");
    }
}
int ** transpose_r_c(int **sparse){
    for(int i=0;i<nz;i++){
        sparse[i][0]=sparse[i][0]+sparse[i][1];
        sparse[i][1]=sparse[i][0]-sparse[i][1];
        sparse[i][0]=sparse[i][0]-sparse[i][1];
    }
    return sparse;
}
int main() {
    int **mat,r,c,i,j,**sparse,**transpose_sp;
    printf("\nEnter the dimension of the mateix row X column :");
    scanf("%d%d",&r,&c);
    printf("\nEnter the Elements of the matrix \n");
    mat=input_mat(mat,r,c);
    if(chk_sparse(mat,r,c)){
        printf("\n Sparse Matrix ");
    }else{
        printf("\n Not Sparse Matrix ");
    }
    sparse=cvt_row_col_rp(mat,r,c);
    display_r_c(sparse);
    printf("\n Transpose \n");
    transpose_sp=transpose_r_c(sparse);

    display_r_c(transpose_sp);
    return 0;
}