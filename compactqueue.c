#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int Queue [MAX];
int front = -1,rear = -1;
void compact ()
{
    int i;
    if(front > (rear - front )){
    for (i = 0; i < rear - front; i++){
        Queue[i] = Queue[front + 1 + i];
    }
    rear = rear - front - 1;
    front = -1;
    }
    printf("front is : %d \n",front);
    printf("rear is : %d \n",rear);
}
void insert (int val)
{
    if (rear >= MAX -1)
    {
            printf("QUEUE IS ALREAY FULL\n");
            return;
        
    }  
    else{
        Queue[++rear] = val;}
}
int Delete ()
{
    if(front >= rear)
    {
        printf("QUEUE IS ALREADY EMPTY\n");
        return -101;
    }
    else 
        return Queue[++front];
}
bool Isfull()
{
    if (rear >= MAX -1)
    return true;
    else
    return false;
}
bool Isempty()
{
    if (rear <= front)
    return true;
    else
    return false;
}
void display()
{   
    printf("Queue : ");
    if(front >= rear) 
        printf("Empty");
    else
        for (int i=front+1;i<=rear;i++)
            printf("%d ",Queue[i]);
}
int main()
{
    int op,val;
    do 
    {
        printf("----------------Queue Menu----------------\n1.Insert\n2.Delete\n3.ISFULL?\n4.ISEMPTY?\n5.Compact Queue\n6.Exit\n------------------------------------------\nEnter Your Choice: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter Value to be Inserted: ");scanf("%d",&val); printf("\n");insert(val);display(); printf("\n");break;
            case 2:
                if(Delete()==(-101)){
                    printf("No element is deleted\n");
                }
                else{
                    printf("Deleted value is : %d\n",Delete());
                }
                display(); printf("\n");break;
            case 3:
                if(Isfull()==true){
                    printf("Queue is Full\n");
                }
                else{
                    printf("Queue is not full\n");
                }
                break;
            case 4:printf("%d\n",Isempty());break;
            case 5: 
                compact();
                break;
            case 6:break;
            default:printf("Invalid Choice\n");
        }
    }
    while(op != 6);
    return 0;
} 