#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of variable
typedef struct node {
    int coeff;
    int pow;
    struct node* link;
}node;

// Function to create new node
node* create(){
    int choice;
    node *start,*temp,*curr;
    printf("Enter your choice : \nPress 1 for create node & Press 0 for exit \n");
    scanf("%d",&choice);
    if(choice == 0){
        start = NULL;
        return start;
    }
    int val,power;
    printf("Enter coefficient : ");
    scanf("%d",&val);
    printf("Enter exponent : ");
    scanf("%d",&power);
    start = (node*)malloc(sizeof(node));
    start -> coeff = val;
    start -> pow = power;
    curr = start;
    printf("Data Stored Successfully.....\n");
    while(choice != 0){
        printf("Enter choice : ");
        scanf("%d",&choice);
        if(choice == 0){
            break;
        }
        else{
            printf("Enter coeffecient : ");
            scanf("%d",&val);
            printf("Enter exponent : ");
            scanf("%d",&power);
            temp = (node*)malloc(sizeof(node));
            temp -> coeff = val;
            temp -> pow = power;
            curr -> link = temp;
            curr = temp;
            printf("Data Stored Successfully .....\n");
        }
    }
    curr -> link = NULL;
    return start;
}
void polyadd(node* poly1, node* poly2,node* poly) {
    while (poly1->link && poly2->link) {
       
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        }

        else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->link;
        }

        else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        poly->link = (node*)malloc(sizeof(node));
        poly = poly->link;
        poly->link = NULL;
    }
    while (poly1->link || poly2->link) {
        if (poly1->link) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        }
        if (poly2->link) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->link;
        }
        poly->link = (node*)malloc(sizeof(node));
        poly = poly->link;
        poly->link = NULL;
    }
}

void show(node* node) {
    while (node->link != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->link;
        if (node->coeff >= 0) {
            if (node->link != NULL)
                printf("+");
        }
    }
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    poly1 = create();


    poly2 = create();

    printf("1st Polynomial : ");
    show(poly1);

    printf("\n2nd Polinomial: ");
    show(poly2);

    poly = (node*)malloc(sizeof(node));

    polyadd(poly1, poly2, poly);

 
    printf("\nAdded polynomial: ");
    show(poly);

    return 0;
}
