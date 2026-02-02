//
//  main.c
//  simple linkedlist
//
//  Created by Thanapon Thanadunpremdet on 2/2/2568 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value ); //what value for 11
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
    start.next = head;
    head = &start;
    
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to facilitate
        
/*  Exercise III Use loop to print everything */
    printf("\nExercise III - Using for loop:\n");
    int i,n=4;
    tmp = head;
    for(i=0;i<n;i++){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
/*  Exercise IV change to while loop!! (you can use NULL to help) */
    printf("\nExercise IV - Using while loop:\n");
    tmp = head;
    while(tmp != NULL){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    
/*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
*/
    printf("\nExercise V - Using malloc:\n");
    head = NULL;
    NodePtr prev = NULL;
    int values[] = {2, 5, 8, 11};
    n = 4;
    
    for(i=0; i<n; i++){
        NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
        newNode->value = values[i];
        newNode->next = NULL;
        
        if(head == NULL){
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    
    // Print the malloc-created list
    tmp = head;
    while(tmp != NULL){
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

/*  Exercise VI Free all nodes !!
         //use a loop to help
*/
    printf("\nExercise VI - Freeing all nodes:\n");
    tmp = head;
    NodePtr next;
    while(tmp != NULL){
        next = tmp->next;
        printf("Freeing node with value: %d\n", tmp->value);
        free(tmp);
        tmp = next;
    }
    head = NULL;
    return 0;
}
