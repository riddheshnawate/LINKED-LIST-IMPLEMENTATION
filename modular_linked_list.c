#include <stdio.h>
#include <stdlib.h>

/* Singly Linked List Node */
struct Node {
    int data;
    struct Node *next;
};

/* Function Prototypes */
struct Node* createNode(int data);
void insertAtBeginning(struct Node **head, int data);
void insertAtEnd(struct Node **head, int data);
void deleteNode(struct Node **head, int key);
void traverse(struct Node *head);
int isEmpty(struct Node *head);
void freeList(struct Node **head);

/* Create a new node */
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at beginning */
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (newNode == NULL) return;
    newNode->next = *head;
    *head = newNode;
}

/* Insert at end */
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (newNode == NULL) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Delete a node */
void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

/* Traverse the list */
void traverse(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Check if list is empty */
int isEmpty(struct Node *head) {
    return head == NULL;
}

/* Free entire list */
void freeList(struct Node **head) {
    struct Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

/* Main Function */
int main() {
    struct Node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    traverse(head);

    deleteNode(&head, 20);

    traverse(head);

    freeList(&head);

    return 0;
}
