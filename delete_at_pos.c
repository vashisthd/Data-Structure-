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
    int count = 1;
    while((count < key - 1)&&(temp ->link!= NULL)){
        temp = temp -> link;
        count++;
    }
    return temp;
}
node* delete_at_begin(node* start,int* deleted_val){
    node* temp;
    temp = start;
    *deleted_val = temp->data;
    start = start->link;
    free(temp);
    return start;
}
node* delete_at_pos(int* deleted,node* start){
    int pos;
    printf("Enter the position to be deleted : ");
    scanf("%d",&pos);
    if(pos == 1){
        start = delete_at_begin(start,deleted);
        return start;
    }

    node* point = pointer(pos,start);
    node* temp;
    temp = point->link;
    *deleted = temp->data;
    point->link = temp->link;
    free(temp);
    return start;
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
    
    int deleted = 0;
    start = delete_at_pos(&deleted,start);
    printf("Deleted value is : %d \n",deleted);
    printf("After deletion Linked list is : ");
    traverse(start);

    return 0;
}