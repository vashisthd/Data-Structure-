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
    printf("\n");
}
node* pointer(int key,node* start){
    node* temp = start;
    while(temp ->data!= key){
        temp = temp -> link;
    }
    return temp;
}
int delete_after_val(int key,node* start){
    node* point = pointer(key,start);
    node* temp;
    temp = point->link;
    int val = temp->data;
    point->link = temp->link;
    free(temp);
    return val;
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
    printf("Data Stored Successfully.....\n");
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
    if(start->link == NULL){
        return 0;
    }
    else{
    int key;
    printf("Enter the key value after which you want to delete the value : ");
    scanf("%d",&key);
    int deleted = delete_after_val(key,start);
    printf("Deleted value is : %d \n",deleted);
    printf("After deletion Linked list is : ");
    traverse(start);
    }
    return 0;
}