#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // For strlen()
#include <ctype.h>  // For isalnum()

#define MAX_SIZE 100

// --- Stack Implementation ---
char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow.\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        return '\0'; // Return null char if empty
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}
// --- End of Stack ---

/**
 * Returns the precedence of an operator.
 * Higher number means higher precedence.
 */
int getPrecedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // For parentheses
    }
}

/**
 * Returns the associativity of an operator.
 * 'R' for Right-associative, 'L' for Left-associative.
 */
char getAssociativity(char op) {
    switch (op) {
        case '^':
            return 'R';
        default:
            return 'L'; // All other operators are Left-associative
    }
}

/**
 * Converts a given infix expression to postfix
 * based on the provided algorithm rules.
 */
void infixToPostfix(char* infix, char* postfix) {
    int i = 0; // Infix index
    int j = 0; // Postfix index
    char token;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        // Rule 1: Operands -> Send directly to output.
        if (isalnum(token)) {
            postfix[j++] = token;
        } 
        
        // Rule 2: Left parenthesis -> Push onto stack.
        else if (token == '(') {
            push(token);
        } 
        
        // Rule 3: Right parenthesis -> Pop & output until ( is found.
        else if (token == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop(); // Pop and discard the '('
            } else {
                printf("Error: Mismatched parentheses\n");
                exit(1);
            }
        } 
        
        // Rule 4: Operators
        else {
            // Check rules while stack is not empty and top is not '('
            while (!isEmpty() && peek() != '(') {
                char topOp = peek();
                int tokenPrec = getPrecedence(token);
                int topPrec = getPrecedence(topOp);

                // Rule 4.3: If lower precedence -> Pop & output
                if (tokenPrec < topPrec) {
                    postfix[j++] = pop();
                }
                // Rule 4.2: If higher precedence -> Push it (by breaking loop)
                else if (tokenPrec > topPrec) {
                    break;
                }
                // Rule 4.4 & 4.5: If same precedence
                else {
                    // Left -> Right associativity -> Pop & output
                    if (getAssociativity(token) == 'L') {
                        postfix[j++] = pop();
                    }
                    // Right -> Left associativity -> Push (by breaking loop)
                    else {
                        break;
                    }
                }
            }
            // Rules 4.1, 4.2, 4.5 all lead to pushing the operator
            push(token);
        }
    }

    // Rule 5: End of expression -> Pop all operators
    while (!isEmpty()) {
        if(peek() == '(') {
             printf("Error: Mismatched parentheses\n");
             exit(1);
        }
        postfix[j++] = pop();
    }

    // Null-terminate the postfix string
    postfix[j] = '\0';
}

// --- Main function to test the conversion ---
int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Reset stack for conversion
    top = -1; 
    infixToPostfix(infix, postfix);

    printf("Infix Expression:   %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    // --- Example 2: Test precedence and associativity ---
    printf("\n--- Example Test (with ^, R->L) ---\n");
    char infix2[] = "A+B*C-D/E^F^G"; // E^F^G is E(FG^)^
    char postfix2[MAX_SIZE];
    top = -1; // Reset stack
    
    infixToPostfix(infix2, postfix2);
    printf("Infix Expression:   %s\n", infix2);
    printf("Postfix Expression: %s\n", postfix2); 
    // Expected: ABC*+DEFG^^/-

    return 0;
}