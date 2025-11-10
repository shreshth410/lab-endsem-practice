#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Stacks[100];
int top[MAX], boundary[MAX];

/*Functions: 
1. Push~
2. Pop~
3. isFull~
4. isEmpty~
5. Peek~
6. Display~
7. Initialise~
*/

void initValues() {
    int partition = 100 / MAX;
    for (int i = 0; i < MAX; i++) {
        boundary[i] = i * partition - 1;
        top[i] = boundary[i];
    }
    boundary[MAX] = 100 - 1;
}


int isFull(int pos){
    return (top[pos] == boundary[pos+1]);
}

int isEmpty(int pos){
    return (top[pos] == boundary[pos]);
}

void push(int pos, int val){
    if (isFull(pos)){
        printf("Stack is full\n");
        return;
    }

    Stacks[++top[pos]] = val;
    printf("Pushed %d to stack %d\n", val, pos);
}

int pop(int pos){
    if (isEmpty(pos)){
        printf("Stack is empty\n");
        return 0;
    }
    
    printf("Popped %d from stack %d\n", Stacks[top[pos]], pos);
    return Stacks[top[pos]--];
}

int peek(int pos){
    if (isEmpty(pos)){
        printf("Stack empty\n");
        return -1;
    }

    return Stacks[top[pos]];
}

void display(int pos){
    if (isEmpty(pos)){
        printf("Stack empty\n");
        return;
    }

    printf("Stack %d: ", pos);
    for (int j = top[pos]; j > boundary[pos]; j--){
        printf("%d\t", Stacks[j]);
    }
    printf("\n");
}

int main(void) {
    initValues();

    // Push two values to each stack
    for (int i = 0; i < MAX; i++) {
        push(i, 100 + i);
        push(i, 200 + i);
    }

    for (int i = 0; i < MAX; i++) {
        display(i);
    }

    // Pop one value from each stack
    for (int i = 0; i < MAX; i++) {
        pop(i);
    }

    // Display all stacks
    for (int i = 0; i < MAX; i++) {
        display(i);
    }

    for (int i = 0; i < MAX; i++) {
        pop(i);
    }

    // Display all stacks
    for (int i = 0; i < MAX; i++) {
        display(i);
    }
}
