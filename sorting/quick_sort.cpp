#include<bits/stdc++.h>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<= pivot && i <= high-1){
            i++;
        }
        while (arr[j]> pivot && j>= low+1)
        {
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
        
    }

    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high){
    if(low < high) {
        int partition_index = partition(arr,low,high);
        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
    }
}

int main(){
int low=0;
int high;
cout<<"Enter the value of high: ";
cin>>high;
std::vector<int> arr;
cout<<"Enter the array elements: ";
for(int i=0; i<high; i++){
    int tempValue;
    std::cin>>tempValue;
    arr.push_back(tempValue);
}
quick_sort(arr,low,high-1);
cout<<"The sorted array is: ";

for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}