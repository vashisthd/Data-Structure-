#include <stdio.h>

#define max 100
void input(int poly[][2],int n){
    printf("Input Values : ");
    for(int i=0;i<n;i++){
        printf("Enter exponent");
        scanf("%d",&poly[i][1]);
        printf("Enter coefficient");
        scanf("%d",&poly[i][0]);
    }
}

void addPolynomials(int poly1[][2], int terms1, int poly2[][2], int terms2, int result[][2], int *resultTerms) {
    int i, j, k;

    i = j = k = 0;

    while (i < terms1 && j < terms2) {
        if (poly1[i][1] == poly2[j][1]) {
            result[k][0] = poly1[i][0] + poly2[j][0];
            result[k][1] = poly1[i][1];
            i++;
            j++;
        } else if (poly1[i][1] > poly2[j][1]) {
            result[k][0] = poly1[i][0];
            result[k][1] = poly1[i][1];
            i++;
        } else {
            result[k][0] = poly2[j][0];
            result[k][1] = poly2[j][1];
            j++;
        }
        k++;
    }

    while (i < terms1) {
        result[k][0] = poly1[i][0];
        result[k][1] = poly1[i][1];
        i++;
        k++;
    }

    while (j < terms2) {
        result[k][0] = poly2[j][0];
        result[k][1] = poly2[j][1];
        j++;
        k++;
    }

    *resultTerms = k;
}

void displayPolynomial(int poly[][2], int terms) {
    int i;

    for (i = 0; i < terms; i++) {
        printf("%dx^%d", poly[i][0], poly[i][1]);

        if (i < terms - 1) {
            printf(" + ");
        }
    }

    printf("\n");
}

int main() {
    int poly1[max][2];
    int poly2[max][2] ;
    int terms1 ,terms2;

    printf("Enter no. of terms for polynomial 1 : ");
    scanf("%d",&terms1);
    printf("Enter no. of terms for polynomial 2 : ");
    scanf("%d",&terms2);
    input(poly1,terms1);
    input(poly2,terms2);
    int result[max * 2][2];
    int resultTerms;

    printf("Polynomial 1: ");
    displayPolynomial(poly1, terms1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2, terms2);

    addPolynomials(poly1, terms1, poly2, terms2, result, &resultTerms);

    printf("Sum of Polynomials: ");
    displayPolynomial(result, resultTerms);
    printf("%d",resultTerms);
    return 0;
}
