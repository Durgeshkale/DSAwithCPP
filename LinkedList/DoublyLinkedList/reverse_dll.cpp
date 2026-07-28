#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data1, Node *next1, Node *prev1) {
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

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

//reverse dll
Node* reverseDll(Node* head) {
    Node* current = head;
    Node* last = current->prev;

    while(current != NULL) {
        last = current->prev;
        current->prev = current->next;
        current->next = last;

        current = current->prev;
    }
    head = last->prev;

    return head;
}

//print dll
void printDLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    vector<int> arr = {2, 7, 14, 18};
    Node* head = convertArr2LL(arr);
    head = reverseDll(head);
    printDLL(head);
    return 0;
}