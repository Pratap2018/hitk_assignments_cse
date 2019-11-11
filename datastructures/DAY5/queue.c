#include <stdio.h>
#include <stdlib.h>
#define  MAX 5
int front=-1,rear=-1;
int Q[MAX];
void enque(int data){
if(rear==MAX){
    printf("\n Queue is full :");
    return;
}else if (rear==-1&& front==-1)
{
    front=0;
}
Q[++rear]=data;

}
void deque(){
    int data;
    if(front==-1){
        printf("\n queue is empty");
    }
    data=Q[front];
    if(front==rear){
        front=rear=-1;
    }else
    {
        front++;
    }
    printf("\n%d deleted",data);
}
void display(){
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", Q[i]);
        printf("\n");
    }
}
int main(){

int ch,data;
while (1)
{
    printf("\n 1. INSERT");
    printf("\n 2. DELETE");
    printf("\n 3. DISPLAY");
    printf("\n 4. EXIT \n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:printf("\n Enter data to Push \n");
        scanf("%d",&data);
        enque(data);
        break;
    case 2:deque();
        break;
    case 3:display();
        break;
    case 4:exit(0);
        break;
    default:printf("\nWrong input try again :\n");
        break;
    }
}

    return 0;

}
