/*
Leetcode 24. Swap Nodes in Pairs

Question:
Given a linked list, swap every two adjacent nodes and return
the modified list.

You must swap the nodes themselves, not just their values.

Example 1:
Input:
[1,2,3,4]

Output:
[2,1,4,3]

Example 2:
Input:
[1,2,3]

Output:
[2,1,3]

Example 3:
Input:
[]

Output:
[]


Intuition:

We swap two nodes at a time.

For every pair:
    first -> second

We change the links to:
    second -> first

A dummy node is used before the head so that the first pair can
also be handled in the same way as all other pairs.

Approach:
1. Create a dummy node pointing to head.
2. Keep prev pointing to the node before the current pair.
3. Take first and second nodes of the pair.
4. Reverse their links.
5. Move prev to first and process the next pair.
6. Return dummy->next.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Dummy node helps handle the first pair easily
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr)
        {

            ListNode *first = prev->next;
            ListNode *second = first->next;

            // Swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy->next;
    }
};

/*
Create linked list.
*/
ListNode *createList(vector<int> &arr)
{

    if (arr.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {

        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

/*
Print linked list.
*/
void printList(ListNode *head)
{

    while (head != nullptr)
    {

        cout << head->val;

        if (head->next != nullptr)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main()
{

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter list elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ListNode *head = createList(arr);

    Solution solution;

    head = solution.swapPairs(head);

    cout << "Linked list after swapping pairs: ";

    printList(head);

    return 0;
}