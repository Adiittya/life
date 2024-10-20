#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;
void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack[++top] = item;
    }
}
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}
int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item;
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            push(infix[i]);
        } else if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == ')' && top != -1) {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            item = pop(); // Remove the left parenthesis
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        } }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    clrscr();
    printf("Enter an infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    getch();
    return 0;
}
