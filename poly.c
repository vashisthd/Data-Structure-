#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int exp, coeff;
    struct Node* link;
} Node;

void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->link != NULL)
            printf("+ ");
        temp = temp->link;
    }
    printf("\n");
}

Node* create() {
    int exp, coeff;
    Node* start = NULL;
    Node* curr = NULL;
    printf("Enter exp and coeff: ");
    scanf("%d%d", &exp, &coeff);

    while (exp != -1) {
        
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->exp = exp;
        temp->coeff = coeff;
        temp->link = NULL;

        if (start == NULL) {
            start = temp;
            curr = temp;
        } else {
            curr->link = temp;
            curr = temp;
        }
        printf("Enter exp and coeff: ");
        scanf("%d%d", &exp, &coeff);
    }
    return start;
}

Node* addpoly(Node* poly1, Node* poly2) {
    Node* temp1 = poly1;
    Node* temp2 = poly2;
    Node* poly3 = NULL;
    Node* curr = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->link = NULL;

        if (temp1->exp > temp2->exp) {
            temp->exp = temp1->exp;
            temp->coeff = temp1->coeff;
            temp1 = temp1->link;
        } else if (temp1->exp < temp2->exp) {
            temp->exp = temp2->exp;
            temp->coeff = temp2->coeff;
            temp2 = temp2->link;
        } else {
            temp->exp = temp1->exp;
            temp->coeff = temp1->coeff + temp2->coeff;
            temp1 = temp1->link;
            temp2 = temp2->link;
        }

        if (poly3 == NULL) {
            poly3 = temp;
            curr = temp;
        } else {
            curr->link = temp;
            curr = temp;
        }
    }

    while (temp1 != NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->exp = temp1->exp;
        temp->coeff = temp1->coeff;
        temp1 = temp1->link;

        if (poly3 == NULL) {
            poly3 = temp;
            curr = temp;
        } else {
            curr->link = temp;
            curr = temp;
        }
    }

    while (temp2 != NULL) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->exp = temp2->exp;
        temp->coeff = temp2->coeff;
        temp2 = temp2->link;

        if (poly3 == NULL) {
            poly3 = temp;
            curr = temp;
        } else {
            curr->link = temp;
            curr = temp;
        }
    }

    return poly3;
}

int main() {
    Node* poly1 = create();
    printf("Polynomial 1: ");
    traverse(poly1);

    Node* poly2 = create();
    printf("Polynomial 2: ");
    traverse(poly2);

    Node* poly3 = addpoly(poly1, poly2);
    printf("Sum of Polynomials: ");
    traverse(poly3);

    return 0;
}