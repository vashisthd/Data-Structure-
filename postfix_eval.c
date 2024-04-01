#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 100
float stack[max];
int top=-1;
void push(float val){
        top++;
        stack[top] = val;
}
float pop(){
        float value = stack[top];
        top--;
        return value;
}
float evaluate(float a,float b,char operator){
    float res;
    switch (operator)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    case '^':
        res = pow(a,b);
        break;
    }
    return res;
}
float postfix_eval(char* str){
    int n = strlen(str);
    for(int i=0;i<n;i++){
        if(str[i]>=48 && str[i]<=57){
            int value = (int)(str[i]) - (int)('0');
            push(value);
        }
        else{
            char operator = str[i];
            float operand2 = pop();
            float operand1 = pop();
            float final = evaluate(operand1,operand2,operator);
            push(final);
        }
    }
    float res= pop();
    return res;
}
int main(){
    char str[max];
    printf("Enter the expression : ");
    gets(str);
    float result = postfix_eval(str);
    printf("Final value of expression after evaluation is %.2f \n",result);
    return 0;
}