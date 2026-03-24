#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        int mini=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            } 
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

void printarr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
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
selection_sort(arr, n);
cout<<"The sorted array is: ";

for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}