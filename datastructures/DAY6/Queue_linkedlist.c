#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * link;
}NODE;
NODE *Front,*Rear;
NODE * Create_node(){
    NODE *node;
    node=(NODE*)malloc(sizeof(NODE));    
}
void insert(int);
void delete();
void display();
int main()
{
    int ch,data;
    while (1){
        printf("\n Queue\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("\n Choose : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:printf("\n Enter the data to be inserted :");
                scanf("%d",&data);
                insert(data);
                break;
        case 2: delete();
            break;
        case 3: display();
            break;
        case 4:exit(0);
            break;
        
        default:printf("\n Wrong input try again");
            break;
        }
    }
    

   /* insert(1);
    insert(2);
    insert(3);
    insert(4);
    delete();
    display();*/
    return 0;
}


void insert(int data){
    if(Rear==NULL){
        Rear=Create_node();
        Rear->data=data;
        Rear->link=NULL;
        Front=Rear;
    }else{
        Rear->link=Create_node();
        Rear=Rear->link;
        Rear->link=NULL;
        Rear->data=data;
    }
}

void delete(){
    if (Front==NULL){
        printf("\n Queue is empty");
        return;
    }else if(Front->link!=NULL){
        NODE *temp=Front;
        printf("\n%d is deleted",temp->data);
        Front=Front->link;
        free(temp);
    }else{
        printf("\n %d is deleted.",Front->data);
        free(Front);
        Front=NULL;
        Rear=NULL;
    }  
}

void display(){
NODE * temp=Front;
    if (Front==NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }
    
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->link;
    }
    free(temp);
printf("\n");
}

