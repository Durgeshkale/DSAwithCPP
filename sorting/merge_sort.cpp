#include<bits/stdc++.h>
#include<vector>
using namespace std;

// function to merge the halves of the array
void merge(vector<int> &arr, int low, int mid, int high){
    //Create temp arrays
    vector <int> temp;
    int left = low;
    int right = mid+1;
    
    //Merge two sorted halves 
    while(left<=mid && right<=high){
        if(arr[left]<= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    //Copying the remaining elements form left half 
    while (left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //Copying the remaining elements from right half
    while (right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    //Copying  sorted elements back to originial array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
    
    
}


//Recursive merge sort funciton
void merge_sort(vector<int> &arr, int low, int high){
    if(low >= high) return;

    //Find the middle index
    int mid = (low+high)/2;

    //Recursively sort the left half
    merge_sort(arr,low,mid);

    //Recursively sort the right half
    merge_sort(arr,mid+1,high);

    //Merge two sorted havles
    merge(arr,low,mid,high);
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
merge_sort(arr,low,high-1);
cout<<"The sorted array is: ";

for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}