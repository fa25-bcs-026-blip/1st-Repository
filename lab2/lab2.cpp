#include <iostream>

using namespace std;

// Node for the singly linked list
struct SNode
{
    int data;
    SNode* next;
};

// Node for the doubly linked list
struct DNode
{
    int data;
    DNode* prev;
    DNode* next;
};

// This function converts the singly linked list into a doubly linked list
DNode* convertToDoubly(SNode* head)
{
    // If the list is empty, return nothing
    if (head == NULL)
    {
        return NULL;
    }

    DNode* doublyHead = NULL;
    DNode* doublyTail = NULL;

    SNode* current = head;

    // Go through each node of the singly linked list
    while (current != NULL)
    {
        // Create a new node for the doubly linked list
        DNode* newNode = new DNode;

        newNode->data = current->data;
        newNode->prev = doublyTail;
        newNode->next = NULL;

        // If this is the first node
        if (doublyHead == NULL)
        {
            doublyHead = newNode;
        }
        else
        {
            // Connect the previous node with the new node
            doublyTail->next = newNode;
        }

        // Move the tail to the new node
        doublyTail = newNode;

        // Move to the next node in the singly linked list
        current = current->next;
    }

    return doublyHead;
}

// Display the singly linked list
void displaySingly(SNode* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Display the doubly linked list
void displayDoubly(DNode* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    // Creating the singly linked list
    SNode* head = new SNode{10, NULL};

    head->next = new SNode{20, NULL};
    head->next->next = new SNode{30, NULL};
    head->next->next->next = new SNode{40, NULL};

    // Show the original singly linked list
    cout << "Singly Linked List: ";
    displaySingly(head);

    // Convert the singly linked list into a doubly linked list
    DNode* doublyHead = convertToDoubly(head);

    // Show the converted doubly linked list
    cout << "Doubly Linked List: ";
    displayDoubly(doublyHead);

    return 0;
}
