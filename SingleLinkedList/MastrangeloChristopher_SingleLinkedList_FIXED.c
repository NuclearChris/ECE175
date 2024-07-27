#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

bool nodeExist(int data, Node **head);

void appendNode(int data, Node **head);

void printList(Node *head);

int main(void)
{
    Node *head = NULL;

    // Test list 1
    appendNode(1, &head);
    appendNode(2, &head);
    appendNode(3, &head);
    appendNode(4, &head);
    appendNode(5, &head);
    appendNode(6, &head);
    printf("----Test List 1----\n");
    printf("Original Linked List: \n");
    printList(head);


// Function to print the linked list in reverse order
void printListReverse(Node *head) {
    // Base case: if the head is NULL, return
    if (head == NULL)
        return;
    
    // Recursive case: first, recur on the next node
    printListReverse(head->next);
    
    // Then print the data of the current node
    printf("%d->", head->data);
}
    // Calling function1 : expect printing 5->4->3->2->1->->NULL

    printf("Function One:");
    printf("\n");
    printListReverse(head);
    printf("NULL");



// Function to reverse the linked list
void reverseLinkedList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;   // Store next
        current->next = prev;   // Reverse current node's pointer
        prev = current;         // Move pointers one position ahead
        current = next;
    }
    *head = prev;
}

// Function to print the linked list
void printList(Node *head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        } else {
            printf("->NULL\n");
        }
        current = current->next;
    }
}       
    // Calling function2
    printf("\n");
    printf("Function Two:\n");
    reverseLinkedList(&head);
    printList(head); //expect 5->4->3->2->1->->NULL

// function3
// input: 1->2->3->4->5->->NULL
// Output: "middle node is 3"
Node* findMiddleNode(Node *head) {
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    //fast pointer advances twice, slow pointer advances once
    //when fast pointer reaches NULL, slow pointer is at middle 
    //prev stores the second middle pointer in the case of even list   
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    // If the list has an even number of nodes, return the higher of the two middle nodes
    if (fast == NULL && prev != NULL) {
        if (prev->data > slow->data) {
            return prev;
        }
    }
    
    return slow;
}
void printMiddleNode(Node *head) {
    //find the middle node
    Node* middle = findMiddleNode(head);
    //print the middle node
    if (middle != NULL) {
        printf("The middle node of the list is %d\n", middle->data);
    } else {
        printf("The list is empty.\n");
    }
}
//calling function
    printf("Function Three: \n");
    printMiddleNode(head);

    // function4:
    // input: 1->2->3->4->5->->NULL
    // output (by printList(head4)): 1->2->4->5->->NULL
    // deleteMiddleNode()

void deleteMiddleNode(Node **head) {
    if (*head == NULL) {
        return; // List is empty
    }
    
    // Find the middle node
    Node* middle = findMiddleNode(*head);
    
    // If the list has only one node
    if (*head == middle) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    // Find the node before the middle node
    Node* current = *head;
    while (current->next != NULL && current->next != middle) {
        current = current->next;
    }
    
    // Delete the middle node
    if (current->next == middle) {
        current->next = middle->next;
        free(middle);
    }
}
    printf("Function Four:\n");
    deleteMiddleNode(&head);
    printList(head);

    // Test list 2
    Node *head2 = NULL;
    appendNode(21, &head2);
    appendNode(44, &head2);
    appendNode(32, &head2);
    appendNode(45, &head2);
    appendNode(5, &head2);
    appendNode(25, &head2);

    printf("\n----Test List 2----\n");
    printf("Function 3: \n");
    printMiddleNode(head2);
    printf("Function 4:");
    // function4:
    // input: 21->44->32->45->5->25->NULL
    // output (by printList(head4)): 21->44->32->5->25->NULL
    deleteMiddleNode(&head2);
    printf("\n");
    printList(head2);

    // Test list 3
    Node *head3 = NULL;
    appendNode(1, &head3);
    appendNode(94, &head3);
    appendNode(37, &head3);
    appendNode(4, &head3);
    appendNode(45, &head3);
    appendNode(58, &head3);

    printf("\n---Test List 3----\n");
    // input: 1->94->37->4->45->58->NULL
    // Output: "middle node is 37"
    // Calling function3    // findMiddleNode()

    // function4:
    // input: 1->94->37->4->45->58->NULL
    // output (by printList(head4)): 1->94->4->45->58->NULL
    // deleteMiddleNode()
    printf("Function 3: \n");
    printMiddleNode(head3);
    printf("Function 4:");

    deleteMiddleNode(&head3);
    printf("\n");
    printList(head3);
    return 0;
}

/*
    This is a helper function which will help us
    determine if a node exist in the list
*/
bool nodeExist(int data, Node **head)
{
    // setting temp = to the first element of the list
    Node *temp = *head;

    while (temp != NULL)
    {
        if (data == temp->data)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

void appendNode(int data, Node **head)
{

    if (nodeExist(data, head))
    {
        printf("This node already exist in the list\n");
        return;
    }

    // Create a new node using dynamic memory allocation
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *temp = *head;

    // Case 1: Empty list
    if (*head == NULL)
    {
        /*
            before: head -> NULL
        */
        *head = newNode;
        newNode->next = NULL;
        /*               (data, next)
            after: head -> NewNode -> NULL
        */
    }
    else
    {
        /*

         supposed we want to add node (20): want this (51)->(7)->(4)->(20)->NULL
                    temp
         (51)->(7)->(4)->(new)->NULL
        */
        // Case2: List is not empty
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

// This function prints the linkedlist
void printList(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}