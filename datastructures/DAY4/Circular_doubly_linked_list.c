#include <stdio.h>
#include <stdlib.h>

typedef struct  node{
    int data;
    struct node *prev,*next;
    
}NODE;
NODE *head,*tail; 
NODE* create_node();
void create_list();
void insert_at_any_pos(int);
void delete_at_any_pos(int);
void reverse();
int count_node();
void traverse();
void search_e(int);
int main(){
int ch,pos;
while (1){
        printf("\n<=Circular and Doubly Linked list=>\n");
        printf("Choose :\n");
        if(head==NULL){
        printf("1. Create list \n");
        }
        printf("2. Insert at any Position (Index Starts from 1)\n");
        printf("3. Delete from any Postion (delete from begin pos=1 || delete from the end pos=count)\n");
        printf("4. Count the nodes \n");
        printf("5. Reverse the list \n");
        printf("6. Search Element \n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("\n Enter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: create_list();
            break;
        case 2: printf("\nEnter the position to insert :");
            scanf("%d",&pos);
            insert_at_any_pos(pos);
            break;
        case 3:printf("\nEnter the position to delete :");
            scanf("%d",&pos);
            delete_at_any_pos(pos);
            break;
        case 4:printf("\nThe number of nodes in LIST %d  ",count_node());   
            break;
        case 5:reverse();
            break;
        case 6:printf("\n Enter key :");
                scanf("%d",&pos);
                search_e(pos);
                break;
        case 7:traverse();
            break;
        case 8: exit(0);
        
        default:printf("\nWrong Input try again..");
            break;
        }
    }
}



NODE* create_node(){
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    printf("\n Enter the data \n");
    scanf("%d",&node->data);
    return node;
}

void create_list(){
    if(head==NULL){
        head=create_node();
      
        head->prev=head;
       
        head->next=head;
          tail=head;
      
    }else{
        printf("\nInvalid");    }

}
void insert_at_any_pos(int pos){
    if (head==NULL){
        printf("\nInsertion is not possible \n");
        return;
    }
    int count=count_node();
    if(pos==1){
        NODE* node=create_node();
        node->next=head;
        head->prev=node;
        node->prev=tail;
        tail->next=node;
        head=node;
    }else if(pos==count+1){
        NODE* node=create_node();
        node->next=head;
        tail->next=node;
        node->prev=tail;
        head->prev=node;
        tail=node;
    }else if (1 < pos && pos < count + 1){
        NODE* node=head,*p;
        
        NODE *new_node=create_node();
        while(--pos){
            printf(" %d ",node->data);
            node=node->next;
           
        }
        p=node->prev;
        printf("%d",p->data);
        new_node->next=node;
        p->next=new_node;
        new_node->prev=p;
        node->prev=new_node;
    }else{
        printf("\nInvalid position");
    }
     
    

}
void reverse(){

}

void delete_at_any_pos(int pos){
if (head==NULL){
        printf("\nDeletion is not possible \n");
        return;
    }
    int count=count_node();
    if(pos==1){
        NODE *k=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(k);
        if(count==1)
           head=NULL;
    }else if(pos==count){
        NODE *k=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(k);
    }else if (1 < pos && pos < count + 1){
        NODE* node=head,*p;
        while(--pos){
            printf(" %d ",node->data);
            node=node->next;
           
        }
        p=node->prev;
        p->next=node->next;
        node=node->next;
        node->prev=p;
    }else{
        printf("\nInvalid position");
    
    }
}

int count_node(){
    if (head==NULL)
    {
        printf("\n Invalid");
    }
    
     int count =1;
     NODE * node;
     node=head;
     while(node!=tail){
         node=node->next;
         count++;
        }
return count;
}
void traverse(){
    NODE * node=head;
    if(head==NULL){
        printf("\n Invalid");
        return;
    }
    while(node!=tail){
        printf("|%d|<=>",node->data);
        node=node->next;
    }
    printf("|%d|<=>",node->data);
    printf("Head");
}

void search_e(int pos){
    NODE *t=head;
    if (head==NULL){
        printf("\nInvalid");
    }
    
    int i=0;
    while(t!=tail){
        ++i;
        if(pos==t->data)
        printf("\n %d is found at location %d\n",pos,i);
        t=t->next;
    }
    if(tail->data==pos){
            printf("\n %d is found at location %d\n",pos,count_node()); 
    }
}