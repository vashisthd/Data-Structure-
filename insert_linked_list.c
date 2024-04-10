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
    while((count < key - 1) &&(temp -> link != NULL)){
        temp = temp -> link;
        count++;
    }
    return temp;
}
node* insert_at_begin(node* start,int val){
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp -> link = start;
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
    temp ->link = point ->link;
    point -> link = temp;
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
    int val,key;
    printf("Enter the position for insertion : ");
    scanf("%d",&key);
    printf("Enter the value you want to insert : ");
    scanf("%d",&val);
    start = insert_at_pos(val,key,start);
    printf("After insertion Linked list is : ");
    traverse(start);
    return 0;
}