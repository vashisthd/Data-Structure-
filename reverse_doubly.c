#include<stdio.h>
#include<stdlib.h>
typedef struct DLLnode{
    int data;
    struct DLLnode *prev,*next;
}node;
node* reverse(node* start){
    node *back,*curr;
    back = start;
    curr = start ->next;
    back->next = NULL;
    
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
    
    return 0;
}