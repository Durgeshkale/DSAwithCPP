/*
Segregate 0s, 1s and 2s in a Linked List

Question:
Given the head of a linked list containing only 0s, 1s, and 2s,
sort the linked list such that all 0s come first,
followed by all 1s, and then all 2s.

The relative order within each group does not matter.

Example 1:
Input:
head = [1,2,2,1,2,0,2,2]

Output:
[0,1,1,2,2,2,2,2]

Example 2:
Input:
head = [2,2,0,1]

Output:
[0,1,2,2]

Intuition:

Instead of counting the occurrences and updating node values,
we can create three separate linked lists:
one for 0s, one for 1s, and one for 2s.

While traversing the original list, attach each node to its
corresponding list. Finally, connect the three lists together.

Approach:

1. Create three dummy nodes for 0s, 1s, and 2s.
2. Traverse the original linked list.
3. Attach each node to the corresponding list.
4. Connect the 0-list to the 1-list (or 2-list if no 1 exists).
5. Connect the 1-list to the 2-list.
6. Mark the last node's next as NULL.
7. Return the head of the merged list.

Time Complexity: O(n)

Each node is visited exactly once.

Space Complexity: O(1)

Only three dummy nodes are used.
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

// Segregate 0s, 1s and 2s
Node* segregate(Node* head) {

    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* zerosHead = new Node(-1);
    Node* zeros = zerosHead;

    Node* onesHead = new Node(-1);
    Node* ones = onesHead;

    Node* twosHead = new Node(-1);
    Node* twos = twosHead;

    Node* temp = head;

    while(temp != nullptr) {

        if(temp->data == 0) {
            zeros->next = temp;
            zeros = temp;
        }
        else if(temp->data == 1) {
            ones->next = temp;
            ones = temp;
        }
        else {
            twos->next = temp;
            twos = temp;
        }

        temp = temp->next;
    }

    // Connect the three lists
    zeros->next = (onesHead->next) ? onesHead->next : twosHead->next;
    ones->next = twosHead->next;
    twos->next = nullptr;

    return zerosHead->next;
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

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter linked list elements (0, 1, or 2): ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = createList(arr);

    head = segregate(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}