#include <bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
        Node* next;

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;

    }
};

Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]); //create a head and stored it 
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head; // we just have to return the starting point it finds complete linked list

}

//search in a ll
int checkIfPresent(Node* head, int val) {
    Node* temp = head;
    while(temp) {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}



int main() {
    // vector<int> arr = {2, 4, 5, 7};
    // Node* y = new Node(arr[0] ,nullptr);
    // cout<< y;
    vector<int> arr = {2, 5 , 8, 7};
    Node* head = convertArr2LL(arr);
    cout << head->data << endl;

    // linked list traversal and length of LL
    // Node* temp = head;
    // int cnt = 0;

    // while(temp) {
    //     cout<< temp->data<< " ";
    //     temp = temp->next;
    //     cnt++;
    // }
    // cout<<endl <<"Length of the linked list: " << cnt;

    cout << checkIfPresent(head, 7);
}