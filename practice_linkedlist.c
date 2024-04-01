#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
void reverse(node* start)
{
    node* prev = NULL;
    node* current = start;
    node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    start = prev;
}
void traverse(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
node* pointer(int key,node* start){
    node* temp = start;
    while(temp ->data!= key){
        temp = temp -> next;
    }
    return temp;
}
void insert_after_val(int val,int key,node* start){
    node* point = pointer(key,start);
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp ->next = point ->next;
    point -> next = temp;

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
            curr -> next = temp;
            curr = temp;
            printf("Data Stored Successfully .....\n");
        }
    }
    curr -> next = NULL;
    return start;
}
int count(node* start){
    node* temp = start;
    int count = 0;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    return count + 1;
}
int main(){
    node* start;
    start = create();
    printf("Linked list is : ");
    traverse(start);
    if(start->next == NULL){
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
    int terms = count(start);
    printf("Total no. of terms in Linked list is : %d\n",terms);
    reverse(start);
    printf("Reversed Linkd list is : ");
    traverse(start);
    return 0;
}

