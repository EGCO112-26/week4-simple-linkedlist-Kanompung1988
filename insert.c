#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float gpa;
    struct student* next;
};

void insertStudent(struct student** head, int id, char name[], float gpa) {
    struct student* newNode =
        (struct student*)malloc(sizeof(struct student));

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->gpa = gpa;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct student* head) {
    struct student* temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, GPA: %.2f\n",
               temp->id, temp->name, temp->gpa);
        temp = temp->next;
    }
}

void deleteList(struct student** head) {
    struct student* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Linked list deleted.\n");
}

int main() {
    struct student* head = NULL;

    // Insert using input arguments
    insertStudent(&head, 1, "Alice", 3.50);
    insertStudent(&head, 2, "Bob", 3.20);
    insertStudent(&head, 3, "Charlie", 3.80);

    printf("Student List:\n");
    printList(head);

    deleteList(&head);

    return 0;
}
