#include <stdio.h>
#include <stdlib.h>

typedef struct node **Node;

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void printForward(Node head) {
    struct node *temp = *head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void addFirst(Node head, int elem) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = elem;

    if ((*head) == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        (*head) = newNode;
    } else {
        newNode->prev = NULL;
        newNode->next = (*head);
        (*head)->prev = newNode;
        (*head) = newNode;
    }
}

void addLast(Node head, int elem) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = elem;
    newNode->next = NULL;

    if ((*head) == NULL) {
        newNode->prev = NULL;
        (*head) = newNode;
    } else {
        struct node *last = (*head);
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
}

int searchNode(Node head, int elem) {
    struct node *temp = (*head);
    while (temp != NULL) {
        if (temp->data == elem) {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}

void deleteNode(Node head, int elem) {
    if ((*head) == NULL) {
        return;
    }
    struct node *temp = *head;

    while (temp != NULL && temp->data != elem) {
        temp = temp->next;
    }

    // if key not found:
    if (temp == NULL) {
        printf("Key not found");
    }
    // if first node is key
    else if (temp == (*head)) {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
    // if last node is key
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
    }
    // if key is in the middle
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void createDLL() {
    struct node *head, *middle, *last;

    head = malloc(sizeof(struct node));
    middle = malloc(sizeof(struct node));
    last = malloc(sizeof(struct node));

    head->data = 10;
    middle->data = 20;
    last->data = 30;

    head->next = middle;
    head->prev = NULL;
    middle->next = last;
    middle->prev = head;
    last->next = NULL;
    last->prev = middle;

    struct node *temp = head;
    // pass pointers to struct with & as parameters to function
    printForward(&temp);
}

int main() {
    struct node *head = NULL;
    createDLL();
    printf("\n");
    addFirst(&head, 10);
    addLast(&head, 20);
    addLast(&head, 30);
    addFirst(&head, 40);
    addFirst(&head, 50);
    printForward(&head);
    printf("\n");
    deleteNode(&head, 40);
    printForward(&head);
    printf("\n");
    deleteNode(&head, 30);
    printForward(&head);
    printf("\n");
    deleteNode(&head, 10);
    printForward(&head);
}