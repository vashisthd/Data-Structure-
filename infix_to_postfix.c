#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#define max 100
int stack[max];
int top = -1;
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch == '^');
}

int getPrecedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; 
    }
}
void push(float val){
        top++;
        stack[top] = val;
}
float pop(){
        float value = stack[top];
        top--;
        return value;
}
void infixToPostfix(char* infix,char* postfix) {
    int i, j;
    char operator;
    
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                operator = pop();
                postfix[j++] = operator;
            }
            push(infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
           while (top >= 0 && stack[top] != '(') {
                operator = pop();
                postfix[j++] = operator;
            }
            top--;
        }
    }
    while (top >= 0) {
            operator = pop();
                postfix[j++] = operator;
    }

    
    postfix[j] = '\0';
}
void display(char* str){
    int n = strlen(str);
    printf("Postfix expression is : ");
    for(int i=0;i<n;i++){
        printf("%c",str[i]);
    }
}
int main() {
    char infix[100], postfix[100];

    // Input infix expression
    printf("Enter the infix expression: ");
    gets(infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display the postfix expression
    display(postfix);

    return 0;
}

/*
A+B					o/p: AB+
A+B-C+D*E/F			o/p: AB+C-DE*F/+
A-B+C-D/E*F*(G-H)		o/p: AB-C+DE/F*GH-*-
A+B*C^D-E-F-G/H/J*K*L+M	o/p: ABCD^*+E-F-GH/J/K*L*-M+
A*(B+C)/(D-(E-F^G-H))		o/p: ABC+*DEFG^-H- -/
(A-B-(C^D))/((E^(F*G-H)))	o/p: AB-CD^-EFG*H-^/
((A+B)^C^D)+E			o/p: AB+ C^D^E+
(A*(B*C/D)^E)			o/p: ABC*D/E^*
(A*(B/C*D))^E			o/p: ABC/D**E^

*/