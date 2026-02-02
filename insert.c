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

int main(int argc, char* argv[]) {
    struct student* head = NULL;

    // ตรวจสอบว่ามีอาร์กิวเมนต์เพียงพอหรือไม่
    if (argc < 4 || (argc - 1) % 3 != 0) {
        printf("Usage: %s <id1> <name1> <gpa1> [<id2> <name2> <gpa2> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i += 3) {
        int id = atoi(argv[i]);
        char* name = argv[i + 1];
        float gpa = atof(argv[i + 2]);

        insertStudent(&head, id, name, gpa);
    }

    // พิมพ์ข้อมูลในลิงก์ลิสต์
    printf("Student List:\n");
    printList(head);

    // ลบลิงก์ลิสต์
    deleteList(&head);

    return 0;
}