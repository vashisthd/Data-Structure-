#include<stdio.h>
#include<string.h>
#define max 100
void reverse(char str[],int len){
    for(int i=0,j=(len-1);i<j;i++,j--){
        char temp = str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
int main(){
    char str[max];
    printf("Enter string : ");
    gets(str);
    int len = strlen(str);
    reverse(str,len);
    puts(str);
}