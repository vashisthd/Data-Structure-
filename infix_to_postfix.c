#include<stdio.h>
#include<string.h>
#define max 100
int stack[max];
int top=-1;
void push(float val){
        top++;
        stack[top] = val;
}
int pop(){
        int value = stack[top];
        top--;
        return value;
}
int priority(char operator){
    int value;
    switch (operator)
    {
    case '$':
        value = 0;
        break;
    case '(':
        value = 1;
        break;
    case '+': case '-':
        value = 2;
        break;
    case '/': case '*':
        value = 4;
        break;
    case '^':
        value = 6;
        break;
    }
    return value;
}
void display(char* str){
    int n = strlen(str);
    printf("Postfix expression is : ");
    for(int i=0;i<n;i++){
        printf("%c",str[i]);
    }
}
void infixtopost(char* infix,char* postfix){
    int n = strlen(infix);
    push('$');
    int k=0;
    for(int i=0;i<n;i++){
        if((infix[i]>=65&&infix[i]<=90)||(infix[i]>=97&&infix[i]<=122)){
            postfix[k++]=infix[i];
        }
        else if(priority(infix[i])==1){
            int val = i;
            while(infix[val]!=')'){
                push(infix[val]);
                val++;
            }
            for(int j=i;j<val;j++){
                char operator = pop();
                postfix[k++]= operator;
            }
        }
        else{
            if(priority(infix[i])>priority(stack[top])){
                push(infix[i]);
            }
            else if(priority(infix[i])==priority(stack[top])){
                char operator = pop();
                postfix[k++]= operator;
                push(infix[i]);
            }
            else{
                postfix[k++]=infix[i];
            }
        }
    }
}
int main(){
    char infix[max],postfix[max];
    printf("Enter the Infix Expression : ");
    gets(infix);
    infixtopost(infix,postfix);
    display(postfix);
}