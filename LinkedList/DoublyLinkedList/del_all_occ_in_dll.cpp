/*
Delete All Occurrences of X in a Doubly Linked List

Question:
Given a doubly linked list and an integer x, delete all nodes
whose value is equal to x and return the updated head.

Example:
Input:
DLL = 1 <-> 2 <-> 3 <-> 2 <-> 4
x = 2

Output:
1 <-> 3 <-> 4


Intuition:

Traverse the linked list and whenever we find a node containing x,
connect its previous node directly to its next node.

For the head node, simply update head to the next node.

Approach:
1. Traverse the list using temp.
2. If temp->data == x, store its previous and next nodes.
3. Connect prev->next to next and next->prev to prev.
4. If the node is head, update head.
5. Delete the current node and continue from the next node.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;


class Node {
public:

    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};


class Solution {
public:

    Node* deleteAllOccurOfX(Node* head, int x) {

        Node* temp = head;

        while(temp != nullptr) {

            if(temp->data == x) {

                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;

                // If current node is the head
                if(prevNode == nullptr) {
                    head = nextNode;
                }
                else {
                    prevNode->next = nextNode;
                }

                // Connect next node back to previous node
                if(nextNode != nullptr) {
                    nextNode->prev = prevNode;
                }

                // Delete current node
                delete temp;

                // Continue from next node
                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};


/*
Create doubly linked list.
*/
Node* createList(vector<int>& arr) {

    if(arr.empty()) {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++) {

        Node* newNode = new Node(arr[i]);

        temp->next = newNode;
        newNode->prev = temp;

        temp = newNode;
    }

    return head;
}


/*
Print doubly linked list.
*/
void printList(Node* head) {

    while(head != nullptr) {

        cout << head->data;

        if(head->next != nullptr) {
            cout << " <-> ";
        }

        head = head->next;
    }

    cout << endl;
}


int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter list elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;

    cout << "Enter value to delete: ";
    cin >> x;


    Node* head = createList(arr);

    Solution solution;

    head = solution.deleteAllOccurOfX(head, x);

    cout << "List after deleting all occurrences of " << x << ": ";

    printList(head);


    return 0;
}