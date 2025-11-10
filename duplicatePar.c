#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int isDuplicate(char s[]) {
    char Stack[MAX_SIZE];
    int top = -1;
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            // Case 1: Empty brackets ()
            if (top != -1 && Stack[top] == '(') {
                return 1; // Duplicate found
            }
            
            int elementsInside = 0;
            // Pop until '(' is found
            while (top != -1 && Stack[top] != '(') {
                elementsInside++;
                top--;
            }
            
            // Pop the '(' also
            if (top != -1) {
                top--;
            }
            
            // If no valid content inside ()
            if (elementsInside == 0) {
                return 1;
            }
        } else {
            // Push character onto stack
            Stack[++top] = s[i];
        }
    }
    
    // Check for unmatched parentheses
    while (top != -1) {
        if (Stack[top--] == '(') {
            return 1; // Unmatched opening parenthesis
        }
    }
    
    return 0;
}

int main() {
    char test_expressions[][MAX_SIZE] = {
        "((a+b))",
        "(a+(b+c))",
        "(a+b)",
        "((a+b)+c)",
        "()",
        "(a)",
        "((a))"
    };
    
    int num_expressions = sizeof(test_expressions) / sizeof(test_expressions[0]);
    
    for (int i = 0; i < num_expressions; i++) {
        int result = isDuplicate(test_expressions[i]);
        printf("Expression: %s\n", test_expressions[i]);
        printf("Has duplicate parentheses: %s\n\n", result ? "True" : "False");
    }
    
    return 0;
}