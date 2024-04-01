#include<stdio.h>
void display(int poly[],int n){
    printf("Degree of addition polynomial is : %d\n",n);
    printf("Addition of two polynomial is : \n");
    for (int i = 0; i <=n;i++) {
        if((poly[i]<10)&&(poly[i]>-9))
        printf("  %d  ",n-i);
        else if(((poly[i]>=10)&&(poly[i]<100))||((poly[i]>(-100)&&(poly[i]<=(-10))))){
            printf("   %d  ",n-i);
        }
       }
       printf("\n");
       for(int i=0;i<=n;i++){
        printf("%dx   ",poly[i]);
        if((i+1)<n){
            printf("+");
        }
       } 
    }

int main(){
    int deg1,deg2,deg3;
    printf("Enter degree for 1st polynomial : ");
    scanf("%d",&deg1);
    printf("Enter degree for 2nd polynomial : ");
    scanf("%d",&deg2);
    int poly1[50],poly2[50],poly3[50];
    printf("\nEnter coefficients of the first polynomial:\n");
    for(int i=0;i<=deg1;i++){
        printf("Enter coefficient of x^%d : ",(deg1-i));
        scanf("%d",&poly1[deg1-i]);
    }
    printf("\nEnter coefficients of the second polynomial:\n");
    for(int i=0;i<=deg2;i++){
        printf("Enter coefficient of x^%d : ",(deg2-i));
        scanf("%d",&poly2[deg2-i]);
    }
    if(deg1==deg2){
        for(int i=0;i<=deg1;i++){
            poly3[i] = poly1[deg1-i] + poly2[deg2-i];
        }
        deg3 = deg1;
        display(poly3,deg3);
    }
    else if(deg1>deg2){
        deg3 = deg1;
        for(int i=0;i<(deg1-deg2);i++){
            poly3[i]=poly1[deg1-i];
        }
        for(int i=(deg1-deg2);i<=deg1;i++){
            poly3[i] = poly1[deg1-i] + poly2[deg2 -(i-(deg1-deg2))];
        }
        display(poly3,deg3);
    }
    else if(deg2>deg1){
        deg3 = deg2;
        for(int i=0;i<(deg2-deg1);i++){
            poly3[i]=poly2[deg2-i];
        }
        for(int i=(deg2-deg1);i<=deg2;i++){
            poly3[i] = poly2[deg2-i] + poly1[deg1-(i-(deg2-deg1))];
        }
        display(poly3,deg3);
    }
}
/*#include <stdio.h>
#include <string.h>

int findSubstring(const char *mainString, const char *subString) {
    int mainLen = strlen(mainString);
    int subLen = strlen(subString);

    for (int i = 0; i <= mainLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (mainString[i + j] != subString[j]) {
                break;
            }
        }
        // printf("%d",j);
        if (j == subLen) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    char mainString[100], subString[50];

    printf("Enter the main string: ");
    gets(mainString);

    printf("Enter the substring to find: ");
    gets(subString);

    int index = findSubstring(mainString, subString);

    if (index != -1) {
        printf("Substring '%s' found at index %d in the main string.\n", subString, index);
    } else {
        printf("Substring '%s' not found in the main string.\n", subString);
    }

    return 0;
}*/
