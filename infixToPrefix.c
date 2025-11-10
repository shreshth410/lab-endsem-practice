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
 * (This function is unchanged and correct)
 */
void infixToPostfix(char* infix, char* postfix) {
    int i = 0; // Infix index
    int j = 0; // Postfix index
    char token;
    
    // Reset stack just in case
    top = -1;

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
            while (!isEmpty() && peek() != '(') {
                char topOp = peek();
                int tokenPrec = getPrecedence(token);
                int topPrec = getPrecedence(topOp);

                if (tokenPrec < topPrec) {
                    postfix[j++] = pop();
                }
                else if (tokenPrec > topPrec) {
                    break;
                }
                else {
                    if (getAssociativity(token) == 'L') {
                        postfix[j++] = pop();
                    }
                    else {
                        break;
                    }
                }
            }
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

/**
 * Reverses a string and swaps parentheses.
 * (e.g., "(A+B)" becomes ")B+A(")
 */
void reverseAndSwap(char* input, char* output) {
    int len = strlen(input);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (input[i] == '(') {
            output[j++] = ')';
        } else if (input[i] == ')') {
            output[j++] = '(';
        } else {
            output[j++] = input[i];
        }
    }
    // Add null terminator
    output[j] = '\0';
}

/**
 * Reverses a string without swapping.
 * (This is your original reverseString, but fixed)
 */
void simpleReverse(char* input, char* output) {
    int len = strlen(input);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        output[j++] = input[i];
    }
    // Add null terminator
    output[j] = '\0';
}

/**
 * Converts infix to prefix using the 3-step algorithm.
 * (This function is now corrected)
 */
void infixToPrefix(char* infix, char* prefix) {
    // Need temporary strings to hold intermediate results.
    // Use arrays, not uninitialized pointers.
    char reversedInfix[MAX_SIZE];
    char tempPostfix[MAX_SIZE];

    // Step 1: Reverse the infix string and swap parentheses
    reverseAndSwap(infix, reversedInfix);

    // Step 2: Run the standard infix-to-postfix algorithm
    // on the reversed string.
    infixToPostfix(reversedInfix, tempPostfix);

    // Step 3: Reverse the resulting "postfix" string to
    // get the final prefix expression.
    simpleReverse(tempPostfix, prefix);
}

// --- Main function to test the conversion ---
int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Call the corrected function
    infixToPrefix(infix, prefix);

    printf("Infix Expression:   %s\n", infix);
    printf("Prefix Expression:  %s\n", prefix);

    // --- Example 2: Test precedence and associativity ---
    printf("\n--- Example Test (with ^, R->L) ---\n");
    char infix2[] = "A+B*C-D/E^F^G";
    char prefix2[MAX_SIZE];
    
    infixToPrefix(infix2, prefix2);
    printf("Infix Expression:   %s\n", infix2);
    printf("Prefix Expression:  %s\n", prefix2); 
    // Expected Prefix: -+A*BC/D^E^FG

    return 0;
}