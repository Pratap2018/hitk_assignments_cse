#include <stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fp;
typedef struct node 
{
    /* data */
    int data;
    struct node *next;
}Node;
Node *head=NULL,*tail=NULL;
int is_in_list(int);
Node * Create_node(){
    Node * temp=(Node*)malloc(sizeof(Node));
    
    return temp;   
}
void store(){
    fp=fopen("data.txt","w");
    Node *temp;
    temp=head;
    //printf("\n The List => \n");
    while(temp!=NULL){
      //  printf(" |%d|->",temp->data);
      fprintf(fp," %d ",temp->data);
        temp=temp->next;
    }

}
void push(int);
int count_node(){

    Node *temp;
    int count=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
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

int main() {
    int data,num;
srand(time(NULL));

printf("\n Enter the value of n :");
scanf("%d",&data);

while(data>count_node()){
     num=(rand()%data )+1;
    if(head==NULL){
            printf(" %d ",num);
        push(num);
    }
    if(!is_in_list(num)) {
        push(num);
    }

}
traverse();
store();
}


int is_in_list(int data){
Node * temp= head;
while(temp!=NULL){
    if(temp->data==data){
        
        return 1;
    }
    temp=temp->next;
}
 return 0;
}


void push(int data){
    if(head==NULL){
        head=Create_node();
        head->data=data;
        head->next=NULL;
        tail=head;
    }else{
        tail->next=Create_node();
        tail=tail->next;
        tail->data=data;
        tail->next=NULL;
    }   

}