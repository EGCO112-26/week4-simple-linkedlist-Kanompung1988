//
//  main.c
//  simple linkedlist
//
//  Created by Thanapon Thanadunpremdet on 2/2/2568 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

// Define student structure
struct student {
    int id;
    char name[50];
    struct student* next;
};

// Insert student node at the end of linked list
void insertStudent(struct student** head, int id, char name[]) {
    struct student* newNode = (struct student*)malloc(sizeof(struct student));
    newNode->id = id;
    strcpy(newNode->name, name);
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

// Print all students in the linked list
void printList(struct student* head) {
    struct student* temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Delete all nodes in the linked list
void deleteList(struct student** head) {
    struct student* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main(int argc, const char * argv[]) {
    struct student* head = NULL;
    
    // Check if there are command line arguments
    if (argc > 1) {
        // Process command line arguments (pairs of id and name)
        for (int i = 1; i < argc; i += 2) {
            if (i + 1 < argc) {
                int id = atoi(argv[i]);
                insertStudent(&head, id, (char*)argv[i + 1]);
            }
        }
        
        // Print all students
        printList(head);
        
        // Delete all nodes
        deleteList(&head);
        
        return 0;
    }
    
    // Original code below (for exercises)
    int c=5;
    struct node a,b,*head2 ;
    a.value = c;
    a.next=&b;
    head2=&a;
    b.value=head2->value+3;

    printf("%d\n", head2 ->value ); //what value for 5
    printf("%d\n", head2 ->next->value ); //what value for 8
    printf("%d\n", head2 ->next->next->value ); //what value for 11
/*  Exercise I
    1. Add 1 more node at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node c_node;
    c_node.value = 11;
    c_node.next = NULL;
    b.next = &c_node;
    
/*  Exercise II
        1. Add 1 more node at the beginning!!!!
        2. Add value (2)
*/
    struct node start;
    start.value = 2;
    start.next = head2;
    head2 = &start;
    
    typedef struct node* NodePtr;
    NodePtr tmp=head2; //add temp value to facilitate
        
/*  Exercise III Use loop to print everything */
    printf("\nExercise III - Using for loop:\n");
    int i,n=4;
    tmp = head2;
    for(i=0;i<n;i++){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
/*  Exercise IV change to while loop!! (you can use NULL to help) */
    printf("\nExercise IV - Using while loop:\n");
    tmp = head2;
    while(tmp != NULL){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
/*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
*/
    printf("\nExercise V - Using malloc:\n");
    NodePtr head3 = NULL;
    NodePtr prev = NULL;
    int values[] = {2, 5, 8, 11};
    n = 4;
    
    for(i=0; i<n; i++){
        NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
        newNode->value = values[i];
        newNode->next = NULL;
        
        if(head3 == NULL){
            head3 = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    
    // Print the malloc-created list
    tmp = head3;
    while(tmp != NULL){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

/*  Exercise VI Free all nodes !!
         //use a loop to help
*/
    printf("\nExercise VI - Freeing all nodes:\n");
    tmp = head3;
    NodePtr next;
    while(tmp != NULL){
        next = tmp->next;
        printf("Freeing node with value: %d\n", tmp->value);
        free(tmp);
        tmp = next;
    }
    head3 = NULL;
    return 0;
}
