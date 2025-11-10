#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int stack_even[MAX];
int stack_odd[MAX];
int top_even = -1, top_odd = -1;

void push(int val){
    if (val%2 == 0){
        if (top_even == MAX-1) printf("Stack full\n");
        else stack_even[++top_even] = val;
    }
    else {
        if (top_odd == MAX-1) printf("Stack full\n");
        else stack_odd[++top_odd] = val;
    }
}

void pop_even(){
    if (top_even == -1){
        printf("Stack empty\n");
        return;
    }
    else top_even--;
}

void pop_odd(){
    if (top_odd == -1){
        printf("Stack empty\n");
        return;
    }
    else top_odd--;
}

int average_even(){
    if (top_even == -1) {
        printf("Stack empty\n");
        return -1;
    }

    int sum = 0;
    int n = top_even + 1;
    int p = top_even;
    while (p > -1){
        sum += stack_even[p--];
    }

    sum = sum/n;

    return sum;
}

int average_odd(){
    if (top_odd == -1){
        printf("Stack empty\n");
        return -1;
    }
    
    int sum = 0;
    int n = top_odd + 1;
    int p = top_odd;
    while (p > -1){
        sum += stack_odd[p--];
    }

    sum = sum/n;

    return sum;
}

int main(void){
    int val, ch, avg_odd, avg_even;
    printf("=========Operations:========== \n");
    printf("1. Push\n");
    printf("2. Pop from even stack\n");
    printf("3. Pop from odd stack\n");
    printf("4. Take average from even stack\n");
    printf("5. Take average from odd stack\n");
    printf("6. Exit\n");

    while (1){
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: 
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: 
                pop_even();
                printf("Popped from even stack\n");
                break;
            case 3: 
                pop_odd();
                printf("Popped from odd stack\n");
                break;
            case 4: 
                avg_even = average_even();
                printf("Even number average: %d\n", avg_even);
                break;
            case 5: 
                avg_odd = average_odd();
                printf("Average of odd numbers: %d\n", avg_odd);
                break;
            case 6: 
                exit(0);
        }
    }
}