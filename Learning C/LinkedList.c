/*
    Linked lists function as an array that can grow and shrink as needed, from any point in the array.
    Each node has:
        1. Data (actual value)
        2. Pointer to the next node
    Linked lists have a few advantages over arrays:
        Items can be added or removed from the middle of the list
        There is no need to define an initial size
        Unlike arrays, linked lists don’t store elements in contiguous memory.
    However, linked lists also have a few disadvantages:
        There is no "random" access. needs to be translated to the nth node for the access
        Dynamic memory allocation and pointers are required which increases complexity of code
        Linked lists have a much larger overhead over arrays.
*/

#include <stdio.h>
#include <stdlib.h>

// Defining the structure for the node
struct Node
{
    int data;          // can be any data
    struct Node *next; // pointer to the next node which will also be of type struct
};

int main()
{
    // Simple linked list
    // Allocating 3 nodes in the heap
    // 1. defining the pointers
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    // 2. allocating memory for structures
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    // 3. assigning data to the node
    first->data = 1;
    first->next = second; // so the next contains the address for the second node
    second->data = 2;
    second->next = third; // so the next contains the address for the third node
    third->data = 3;
    third->next = NULL; // so the next is NULL i.e. no further nodes

    // temporary node to translate through the list
    struct Node *temp = first;
    int i = 1;
    while (temp != NULL)
    {
        // When printing addresses with %p, cast to (void*) (the C standard recommends it)
        printf("On Node %d\nNode address: %p\nData: %d\nNext node address: %p\n\n", i, (void *)temp, temp->data, (void *)temp->next);
        temp = temp->next;
        i++;
    }

    // Taking input from the user and accordingly ask data to sum
    int inNumOfNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &inNumOfNodes);
    if (inNumOfNodes <= 0)
    {
        printf("The number of nodes cannot be 0 or less than 0!\n\n");
        return 0; // exiting the main loop here with return 0
    }
    // creating the first node or head node
    struct Node *head = NULL;
    head = (struct Node *)malloc(sizeof(struct Node)); // allocating memory for the first node
    temp = head;
    // taking data for the node 1
    printf("\nEnter the value to be stored in Node 1: ");
    scanf("%d", &temp->data);
    i = 2;
    while (i <= inNumOfNodes)
    {
        // taking data for the other nodes
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // allocating memory for the new node
        printf("\nEnter the value to be stored in Node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL; // making the new node as the last node
        temp->next = newNode; // making the temp to point to the new created node
        temp = newNode;       // moving the temp to the new node
        i++;
    }
    temp = head;
    i = 1;
    int sum = 0;
    while (temp != NULL)
    {
        printf("On Node %d\nNode address: %p\nData: %d\nNext node address: %p\n\n", i, (void *)temp, temp->data, (void *)temp->next);
        sum += temp->data;
        temp = temp->next;
        i++;
    }
    printf("The Sum of the Data is %d\n\n", sum);

    // Freeing the memory
    temp = NULL;
    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }

    // other way aroung using FOR LOOP to avoid the last extra node
    printf("Enter the data for the same (using FOR LOOP)\n\n");
    struct Node *forHead = NULL;
    temp = NULL;
    for (int i = 1; i <= inNumOfNodes; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the value to be stored in Node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL; // making the new node as the last node
        if (forHead == NULL)  // making the head node as not initialized outside the for loop
        {
            forHead = newNode; // putting the value of new node in the head
            temp = forHead;    // making the head as the current node
        }
        else
        {
            temp->next = newNode; // making the temp to point to the new created node
            temp = newNode;       // moving the temp to the new node
        }
    }

    temp = forHead;
    sum = 0;
    for (int i = 1; i <= inNumOfNodes; i++)
    {
        printf("On Node %d\nNode address: %p\nData: %d\nNext node address: %p\n\n", i, (void *)temp, temp->data, (void *)temp->next);
        sum += temp->data;
        temp = temp->next;
    }
    printf("The Sum of the Data is %d\n\n", sum);

    // freeing the memory used by the nodes
    temp = NULL;
    for (int i = 0; i < inNumOfNodes; i++)
    {
        temp = forHead->next;
        free(forHead);
        forHead = temp;
    }

    return 0;
}