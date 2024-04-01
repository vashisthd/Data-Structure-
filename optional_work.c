#include<stdio.h>
#include<stdbool.h>
#define max 100
char stack[100];
int top = -1;
/*bool IS_EMPTY(){
    if(top== -1){
        return true;
    }
    else
        return false;
}
int main(){
    if(IS_EMPTY())
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}*/
bool is_pallindrome(){
    int j=top;
    for(int i=0;i<j;i++,j--){
        if(stack[i]!=stack[j]){
            return false;
        }
    }
    return true;
}
void push(char val){
    if(top>=max-1){
        printf("Stack is already full \n");
    }
    else{
        top++;
        stack[top] = val;
    }
}
void display(){
    printf("Stack is : ");
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
        }
}
int main(){
    char str[max];
    int i=0;
    printf("Enter string \n");
    gets(str);

    while(i<max){
        
        if(str[i]=='\0')
        break;
        else
        push(str[i]);
        i++;
    }
    display();
    printf("\n");
    if(is_pallindrome()==true){
        printf("Yes , It's pallindrome \n");
    }
    else
        printf("No, It's not a pallindrome\n");
}