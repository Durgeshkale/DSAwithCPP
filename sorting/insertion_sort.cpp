#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j = i;
        while(j > 0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;

            cout<<"runs";
        }
    }
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
insertion_sort(arr,n);
cout<<"The sorted array is: ";

for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}