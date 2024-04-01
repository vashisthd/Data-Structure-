#include<stdio.h>
#include<stdlib.h>
typedef struct DLLnode{
    int data;
    struct DLLnode *prev,*next;
}node;
node* pointer(int key,node* start){
    node* temp = start;
    int count = 1;
    while((count < key - 1) &&(temp -> next != NULL)){
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
node* insert_before(int val,node* start){
    int pos;
    printf("Enter position before u want to insert : ");
    scanf("%d",&pos);
    if(pos==1){
        start = insert_at_begin(start,val);
        return start;
    }
    node* point = pointer(pos,start);
    node* temp;
    node* next_point = point -> next;
    temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp ->next = next_point;
    point -> next = temp;
    next_point -> prev = temp;
    temp ->prev = point;

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
    int val;
    printf("Enter value You want to be inserted : ");
    scanf("%d",&val);
    start = insert_before(val,start);
    printf("New Linked list is : ");
    traverse(start);
    return 0;
}