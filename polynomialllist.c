#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coef;
    int expo;
    struct Node* next;
}Node;

Node* createList(Node* head, int c, int e){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->coef = c;
    newNode->expo = e;
    newNode->next = NULL;

    if (head == NULL){
        return newNode;
    }
    else if (head->next == NULL){
        head->next = newNode;
        return head;
    }
    else{
        Node* ptr = head;
        while (ptr->next) ptr = ptr->next;

        ptr->next = newNode;
        return head;
    }
}

void displayPolynomial(Node* head){
    Node* ptr = head;

    while (ptr->next != NULL){
        if (ptr->expo == 0) printf("%d+", ptr->coef);
        else{
            if (ptr->next->expo < 0) printf("%dx^%d-", ptr->coef, ptr->expo);
            else printf("%dx^%d+", ptr->coef, ptr->expo);
        }
        ptr = ptr->next;
    }

    if (ptr->expo == 0) printf("%d", ptr->coef);
    else printf("%dx^%d", ptr->coef, ptr->expo);

    printf("\n");
}

Node* addPolynomial(Node* head1, Node* head2){
    Node* p1 = head1, *p2 = head2;
    Node* ans = NULL;

    while (p1 != NULL && p2 != NULL){
        if (p1->expo > p2->expo){
            ans = createList(ans, p1->coef, p1->expo);
            p1 = p1->next;
        }
        else if (p1->expo < p2->expo){
            ans = createList(ans, p2->coef, p2->expo);
            p2 = p2->next;
        }
        else if (p1->expo == p2->expo){
            ans = createList(ans, (p1->coef+p2->coef), p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    if (p1 == NULL && p2 == NULL) return ans;

    Node* ptrr;
    if (p1 != NULL) ptrr = p1;
    else if (p2 != NULL) ptrr = p2;

    while (ptrr != NULL) {
        ans = createList(ans, ptrr->coef, ptrr->expo);
        ptrr = ptrr->next;
    }

    return ans;
}

int main(void){
    Node* head1 = NULL, *head2 = NULL;

    int c, e;

    printf("\nFirst polynomial: \n");

    printf("First coefficient: ");
    scanf("%d", &c);

    printf("First exponent: ");
    scanf("%d", &e);

    head1 = createList(head1, c, e);

    printf("Second coefficient: ");
    scanf("%d", &c);

    printf("Second exponent: ");
    scanf("%d", &e);

    head1 = createList(head1, c, e);

    printf("Third coefficient: ");
    scanf("%d", &c);

    printf("Third exponent: ");
    scanf("%d", &e);

    head1 = createList(head1, c, e);

    printf("\nSecond polynomial: \n");

    printf("First coefficient: ");
    scanf("%d", &c);

    printf("First exponent: ");
    scanf("%d", &e);

    head2 = createList(head2, c, e);

    printf("Second coefficient: ");
    scanf("%d", &c);

    printf("Second exponent: ");
    scanf("%d", &e);

    head2 = createList(head2, c, e);

    printf("Third coefficient: ");
    scanf("%d", &c);

    printf("Third exponent: ");
    scanf("%d", &e);

    head2 = createList(head2, c, e);

    displayPolynomial(head1);
    displayPolynomial(head2);

    Node* additionHead = NULL;
    additionHead = addPolynomial(head1, head2);
    displayPolynomial(additionHead);
}