#include<stdio.h>
#include<stdlib.h>
void traverse(int **graph,int n,int sv,int *visited){

	printf(" -> %d",sv);
	visited[sv]=1;
	for (int i = 0; i < n; i++){
		if(i==sv)continue;
		if(graph[sv][i]==1){
			if(visited[i])
				continue;
			traverse(graph,n,i,visited);		
		}
	}
}
int main(){
int n,e;
printf("\n Enter the number of vertices and edges respectively ");
scanf("%d%d",&n,&e);
int **graph;
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
}
int *visited;
int sv;
printf("\n Enter the starting vertex :");
scanf("%d",&sv);
	visited=(int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++){
		visited[i]=0;
	}

	traverse(graph,n,sv,visited);
    printf("\n");

}
