#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    /* data */
    int data;
    struct node *next;
}Node;
Node *head;

void create_list();
void insert_at_any_pos(int);
void delete_from_any_pos(int);
void count_nodes();
void reverse_list();
void traverse();
void search(int data);
int search_d(int data);

int main(int argc, char const *argv[])
{
    /* code */
    int ch,pos;
    while (1)
    {
        /* code */
        printf("\n<=Linked list=>\n");
        printf("Choose :\n");
        printf("1. Create list \n");
        printf("2. Insert at any Position (Index Starts from 1)\n");
        printf("3. Delete from any Postion (delete from begin pos=1 || delete from the end pos=count)\n");
        printf("4. Delete with respect to value\n");
        printf("5. Count the nodes \n");
        printf("6. Reverse the list \n");
        printf("7. Search Element \n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("\n Enter your choice :");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:create_list();

            break;
        case 2: printf("\nEnter the position Where you want to insert ");
            scanf("%d",&pos);
            insert_at_any_pos(pos);
            break;
        case 3: printf("\nEnter the position from Where you want to delete ");
            scanf("%d",&pos);
            delete_from_any_pos(pos);
            break; 
        case 4:printf("\n Enter a data to Delete ");
                scanf("%d",&pos);
                if(search_d(pos)==-1){
                    printf("\nThe data is not present.\n");
                }
                else
                {
                    delete_from_any_pos(search_d(pos));
                }
            break;  
        case 5: count_nodes();
            break;
        case 6:reverse_list();
            break;
        case 7: printf("\n Enter a data to search ");
                scanf("%d",&pos);
            search(pos);
            break;
        case 8: traverse();
            break;
        case 9:
            perror("Exit Status");
            exit(0);
        default:
            printf("Wrong Input Try again \n");
            break;
        }
    }
    
    



    return 0;
}


void create_list(){
    Node *temp,*temp2;
    temp=(Node *)malloc(sizeof(Node));
    printf("\nEnter the data => ");
    scanf("%d",&temp->data);
    if (head==NULL){

        head=temp;
        perror("\nData Inserted ");
    }
    else
    {   temp2=head;
        while (temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        
        temp2->next=temp;
    }
    
}
void traverse(){
    Node *temp;
    temp=head;
    printf("\n The List => \n");
    while(temp!=NULL){
        printf(" |%d|->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void insert_at_any_pos(int pos){
    Node *temp;
    int count=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(pos>0&&pos<=count+1){
        if(pos==count+1){
            create_list();
        }
        else if (pos==1)
            {
                Node *temp1;
                temp1=(Node *)malloc(sizeof(Node));
                printf("\nEnter the data :");
                scanf("%d",&temp1->data);
                temp1->next=head;
                head=temp1;
            }else if (pos>1&&pos<=count)
            {   Node *prev;
                temp=head;
                while (--pos!=1)
                {   
                    
                    temp=temp->next;
                }
                prev=temp;
                temp=temp->next;
                printf("\n %d",temp->data);
                Node *temp1;
                temp1=(Node *)malloc(sizeof(Node));
                printf("\nEnter the data :");
                scanf("%d",&temp1->data);
                temp1->next=temp;
                prev->next=temp1;
            }
            
        
        
    }else
    {
        printf("\n***********\t Invalid positon **********");
    }
    
}

void count_nodes(){
    Node *temp;
    int count=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    printf("\nThe number of nodes are %d",count);
}

void delete_from_any_pos(int pos){
    Node *temp,*curr;
    int count=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
 
    if(pos>0&&pos<=count){
        if(pos==count){
            temp=head;
            while(temp->next!=NULL){
                curr=temp;
                temp=temp->next;
            }
            free(curr->next);
            curr->next=NULL;    
            printf("\n Data deleted ");        
        }
        else if (pos==1)
            {
                Node *temp1;
                temp1=head;
                head=head->next;
                free(temp1);
                printf("\nData deleted ");
            }else if (pos>1&&pos<count)
            {   Node *prev,*curr;
                temp=head;
                while (--pos!=1)
                {   
                    
                    temp=temp->next;
                }
                prev=temp;
                curr=temp->next;
                temp=curr->next;
                prev->next=temp;
                free(curr);
                printf("\nData deleted ");       
            }                 
        
        }else
    {
        printf("\n***********\t Invalid positon **********");
    }
}


void reverse_list(){
    Node *curr,*prev=NULL,*next=NULL;
    curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    } 
    head=prev;
}
void search(int data){
    int count=0;
    Node *temp;
    temp=head;
    while(temp!=NULL){
        ++count;
        if(temp->data==data){
                        printf("\nThe data  %d has found at %d th node",data,count);
            return;
        }
        temp=temp->next;
    }
    printf("\n The data has not been found");

}
int search_d(int data){
    int count=0;
    Node *temp;
    temp=head;
    while(temp!=NULL){
        ++count;
        if(temp->data==data){
            return count;
        }
        temp=temp->next;
    }
    return -1;

}