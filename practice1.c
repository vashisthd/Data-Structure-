// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Function to check if a character is an operator
// int isOperator(char ch) {
//     return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
// }

// // Function to get the precedence of an operator
// int getPrecedence(char op) {
//     if (op == '+' || op == '-')
//         return 1;
//     else if (op == '*' || op == '/')
//         return 2;
//     else
//         return 0; // Assuming any other character is not an operator
// }

// // Function to convert infix expression to 
// void infixToPostfix(char *infix, char *postfix) {
//     int i, j;
//     char stack[100]; // Stack to store operators
//     int top = -1;

//     for (i = 0, j = 0; infix[i] != '\0'; i++) {
//         char ch = infix[i];

//         if (isalnum(ch)) {
//             postfix[j++] = ch;
//         } else if (ch == '(') {
//             stack[++top] = ch;
//         } else if (ch == ')') {
//             while (top != -1 && stack[top] != '(') {
//                 postfix[j++] = stack[top--];
//             }
//             if (top != -1 && stack[top] == '(') {
//                 top--; // Discard the '('
//             }
//         } else if (isOperator(ch)) {
//             while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(ch)) {
//                 postfix[j++] = stack[top--];
//             }
//             stack[++top] = ch;
//         }
//     }

//     // Pop any remaining operators from the stack
//     while (top != -1) {
//         postfix[j++] = stack[top--];
//     }

//     postfix[j] = '\0'; // Null-terminate the postfix expression
// }

// int main() {
//     char infix[100], postfix[100];

//     printf("Enter an infix expression: ");
//     gets(infix);

//     infixToPostfix(infix, postfix);

//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }
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

