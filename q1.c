#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

typedef struct Event{
    char name[50];
    char event_name[50];
    int reg_id;
} Event;

typedef struct Queue{
    Event events[MAX];
    int front, rear;
} Queue;

Queue* initQueue(void){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    return q;
}

Queue* enqueue(Queue* q, char n[], char en[], int reg){
    if (q->rear == MAX-1){
        printf("Queue full\n");
        return q;
    }

    strcpy(q->events[++(q->rear)].name, n);
    strcpy(q->events[q->rear].event_name, en);
    q->events[q->rear].reg_id = reg;

    return q;
}

Queue* dequeue(Queue* q){
    if (q->rear == q->front || q->rear == -1){
        printf("Queue empty.\n");
        return q;
    }
    q->front++;
    return q;
}

void display(Queue* q){
    printf("\n=======Queue of events: ========\n");
    for (int i = q->front+1; i < q->rear+1; i++){
        printf("Name: %s\n", q->events[i].name);
        printf("Event Name: %s\n", q->events[i].event_name);
        printf("Registration ID: %d\n\n", q->events[i].reg_id);
    }
    printf("\n");
}

int main(void){
    int r, ch;
    char n[50];
    char en[50];

    Queue* q = initQueue();

    printf("\nQueue functions: \n\n");
    printf("1. Enqueue an event\n");
    printf("2. Dequeue an event\n");
    printf("Display the queue\n");
    printf("4. Exit\n");

    while (1){
        printf("Enter a choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: 
                printf("Enter name: ");
                scanf(" %[^\n]", n);
                printf("Enter event name: ");
                scanf(" %[^\n]", en);
                printf("Enter Registration ID: ");
                scanf("%d", &r);
                q = enqueue(q, n, en, r);
                break;
            
            case 2: 
                q = dequeue(q);
                break;

            case 3:
                display(q);
                break;
            case 4: 
                exit(0);

            default: 
                printf("Invalid choice\n");
                break;
        }
    }
}