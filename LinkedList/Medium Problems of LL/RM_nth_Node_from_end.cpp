/*
Leetcode 19. Remove Nth Node From End of List

Question:
Given the head of a linked list, remove the nth node from the end
of the list and return its head.

Example 1:
Input:
head = [1,2,3,4,5], n = 2

Output:
[1,2,3,5]

Example 2:
Input:
head = [1], n = 1

Output:
[]

Example 3:
Input:
head = [1,2], n = 1

Output:
[1]

Intuition:

Instead of first finding the length of the linked list,
we use two pointers.

Move the fast pointer n steps ahead. Then move both fast and slow
together until fast reaches the last node. At that point,
slow will be just before the node to be deleted.

Approach:

1. Move the fast pointer n nodes ahead.
2. If fast becomes NULL, remove the head node.
3. Initialize slow at the head.
4. Move both pointers together until fast reaches the last node.
5. Delete slow->next.
6. Return the updated head.

Time Complexity: O(n)

Each node is visited at most once.

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

// Remove nth node from the end
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* fast = head;

    // Move fast pointer n steps ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Remove head node if required
    if(fast == nullptr) {
        return head->next;
    }

    ListNode* slow = head;

    // Move both pointers together
    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the target node
    ListNode* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;

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

    int k;
    cout << "Enter nth node to remove from end: ";
    cin >> k;

    ListNode* head = createList(arr);

    head = removeNthFromEnd(head, k);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}