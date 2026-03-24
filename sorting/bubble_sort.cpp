#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int didSwap = 0;
        for(int j=0; j<i-1;j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
                didSwap=1;
            }
        }
        if(didSwap == 0){
            break;
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
bubble_sort(arr,n);
cout<<"The sorted array is: ";

for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}