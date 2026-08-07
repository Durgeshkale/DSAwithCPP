/*
Add 1 to a Number Represented as a Linked List (Recursive Approach)

Question:
A non-negative number is represented as a singly linked list,
where each node contains a single digit.

Add one to the number and return the head of the updated linked list.

Example 1:
Input:
head = [4,5,6]

Output:
[4,5,7]

Example 2:
Input:
head = [9,9,9]

Output:
[1,0,0,0]

Intuition:

Recursion naturally reaches the last node first,
which represents the least significant digit.

While returning from recursion, propagate the carry
towards the head just like manual addition.

Approach:

1. Recursively reach the last node.
2. Return an initial carry of 1.
3. Add carry to the current node.
4. Update the node value and propagate carry if needed.
5. If carry remains after processing the head,
   create a new node with value 1.

Time Complexity: O(n)

Each node is visited exactly once.

Space Complexity: O(n)

Recursive call stack is used.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Recursive helper function
int helper(Node* temp) {

    if(temp == nullptr) {
        return 1;
    }

    int carry = helper(temp->next);

    temp->data += carry;

    if(temp->data < 10) {
        return 0;
    }

    temp->data = 0;

    return 1;
}

// Add one to linked list
Node* addOne(Node* head) {

    int carry = helper(head);

    if(carry == 1) {

        Node* newNode = new Node(1);
        newNode->next = head;

        return newNode;
    }

    return head;
}

// Create linked list
Node* createList(vector<int>& arr) {

    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print linked list
void printList(Node* head) {

    while(head != nullptr) {
        cout << head->data;

        if(head->next) cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter digits: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = createList(arr);

    head = addOne(head);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}