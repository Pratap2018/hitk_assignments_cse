#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node * link;
}NODE;
NODE* head;
NODE * Create_node(){
    NODE *node;
    node=(NODE*)malloc(sizeof(NODE));    
}
void insert(int);
void delete();
void display();
int main() {
int var;    
while (1){
    printf("\nChoose :\n");
    printf("1. INSERT \n");
    printf("2. DELETE \n");
    printf("3. DISPLAY\n");
    printf("4. EXIT\n");
    scanf("%d",&var);
    switch (var)
    {
    case 1:printf("\nEnter the data :");
        scanf("%d",&var);
        insert(var);
    break;
    case 2:delete();
    break;
    case 3:display();
    break;
    case 4:
    free(head);
    exit(0);
    break;
    default:printf("\nWrong choice! Try Again \n");
        
    }
}
    return 0;
}

void insert(int data){
if(head==NULL){
    head=Create_node();
    head->data=data;
    head->link=NULL;
    }else
    {
       NODE *temp=Create_node();
       temp->data=data;
       temp->link=head;
       head=temp;
    
        
    }
  
}
void delete(){
    if (head==NULL){
        printf("\n Deletion is not possible ");
        return;
    }else if(head->link==NULL){
        printf("\n%d is deleted.......",head->data);
        head=NULL;
        return;
    }   
    NODE * temp=head;
    printf("\n%d is deleted..",temp->data);
    head=head->link;
    temp->link=NULL;
    free(temp);

            
}
void display(){
   if (head==NULL){
        printf("\n Display is not possible ");
        return;
   }
    NODE * temp=head;
    while(temp!=NULL){
        printf("|%d|\n",temp->data);
        temp=temp->link;
    }
    free(temp);
}