#include <stdio.h>
#include <ctype.h>  // For isdigit() and isalpha()
#include <string.h> // For string manipulation

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int getPriority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        // If the character is an operand (letter or digit), add it to postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the character is '(', push it to the stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        // If the character is an operator, pop all higher or equal precedence operators from the stack
        else {
            while (top != -1 && getPriority(stack[top]) >= getPriority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop all remaining operators in the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    gets(infix); // Unsafe, but used for simplicity here. Use fgets() for better safety.
    
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
