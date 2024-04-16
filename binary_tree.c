#include<stdio.h>
#include<stdlib.h>

typedef struct btree
{
    int data;
    struct btree *left,*right;
}btree;

btree* create(int parent_data,int side){

    btree *root1;
    int choice;
    if(side ==-1){
        root1=(btree*)malloc(sizeof(btree));
        scanf("%d",&root1->data);
    }
    else if(side == 1){
        printf("Enter left child of %d",parent_data);
        root1= (btree*)malloc(sizeof(btree));
        scanf("%d",&root1->data);
    }
    else if(side ==2){
        printf("Enter right child of %d",parent_data);
        root1 = (btree*)malloc(sizeof(btree));
        scanf("%d ",&root1->data);
    }

    printf("Do you want left child?(0/1)");
    scanf("%d",&choice);
    if(choice == 0){
        root1->left = NULL;
    }
        else{
        root1->left = create(root1->data,1);
    }

    printf("Do you want right child?(0/1)");
    scanf("%d",&choice);
    if(choice == 0){
        root1->right = NULL;
    }
    else{
        root1->right = create(root1->data,2);
    }
    
    return root1;
}

void inorder(btree *root){

    if(root != NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }

    return ;
}

int main(){

    btree *root;
    root = create(-1,-1);

    inorder(root);
}