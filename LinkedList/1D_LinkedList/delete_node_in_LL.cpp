/*
Leetcode 237. Delete Node in a Linked List

Question:
You are given only the node to be deleted in a singly linked list.
Delete that node without access to the head of the list.

Example 1:
Input:
4 -> 5 -> 1 -> 9
node = 5

Output:
4 -> 1 -> 9

Example 2:
Input:
4 -> 5 -> 1 -> 9
node = 1

Output:
4 -> 5 -> 9

Intuition:

Since we are not given the head or previous node,
we cannot actually remove the current node.

Instead:
1. Copy the value of the next node into the current node.
2. Skip the next node.

This makes the current node look deleted.

Approach:

1. Copy next node's value to current node.
2. Point current node to next->next.
3. The next node is effectively removed.

Time Complexity: O(1)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void deleteNode(ListNode* node) {

    // copy next node value
    node->val = node->next->val;

    // skip next node
    node->next = node->next->next;
}

void printList(ListNode* head) {

    while(head) {
        cout << head->val;

        if(head->next) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main() {

    // 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    // delete node with value 5
    deleteNode(head->next);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}