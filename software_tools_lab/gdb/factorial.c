#include<stdio.h>
int main(){
	int i,num,j;
	printf("Enter the number : ");
	scanf("%d",&num);
	for(i=1;i<num;i++){
		j*=i;
	}
	printf("The factorial of %d os %d \n",num,j);
}
