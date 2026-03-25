#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}   

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"The array is "<<(isSorted(arr, n) ? "sorted" : "not sorted")<<endl;
    return 0;
}