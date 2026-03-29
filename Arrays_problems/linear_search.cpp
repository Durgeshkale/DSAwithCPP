#include<iostream>
using namespace std;

void linear_search(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            cout<<"Search is successful. "<<key<<" is found at " <<i<<" index.";
            break;
        }
    }
    cout<<"Search is unsuccessful. Element not found.";
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements: ";

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the element you want to search in the array:";
    cin>>key;

    linear_search(arr,n,key);
    

}