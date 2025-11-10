// make a stack of nodes, each node represents an incoming car at the car service center, each car should have car number, 
// owner name and service. It should be able to, add a new car node, remove car node, 
// display all the cars and exit (menu driver)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    int carno;
    char owner[50];
    char service[20];
    struct Node* next;
} Node;

Node* stack[MAX];
int top = -1;

Node* createCar(char o[], char s[], int n){
    Node* node = malloc(sizeof(Node));

    node->carno = n;
    int i = 0;

    while (o[i] != '\0'){
        node->owner[i] = o[i];
    }
    node->owner[i+1] = o[i+1];

    i = 0;
    while (s[i] != '\0'){
        node->service[i] = s[i];
    }
    node->service[i+1] = s[i+1];

    return node;
}

void push(Node* n){
    if (top == MAX-1) {
        printf("Stack is full\n");
    }
    else {
        stack[++top] = n;
    }
}

void removeCar(){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        top--;
    }
}

void display(){
    int i = 0; 
    for (i = 0; i <= top; i++){
        printf("Car %d\n", i+1);
        printf("Car No: %d\n", stack[i]->carno);
        printf("Car Owner: %s\n", stack[i]->owner);
        printf("Service: %s\n\n", stack[i]->service);
    }
}

int main(void) {
    int choice = 0;
    int c;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add new car\n");
        printf("2. Remove car\n");
        printf("3. Display all cars\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            /* clear invalid input */
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (choice == 1) {
            int carno;
            char owner[50];
            char service[20];

            printf("Enter car number: ");
            if (scanf("%d", &carno) != 1) {
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Invalid car number.\n");
                continue;
            }
            /* consume leftover newline before fgets */
            while ((c = getchar()) != '\n' && c != EOF) {}

            printf("Enter owner name: ");
            if (!fgets(owner, sizeof owner, stdin)) {
                printf("Input error.\n");
                continue;
            }
            size_t len = strlen(owner);
            if (len > 0 && owner[len - 1] == '\n') owner[len - 1] = '\0';

            printf("Enter service: ");
            if (!fgets(service, sizeof service, stdin)) {
                printf("Input error.\n");
                continue;
            }
            len = strlen(service);
            if (len > 0 && service[len - 1] == '\n') service[len - 1] = '\0';

            Node* n = malloc(sizeof(Node));
            if (!n) {
                perror("malloc");
                continue;
            }
            n->carno = carno;
            strncpy(n->owner, owner, sizeof n->owner - 1);
            n->owner[sizeof n->owner - 1] = '\0';
            strncpy(n->service, service, sizeof n->service - 1);
            n->service[sizeof n->service - 1] = '\0';
            n->next = NULL;

            push(n);
        }
        else if (choice == 2) {
            removeCar();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice. Please select 1-4.\n");
        }
    }

    /* free any remaining nodes on stack */
    while (top >= 0) {
        free(stack[top--]);
    }

    return 0;
}