#include <iostream>
#include <vector>
using namespace std;
// This program finds the secondlargest element in an array of integers.

int secondLargest(vector<int> &arr,int n) {
    int largest = arr[0];
    int second_largest = -1; // in case of array with negative numbers use int max
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest = arr[i];  
        }
        else if(arr[i]<largest && arr[i]>second_largest){
            second_largest=arr[i];
        }    
    }
    return second_largest;
}

int main() {
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int> arr;

    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        arr.push_back(value);
    }
    
    for (int i : arr)
    {
        cout <<i<<" ";
    }
    cout<<endl;
    
    cout<<"The second largest element in the array is: "<<secondLargest(arr,arr.size());
    return 0;
}
