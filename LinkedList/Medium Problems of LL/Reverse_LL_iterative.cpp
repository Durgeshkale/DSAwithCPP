/*
Leetcode 206. Reverse Linked List (Iterative Approach)

Question:
Given the head of a singly linked list, reverse the linked list
and return the new head.

Note:
A recursive approach can also be used to solve this problem.

Example 1:
Input:
head = [1,2,3,4,5]

Output:
[5,4,3,2,1]

Example 2:
Input:
head = [1,2]

Output:
[2,1]

Example 3:
Input:
head = []

Output:
[]

Intuition:

Traverse the linked list while reversing the direction of each link.

Maintain three pointers:
- prev  -> previous node
- temp  -> current node
- front -> next node

Reverse the current node's link, then move all pointers one step ahead.

Approach:

1. Initialize prev as NULL.
2. Traverse the linked list using temp.
3. Store temp->next in front.
4. Reverse the link by pointing temp->next to prev.
5. Move prev and temp one step forward.
6. After traversal, prev becomes the new head.

Time Complexity: O(n)

Each node is visited exactly once.

Space Complexity: O(1)

Only three pointers are used.
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};

// Reverse the linked list
ListNode* reverseList(ListNode* head) {

    ListNode* prev = nullptr;
    ListNode* temp = head;

    while(temp != nullptr) {

        // Store next node
        ListNode* front = temp->next;

        // Reverse current link
        temp->next = prev;

        // Move pointers ahead
        prev = temp;
        temp = front;
    }

    return prev;
}

// Create linked list
ListNode* createList(vector<int>& arr) {

    if(arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head) {

    while(head != nullptr) {
        cout << head->val;

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

    cout << "Enter linked list elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ListNode* head = createList(arr);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}