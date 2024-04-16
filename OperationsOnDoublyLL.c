#include<stdio.h>
#include<stdlib.h>
typedef struct DLLnode{
    int data;
    struct DLLnode *prev,*next;
}node;
node* pointer(int key,node* start){
    node* temp = start;
    int count = 1;
    while((count < key - 1)&&(temp ->next!= NULL)){
        temp = temp -> next;
        count++;
    }
    return temp;
}
node* insert_at_begin(node* start,int val){
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp -> next = start;
    temp -> prev = NULL;
    start = temp;
    return start;
}
node* insert_at_pos(int val,int pos,node* start){
    if(pos == 1){
        start = insert_at_begin(start,val);
        return start;
    }
    node* point = pointer(pos,start);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp ->next = point ->next;
    point -> next -> prev = temp;
    point -> next = temp;
    temp-> prev = point;
    return start;
}
node* delete_at_begin(node* start,int* deleted_val){
    node* temp;
    temp = start;
    *deleted_val = temp->data;
    start = start->next;
    start->next -> prev = NULL;
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
    temp = point->next;
    *deleted = temp->data;
    point->next = temp->next;
    temp->next ->prev = point;
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
    start -> prev = NULL;
    start -> data = val;
    curr = start;
    printf("Data Stored Successfully .....\n");
    while(val != -1){
        printf("Enter data : ");
        scanf("%d",&val);
        if(val == -1){
            break;
        }
        else{
            temp = (node*)malloc(sizeof(node));
            temp -> data = val;
            curr -> next = temp;
            temp -> prev = curr;
            curr = temp;
            printf("Data Stored Successfully .....\n");
        }
    }
    curr -> next = NULL;
    return start;

}
void traverse(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void traverse_reverse(node* head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main(){
    node* start;
    start = create();
    printf("Linked list is : ");
    traverse(start);
    printf("Reverse Linked list is : ");
    traverse_reverse(start);
    int choice;
    printf("Press 1 for insertion nd press 2 for deletion & press 0 for termination : ");
    scanf("%d",&choice);
    if(choice == 0 ){
        return 0;
    }
    while(choice != 0){
        if(choice == 1){
            int val,key;
    printf("Enter the position for insertion : ");
    scanf("%d",&key);
    printf("Enter the value you want to insert : ");
    scanf("%d",&val);
    start = insert_at_pos(val,key,start);
    printf("Linked list is : ");
    traverse(start);
    printf("Reverse Linked list is : ");
    traverse_reverse(start);
    
        }
        
    if(choice == 2){
        int deleted = 0;
    start = delete_at_pos(&deleted,start);
    printf("Deleted value is : %d \n",deleted);
    printf("Linked list is : ");
    traverse(start);
    printf("Reverse Linked list is : ");
    traverse_reverse(start);
    }
    printf("Enter choice(Press 0 or 1 or 2 ) : ");
    scanf("%d",&choice);
    }
    
    return 0;
}