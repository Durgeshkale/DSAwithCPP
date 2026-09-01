/*
Pairs with Given Sum in a Doubly Linked List

Question:
Given a sorted doubly linked list and an integer target, find all
pairs of nodes whose values add up to target.

Return the pairs as a 2D vector.

Example:
Input:
DLL = 1 <-> 2 <-> 3 <-> 4 <-> 9
target = 5

Output:
[1, 4]
[2, 3]


Intuition:

Since the doubly linked list is sorted, we can use two pointers:
- left starts from the head.
- right starts from the tail.

If the sum is too large, move right backwards.
If the sum is too small, move left forwards.
If the sum equals target, store the pair and move left forward.

This is the same two-pointer idea used in a sorted array,
but here we can move backwards because it is a doubly linked list.

Approach:
1. Set left = head and right = tail.
2. Calculate left->data + right->data.
3. If sum == target, store the pair and move left.
4. If sum > target, move right backwards.
5. If sum < target, move left forwards.
6. Continue until the two pointers cross.

Time Complexity: O(n)
Space Complexity: O(1)
(Excluding the space used to store the answer.)
*/

#include <bits/stdc++.h>
using namespace std;


class Node {
public:

    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};


class Solution {
public:

    vector<vector<int>> givenSumPairs(Node* head, int target) {

        vector<vector<int>> ans;

        if(head == nullptr || head->next == nullptr) {
            return ans;
        }

        Node* left = head;
        Node* right = head;

        // Move right to the tail
        while(right->next != nullptr) {
            right = right->next;
        }


        // Two-pointer approach
        while(left != right && left->prev != right) {

            int sum = left->data + right->data;

            if(sum == target) {

                ans.push_back({left->data, right->data});

                left = left->next;
            }
            else if(sum > target) {

                right = right->prev;
            }
            else {

                left = left->next;
            }
        }

        return ans;
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

    cout << "Enter sorted list elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cout << "Enter target sum: ";
    cin >> target;


    Node* head = createList(arr);

    Solution solution;

    vector<vector<int>> ans = solution.givenSumPairs(head, target);


    cout << "Pairs with sum " << target << ":" << endl;

    if(ans.empty()) {
        cout << "No pairs found." << endl;
    }
    else {
        for(auto& pair : ans) {
            cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
        }
    }


    return 0;
}