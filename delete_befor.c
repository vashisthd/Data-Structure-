#include<stdio.h>
#include<stdlib.h>
typedef struct DLLnode{
    int data;
    struct DLLnode *prev,*next;
}node;
node* pointer(int key,node* start){
    node* temp = start;
    int count = 1;
    while((count < key - 2)&&(temp ->next != NULL)){
        temp = temp -> next;
        count++;
    }
    return temp;
}
node* delete_at_begin(node* start,int* deleted_val){
    node* temp;
    temp = start;
    *deleted_val = temp->data;
    start = start->next;
    free(temp);
    return start;
}
node* delete_before(int* deleted,node* start){
    int pos;
    printf("Enter position before you want to delete : ");
    scanf("%d",&pos);
    if(pos==1){
        start = delete_at_begin(start,deleted);
        return start;
    }
    node* point = pointer(pos,start);
    node* temp;
    temp = point->next;
    *deleted = temp->data;
    point->next = temp->next;
    temp -> prev = point;
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
int main(){
    node* start;
    start = create();
    printf("Linked list is : ");
    traverse(start);
    int deleted = 0;
    start = delete_before(&deleted,start);
    printf("Deleted value is : %d \n",deleted);
    printf("After deletion Linked list is : ");
    traverse(start);
    return 0;
}