#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * prev,*next;
}NODE;
NODE *Front,*Rear;
 

NODE * create_node(int);
void insert_rear(int);
void delete_front();
void insert_front(int);
void delete_rear();
void display();

int main()
{
    int ch,data;
    while (1){
        printf("\n Queue\n");
        printf("1. INSERT FROM FRONT\n");
        printf("2. INSERT FROM REAR \n");
        printf("3. DELETE FROM FRONT \n");
        printf("4. DELETE FROM REAR\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("\n Choose : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:printf("\n Enter the data to be inserted :");
                scanf("%d",&data);
                insert_rear(data);
                break;
        case 2: printf("\n Enter the data to be inserted :");
                scanf("%d",&data);
                insert_front(data);
                break;   
        case 3: delete_front();
                break;
        case 4:delete_rear();
            break;
        case 5: display();
            break;
        case 6:exit(0); 
        default:printf("\n Wrong input try again");
            break;
        }
    }
    

    return 0;
}



NODE* create_node(int data ){
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    node->data=data;
    return node;
}
void insert_front(int data){
    if(Rear==NULL){ 
        Rear=create_node(data);
        Rear->next=Rear->prev=NULL;
        Front=Rear;
        return;
    }
    NODE *temp=create_node(data);
    Rear->next=temp;
    temp->prev=Rear;
    Rear=Rear->next;
    Rear->next=NULL;


}

void insert_rear(int data){
      if(Rear==NULL){ 
        Rear=create_node(data);
        Rear->next=Rear->prev=NULL;
        Front=Rear;
        return;
    }
    NODE *temp=create_node(data);
    temp->next=Front;
    Front->prev=temp;
    Front=temp;
    Front->prev=NULL;

}
void delete_rear(){
    if(Rear==NULL){
        printf("\n Deletion is not possible \n");
    }else if (Rear->prev!=NULL){
        NODE* temp=Rear;
        printf("\n %d is deleted.. \n",Rear->data);
        Rear=Rear->prev;
        Rear->next=NULL;
        
    }else{
         printf("\n %d is deleted. \n",Rear->data);
         Rear=NULL;
         Front=NULL;
    }
}
void delete_front(){
    if(Front==NULL){
        printf("\n Deletion is not possible \n");
    }else if (Front->next!=NULL){
        NODE *temp=Front;
        printf("\n %d is deleted.. \n",Front->data);
        temp=temp->next;
        temp->prev=NULL;
        Front=temp;
        
        }else{
         printf("\n %d is deleted. \n",Front->data);
         Rear=NULL;
         Front=NULL;
    }
}

void display(){
    if(Front==NULL){
        printf("\nNothing  to display \n");
        return;
    }
    NODE * temp=Front;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->next;
    }

}

