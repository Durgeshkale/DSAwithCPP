/*
Leetcode 876. Middle of the Linked List

Question:
Given the head of a singly linked list, return the middle node
of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input:
head = [1,2,3,4,5]

Output:
[3,4,5]

Explanation:
The middle node is node 3.

Example 2:
Input:
head = [1,2,3,4,5,6]

Output:
[4,5,6]

Explanation:
There are two middle nodes (3 and 4). Return the second middle node.

Intuition:

Instead of first finding the length of the linked list, we use the
Tortoise and Hare algorithm (Slow and Fast Pointer).

The slow pointer moves one node at a time, while the fast pointer
moves two nodes at a time. When the fast pointer reaches the end,
the slow pointer will be at the middle of the linked list.

Approach:

1. Initialize both slow and fast pointers at the head.
2. Move slow by one step and fast by two steps.
3. Continue until fast reaches the end of the list.
4. Return the slow pointer as the middle node.

Time Complexity: O(n/2) ≈ O(n)

The fast pointer moves two nodes at a time, so the loop runs about n/2 times.

Space Complexity: O(1)

Only two pointers are used.
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

// Find middle node using Slow & Fast Pointer
ListNode* middleNode(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr) {

        // Slow moves 1 step
        slow = slow->next;

        // Fast moves 2 steps
        fast = fast->next->next;
    }

    return slow;
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

    ListNode* middle = middleNode(head);

    cout << "Middle Node: ";
    printList(middle);

    return 0;
}