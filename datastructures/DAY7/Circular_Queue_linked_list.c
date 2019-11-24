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
       Rear->link=Rear;
       Front=Rear;
       return;
   }
   
       NODE *temp=Create_node();
       temp->data=data;
       temp->link=Front;
       Rear->link=temp;
       Rear=temp;
         
}

void delete(){
    if(Front==NULL){
        printf("\n Queue is empty");
    }else if(Front->link!=Front){
        NODE* temp=Front;
        printf(" \n %d is deleted ",temp->data);
        Front=Front->link;
        Rear->link=Front;
        free(temp);
    }else if(Front->link==Front){
         printf(" \n %d is deleted ....",Front->data);
        Front=NULL;
        Rear=NULL;
    }
    
    
 
}

void display(){
if(Front==NULL){
    printf("\n EMPTY \n");
    return;
}
NODE *temp=Front;
while (temp!=Rear)
{
    printf(" %d ",temp->data);
    temp=temp->link;
}
printf(" %d ", temp->data);

}

