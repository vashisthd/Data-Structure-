#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct DLLnode{
    int data;
    struct DLLnode *prev,*next;
}node;
node* start = NULL;
node* top = NULL;
bool isEmpty(){
	if (start == NULL)
		return true;
	return false;
}
void push(int val){
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node ->data = val;
    if (isEmpty()) {
        new_node ->prev = NULL;
        new_node ->next = NULL;
        start = new_node ;
        top = new_node ;
    }
    else {
        top->next = new_node ;
        new_node ->next = NULL;
        new_node ->prev = top;
        top = new_node;
    }
}
int pop()
{
    node* temp;
    temp = top;
    int val;
    if (isEmpty())
        printf("Stack is empty");
    else if (top == start) {
        val = top -> data;
        top = NULL;
        start = NULL;
        free(temp);
        return val;
    }
    else {
        val = top -> data;
        top->prev->next = NULL;
        top = temp->prev;
        free(temp);
        return val;
    }
    exit(1);
}
void traverse(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int val,choice=0,deleted;
    do{
        printf("1. Push()\n2. Pop()\n3. Traverse Linked List\n4. Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter Data you want to be stored : ");
                scanf("%d",&val);
                push(val);
                break;
            case 2: 
                deleted = pop();
                printf("Deleted value is : %d \n",deleted);
                break;
            case 3: 
                 printf("Linked list is : ");
                traverse(start);
                break;
            case 4: break;
        }
    }while(choice!=4);
}