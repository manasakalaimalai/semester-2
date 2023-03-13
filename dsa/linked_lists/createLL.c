// Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

typedef struct node **Node;

struct node {
    int data;
    struct node *next;
};

void printLL(Node head) {
    while(*head != NULL) {
        printf("%d ", (*head)->data);
        *head = (*head)->next;
    }
}

void addFirst(Node head, int elem) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = elem;
    newNode->next = (*head);
    (*head) = newNode;
}

void addLast(Node head, int elem) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = elem;
    newNode->next = NULL;
    if ((*head) == NULL) {
        (*head) = newNode;
    } else {
        struct node *find_last = (*head);
        while (find_last->next != NULL) {
            find_last = find_last->next;
        }
        find_last->next = newNode;
    }
}

void deleteNode(Node head, int elem) {
    struct node *temp;
    if ((*head)->data == elem) {
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    } else {
        struct node *current = (*head);
        // use current->next instead of current to prevent dealing with deletions at the last node
        while (current->next != NULL) {
            if (current->next->data == elem) {
                temp = current->next;
                current->next = current->next->next;
                free(temp);
            } else {
                current = current->next;
            }
        }
    }
}

int searchNode(Node head, int elem) {
    struct node *temp = (*head);
    while (temp != NULL) {
        if (temp->data == elem) {
            return 1;
        }
        else {
            temp = temp->next;
        }
    }
    return -1;
}

void createLL() {
    // Creating LL for 3 nodes
    struct node *head, *middle, *last;

    head = malloc(sizeof(struct node));
    middle = malloc(sizeof(struct node));
    last = malloc(sizeof(struct node));

    // Creating Values for LL
    head->data = 10;
    middle->data = 20;
    last->data = 30;

    head->next = middle;
    middle->next = last;
    last->next = NULL;

    // Printing LL
    struct node *temp = head;
    printLL(&temp);
}

int main() {
    struct node *head = NULL;

    // struct node *new = head;
    addFirst(&head, 10);
    addLast(&head, 30);
    addFirst(&head, 20);
    addLast(&head, 40);
    addFirst(&head, 100);
    deleteNode(&head, 20);
    searchNode(&head, 100);
    printLL(&head);
}