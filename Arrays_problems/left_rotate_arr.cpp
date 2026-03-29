#include <iostream>
using namespace std;
// This program finds the largest element in an array of integers.

int main() {
    int n;
    cout<<"Enter te value of n :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    
    for(int j=0; j<k; j++){
    int temp = arr[0];

    for(int i=1; i<n; i++){
        arr[i-1]=arr[i];
    }

    arr[n-1]=temp;
    }

    cout<<"The left rotated array is :";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}
