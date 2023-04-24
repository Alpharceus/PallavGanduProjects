#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct ListNode* createNode(char data) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* insertSorted(struct ListNode* head, char data) {
    struct ListNode* newNode = createNode(data);
    struct ListNode* current;

    if (head == NULL || head->data > data) {
        newNode->next = head;
        return newNode;
    }

    current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int removeItem(struct ListNode** headRef, char data) {
    struct ListNode* current = *headRef;
    struct ListNode* prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                *headRef = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return 1;
        }

        prev = current;
        current = current->next;
    }

    return 0;
}

struct ListNode* pushStack(struct ListNode* head, char data) {
    struct ListNode* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

char popStack(struct ListNode** headRef) {
    struct ListNode* head;
    char data;

    if (*headRef == NULL) {
        return '\0'; /* Return null character if the list is empty */
    }

    head = *headRef;
    data = head->data;
    *headRef = head->next;
    free(head);
    return data;
}


int listLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%c", head->data);
        if (head->next != NULL) {
            printf(", ");
        }
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void reverseList(struct ListNode** headRef) {
    struct ListNode* prev = NULL;
    struct ListNode* current = *headRef;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}
