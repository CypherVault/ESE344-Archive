#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the list
void insert(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to sort the linked list using bubble sort
void sortList(Node*& head) {
    if (head == nullptr || head->next == nullptr) return;

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr; // Keeps track of the last sorted node

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Swap data between nodes
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = true;
            }
            current = current->next;
        }
        lastSorted = current; // Update the last sorted node
    } while (swapped);
}

// Main function to run the program
int main() {
    Node* head = nullptr;

    // Example input: Insert values into the linked list
    insert(head, 4);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);

    cout << "Original List: ";
    printList(head);

    // Sort the linked list
    sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
