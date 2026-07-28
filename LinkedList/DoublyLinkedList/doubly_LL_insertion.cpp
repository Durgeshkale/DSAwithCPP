#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data1, Node *next1, Node *prev1) {
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        prev = NULL;
        next = NULL;
    }
};

// Print Doubly Linked List
void printDLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

//convert array to a doubly linkedlist
Node* convertArr2LL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for(int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Insertion in doubly linked list
// insertion before:

// insertion before head of dll     
Node * insertBeforeHead(Node *head , int val) {
    Node* newHead = new Node(val , head , nullptr);
    head->prev = newHead;

    return newHead;
}

//insertiion before tail

Node* insertBeforeTail(Node * head, int val) {
    if(head->next == NULL) {
        return insertBeforeHead(head, val);
    }

    Node* tail = head;

    while(tail->next != nullptr) {
        tail = tail->next;
    }

    Node* back = tail->prev;

    Node* newNode = new Node(val, tail, back);
    tail->prev = newNode;
    back->next = newNode;   

    return head;
}

Node* insertbeforeKthel(Node* head, int val, int k) {

    if(head == NULL) {
        return new Node(val);
    }
    
    if(k == 1) return insertBeforeHead(head, val);


    Node* temp = head;
    int cnt = 1;
    while(temp != NULL) {
        if(cnt == k) break;
        cnt++;
        temp = temp->next;
    }

    if(temp == NULL)
        return head;


    Node* back = temp->prev;

    Node* newNode = new Node(val, temp, back);

    back->next = newNode;
    temp->prev = newNode;

    return head;
}


//insert before given node

void insertbeforeNode(Node* node, int val) {
    Node* back = node->prev;
    Node* newNode = new Node(val ,node, back);

    back->next  = newNode;
    node->prev = newNode;
}


int main() {
    vector<int> arr = {2, 7, 14, 8};
    Node* head = convertArr2LL(arr);
    // head = insertBeforeHead(head, 100);
    // head = insertBeforeTail(head, 100);
    // head = insertbeforeKthel(head, 100, 1);
    insertbeforeNode(head->next, 100);
    printDLL(head);
    return 0;
}