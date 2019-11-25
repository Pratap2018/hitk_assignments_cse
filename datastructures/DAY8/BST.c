#include <stdio.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}NODE;

NODE * Create_node(){
    int data;
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data :");
    scanf("%d",&data);
    temp->data=data;
    temp->left=temp->right=NULL;
}

int main() {

    return 0;
}

