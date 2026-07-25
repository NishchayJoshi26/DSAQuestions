// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node *head = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    scanf("%d", &k);

    if (head == NULL || head->next == NULL || k == 0) {
        struct Node *temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }
    int len = 1;
    struct Node *tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) {
        struct Node *temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    int steps = len - k;
    struct Node *newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node *newHead = newTail->next;
    newTail->next = NULL;

    struct Node *temp = newHead;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}