#include<stdio.h>
#include<stdlib.h>
int *visited,time=1;

void traverse(int **graph,int n,int sv,int *Q,int front,int rear){
   
 printf("%d ",sv);
       
for (int i = 0; i < n; i++)
    if (graph[sv][i]==1&&visited[i]==0)
        Q[++rear]=i;
    if(front<rear){
        visited[Q[front]]=1;    
        traverse(graph,n,Q[front++],Q,front,rear);    
       }
   
}
int main(){
int n,e,front=0,rear=-1;
int sv;
printf("\n Enter the number of vertices and edges respectively ");
scanf("%d%d",&n,&e);
int **graph;
int *Q;
Q=(int*)malloc(sizeof(int)*n);

graph=(int **)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++){
		graph[i]=(int *)malloc(sizeof(int)*n);
		for(int j=0;j<n;j++)
			graph[i][j]=0;
    	}
for (int i = 0; i < e; i++){
	int f,s;
	printf("\n Enter the first and second edge respectvely :");
	scanf("%d%d",&f,&s);
	graph[f][s]=1;
    //graph[s][f]=1;
}

printf("\n Enter the starting vertex :");
scanf("%d",&sv);
	visited=(int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		visited[i]=0;
	}
     

	traverse(graph,n,sv,Q,front,rear);

   

    printf("\n ");
   /*for (int i = 0; i < n; i++)
    {
        if(visited[i]){
            printf("\t%d=>",i);
        }else
        {
            printf("\n All nodes are not reachable");
        }
        
    }*/
   

}
