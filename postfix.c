#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100
struct Stack {
    int top;
    int items[MAX_STACK_SIZE];
};
void push(struct Stack* stack, int item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    stack.top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }}}
    return pop(&stack);
}
int main() {
    char postfix[MAX_STACK_SIZE];
    printf("Enter a postfix expression: ");
    gets(postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    getch();  // Wait for a key press before exiting
    return 0;
}

