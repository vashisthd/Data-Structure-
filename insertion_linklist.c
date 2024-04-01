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
void insert_after_val(int val,int key,node* start){
    node* point = pointer(key,start);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp ->link = point ->link;
    point -> link = temp;

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
    int val,key;
    printf("Enter the key value after which you want to insert : ");
    scanf("%d",&key);
    printf("Enter the value you want to insert : ");
    scanf("%d",&val);
    insert_after_val(val,key,start);
    printf("After insertion Linked list is : ");
    traverse(start);
    }
    return 0;
}