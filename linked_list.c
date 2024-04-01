#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node ;
void traverse(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
node* create(){
    int val;
    node *start,*temp,*curr;
    printf("Enter data : ");
    scanf("%d",&val);
    if(val == -1){
        start = NULL;
        return start;
    }
    start = (node*)malloc(sizeof(node));
    start -> data = val;
    curr = start;
    printf("Data Stored .....\n");
    while(val != -1){
        printf("Enter data : ");
        scanf("%d",&val);
        if(val == -1){
            break;
        }
        else{
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
    node* start;
    start = create();
    printf("Linked list is : ");
    traverse(start);
    return 0;
}