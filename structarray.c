#include<stdio.h>
#define max 100
typedef struct polynomial{
    int exp;
    int coeff;
} poly;
void input(poly poly[],int num){
	int i;
    for(i=0;i<num;i++){
        printf("Enter exponent & coefficient : ");
        scanf("%d%d",&(poly[i].exp),&(poly[i].coeff));
    }
}
void display(poly poly3[],int n){
	int i;
    for(i=0;i<n;i++){
        printf("%dx^%d ",poly3[i].coeff,poly3[i].exp);
        if(i<n-1)
        printf("+");
    }
}
void add2poly(poly poly1[],poly poly2[],poly poly3[],int x,int y){
    int i=0,j=0,k=0;
    while(i<x&&j<y){
        if(poly1[i].exp>poly2[j].exp){
            poly3[k].exp = poly1[i].exp;
            poly3[k].coeff = poly1[i].coeff;
            i++,k++;
        }
        else if(poly1[i].exp<poly2[j].exp){
            poly3[k].exp = poly2[j].exp;
            poly3[k].coeff = poly2[j].coeff;
            j++,k++;
        }
        else{
            poly3[k].exp = poly1[i].exp;
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            i++,j++,k++;
        }
    }
    while(i<x||j<y){
        if(i<x){
            poly3[k].exp = poly1[i].exp;
            poly3[k].coeff = poly1[i].coeff;
            i++,k++;
        }
        if(j<y){
            poly3[k].exp = poly2[j].exp;
            poly3[k].coeff = poly2[j].coeff;
            j++,k++;
        }
    }
    display(poly3,k);
}
int main(){
    poly poly1[max],poly2[max],poly3[max];
    int num1,num2;
    printf("Enter no of elements of polynomial 1 : ");
    scanf("%d",&num1);
    printf("Enter no of elements of polynomial 2 : ");
    scanf("%d",&num2);
    printf("Input for 1st polynomial \n");
    input(poly1,num1);
    printf("Input for 2nd polynomial \n");
    input(poly2,num2);
    add2poly(poly1,poly2,poly3,num1,num2);
}