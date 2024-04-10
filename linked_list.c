#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node;
void traverse(node* head){
    if(head == NULL){
        printf("Empty");
        exit(1);
    }
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
node* create(){
    int choice;
    node *start,*temp,*curr;
    printf("Enter your choice : \nPress 1 for create node & Press 0 for exit \n");
    scanf("%d",&choice);
    if(choice == 0){
        start = NULL;
        return start;
    }
    int val;
    printf("Enter data : ");
    scanf("%d",&val);
    start = (node*)malloc(sizeof(node));
    start -> data = val;
    curr = start;
    printf("Data Stored Successfully.....\n");
    while(choice != 0){
        printf("Enter choice : ");
        scanf("%d",&choice);
        if(choice == 0){
            break;
        }
        else{
            printf("Enter data : ");
            scanf("%d",&val);
            temp = (node*)malloc(sizeof(node));
            temp -> data = val;
            curr -> link = temp;
            curr = temp;
            printf("Data Stored Successfully .....\n");
        }
    }
    curr -> link = NULL;
    return start;
}
int main(){
    node* temp;
    temp = create();
    printf("Linked list is : ");
    traverse(temp);
    printf("Linked list is : ");
    traverse(temp);
    return 0;
}