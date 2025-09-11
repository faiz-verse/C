#include <stdio.h>
#include <stdlib.h>

// Defining the structure for the node
struct Node
{
    int data;          // can be any data
    struct Node *next; // pointer to the next node which will also be of type struct
};

// functions for menu driven linked list
void createList(struct Node **head);
void insertIntoList(struct Node **head);
void insertAtBeginning(struct Node **head);
void insertAtEnd(struct Node **head);
void insertAtPosition(struct Node **head);
void deleteNode(struct Node **head);
void traverseList(struct Node *head);
void sumList(struct Node *head);
void freeMemory(struct Node **head);

int main()
{
    // --------------------------- MENU DRIVEN LINKED LIST ---------------------------
    // Linked List Menu
    int choice;
    struct Node *head = NULL;
    while (1)
    {
        printf("\nLinked List Menu:\n\n");
        printf("1. Create a linked list\n");
        printf("2. Insert into linked list\n");
        printf("3. Delete a Node\n");
        printf("4. Traverse a linked list\n");
        printf("5. Sum a linked list\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            createList(&head);
            break;
        case 2:
            insertIntoList(&head);
            break;
        case 3:
            deleteNode(&head);
            break;
        case 4:
            traverseList(head);
            break;
        case 5:
            sumList(head);
            break;
        case 6:
            freeMemory(&head);
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

// linked list functions logic/implementation
void createList(struct Node **head)
{
    int inNumberOfNodes;
    printf("Enter the number of nodes for the list ");
    scanf("%d", &inNumberOfNodes);

    if (inNumberOfNodes <= 0)
    {
        printf("Invalid number of nodes!\n");
        return;
    }

    // creating the head
    *head = (struct Node *)malloc(sizeof(struct Node)); // allocating memory for the first node
    struct Node *temp = *head;

    // taking data for the node 1
    printf("\nEnter the value to be stored in Node 1: ");
    scanf("%d", &temp->data);

    int i = 2;
    while (i <= inNumberOfNodes)
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

    printf("\nList created successfully!\n");
}

void freeMemory(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    printf("Cleaning the memory!\n\n");
    struct Node *temp = *head;
    while (*head != NULL)
    {
        temp = *head;
        (*head)->next = temp;
        free(*head);
    }
}

void traverseList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List does not exists!\n");
        return;
    }
    struct Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("On Node %d\nNode address: %p\nData: %d\nNext node address: %p\n\n", i, (void *)temp, temp->data, (void *)temp->next);
        temp = temp->next;
        i++;
    }
}

void sumList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List does not exists!\n");
        return;
    }
    struct Node *temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of the data in the list is %d\n", sum);
}

void insertIntoList(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List does not exists!\n");
        return;
    }
    int choice;
    while (1)
    {
        printf("\nSelect the type of insertion: \n\n");
        printf("1. Insert at the beginning of the list\n");
        printf("2. Insert at the end of the list\n");
        printf("3. Insert at the specific position of the list\n");
        printf("4. Exit insertion\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            insertAtBeginning(&(*head));
            break;
        case 2:
            insertAtEnd(&(*head));
            break;
        case 3:
            insertAtPosition(&(*head));
            break;
        case 4:
            return; // would not exit the whole program but exit the switch
        default:
            printf("Invalid choice!\n");
        }
    }
}

void insertAtBeginning(struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value to be stored in created node: ");
    scanf("%d", &newNode->data);
    newNode->next = *head;
    *head = newNode;
    printf("New node inserted successfully!\n");
}

void insertAtEnd(struct Node **head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value to be stored in created node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("New node inserted successfully!\n");
}

void insertAtPosition(struct Node **head)
{
    int position;
    printf("\nEnter the position at which you want to insert: ");
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Position cannot be less than 1");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value to be stored in created node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (position = 1) // insert at beginning
    {
        newNode->next = *head;
        *head = newNode;
        printf("New node inserted successfully!\n");
        return;
    }

    struct Node *temp = *head;
    int i = 1;
    while (temp != NULL && i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) // position too large
    {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("New node inserted successfully!\n");
}

void deleteNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List does not exist!\n");
        return;
    }

    int position;
    printf("\nEnter the position of the node you want to delete: ");
    scanf("%d", &position);

    if (position <= 1) // delete head
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node deleted successfully!\n");
        return;
    }

    struct Node *temp = *head;
    int i = 1;
    while (temp != NULL && i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of range!\n");
        return;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    printf("Node deleted successfully!\n");
}
