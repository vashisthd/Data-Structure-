#include<stdio.h>
#include<string.h>
#define MAX 100
int main(){
    char str[MAX];
    printf("Enter string : ");
    gets(str);
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    printf("Length of string is %d ",i);
}