#include<stdio.h>
#define max 100
int stack[max];
int top=-1;
void push(int val){
    if(top>=(max-1)){
        printf("Stack is already full ..\n");
    }
    else{
        top++;
        stack[top] = val;
    }
}
int pop(){
    if(top<0){
        return 0;
    }
    else{
        int value = stack[top];
        top--;
        return value;
    }
}
void display(){
    printf("Stack is : ");
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
        }
}
int main(){
    int choice=0,i=0,val,delete;
    while(i<max){
        printf("Enter your choice : \n1. Push an element in stack \n2. Pop an element from stack\n3. Display full stack \n4. Exit this program \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 :
            printf("Enter the value you want to push in stack(all numbers except zero) : ");
            scanf("%d",&val);
            push(val);
            i++;
            break;
        case 2 :
            delete = pop();
            if(delete==0){
                printf("Stack is already empty :( \n");
                break;
            }
            else{
            printf("Deleted value is : %d \n",delete);
            i++;
            break;
            }
        case 3 :
            display();
            i++;
            break;
        case 4 :
            printf("Thanks for Your time ... Exiting :) ");
            i++;
            break;
        default:
            printf("You entered a wrong choice .. Please enter it again :) ");
            break;
        }
        if(choice==4){
            break;
        }
            
        }
    }