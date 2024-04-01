#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node* start = NULL;
node* top = NULL;
int curr = 0;
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
        new_node ->next = NULL;
        start = new_node ;
        top = new_node ;
        curr++;
    }
    else {
        top->next = new_node ;
        new_node ->next = NULL;
        top = new_node;
        curr++;
    }
}
node* pointer(int key,node* start){
    node* temp = start;
    int count = 1;
    while((count < key - 1)&&(temp -> next!= NULL)){
        temp = temp -> next;
        count++;
    }
    return temp;
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
        node* point = pointer(curr,start);
        node* temp;
        temp = point->next;
        point->next = temp->next;
        free(temp);
        curr--;
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