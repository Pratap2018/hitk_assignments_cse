#include<stdio.h>
#include <stdlib.h>
#define MAX 10
int Top=-1;
int Stack[MAX];

void push(int data){
    if(Top>=MAX){
        printf("\n Stack Overflow");
        return;
    }
    Stack[++Top]=data;
}

void pop(){
    if(Top<=-1){
        printf("\n Stack Underflow");
        return;
    }
    printf("\n%d is deleted\n", Stack[Top--]);
}
void display(){
    int k=Top;
     if(Top<=-1){
        printf("\n Stack Underflow");
        return;
    }
    while(k>-1){
        printf("| %d |\n",Stack[k]);
        k--;
    }
}

int main() {
int ch,data;
while (1)
{
    printf("\n 1. PUSH");
    printf("\n 2. POP");
    printf("\n 3. DISPLAY");
    printf("\n 4. EXIT \n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:printf("\n Enter data to Push \n");
        scanf("%d",&data);
        push(data);
        break;
    case 2:pop();
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