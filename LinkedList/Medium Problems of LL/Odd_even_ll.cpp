/*
Leetcode 328. Odd Even Linked List

Question:
Given the head of a singly linked list, group all the nodes with odd indices
together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, the second even, and so on.

You must preserve the relative order of both odd-indexed and even-indexed nodes.

Example 1:
Input:
head = [1,2,3,4,5]

Output:
[1,3,5,2,4]

Example 2:
Input:
head = [2,1,3,5,6,4,7]

Output:
[2,3,6,7,1,5,4]

Intuition (Brute Force):

We can traverse the linked list twice.

In the first traversal, store all nodes at odd indices into a vector.
In the second traversal, store all nodes at even indices.
Finally, overwrite the linked list values using the vector.

This preserves the required ordering but uses extra space.

Approach:

1. Traverse the linked list and store values at odd indices.
2. Traverse again and store values at even indices.
3. Traverse the linked list one final time and replace node values
   using the stored vector.
4. Return the modified linked list.

Time Complexity: O(n)

The linked list is traversed a constant number of times.

Space Complexity: O(n)

An extra vector is used to store all node values.
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

// Brute Force Solution
ListNode* oddEvenList(ListNode* head) {

    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    vector<int> list;

    ListNode* temp = head;

    // Store odd indexed nodes
    while(temp != nullptr && temp->next != nullptr) {
        list.push_back(temp->val);
        temp = temp->next->next;
    }

    if(temp) {
        list.push_back(temp->val);
    }

    // Store even indexed nodes
    temp = head->next;

    while(temp != nullptr && temp->next != nullptr) {
        list.push_back(temp->val);
        temp = temp->next->next;
    }

    if(temp) {
        list.push_back(temp->val);
    }

    // Copy values back into linked list
    temp = head;
    int i = 0;

    while(temp != nullptr) {
        temp->val = list[i++];
        temp = temp->next;
    }

    return head;
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

    head = oddEvenList(head);

    cout << "Odd-Even Linked List: ";
    printList(head);

    return 0;
}