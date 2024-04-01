#include<stdio.h>
#include<string.h>
#define max 1200
int main(){
    char str[max];
    printf("Enter the string\n");
    gets(str);
    int n = strlen(str);
    if (n==0) 
    {   printf("The string is empty.\n");
        return 0;
    }
    int flag =1;
    for(int i=0,j=(n-1);i<j;i++,j--){
        if(str[i]!=str[j]){
            flag=0;
            break;
        }
        
        
    }
    if(flag==1){
        printf("String is pallindrome\n");
    }
    else
    printf("String is not pallindrome\n");
}