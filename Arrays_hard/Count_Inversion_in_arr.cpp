/*Given an array of N integers, count the inversion of the array (using merge-sort).

Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

so we solve it using the concept of merge sort

basically first we saw that if we have two sorted arrays we can check if the above conditions satisfies and if yes we can increase the count not only by
one but by the no. of elements in the first array that is arr[i] since it is a sorted array 

but our question gives us unsorted array so
basically we can perfrom merge sort on the array since it breaks the array in to smaller parts until it is sorted and then it 
merges two sorted array in sorted order
so when we perform merge in merge sort at that time we can use the above method to count the no. of pairs (inversion paris)

*/


#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
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
            cnt += (mid - left + 1);
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

int findInversions(vector<int>& nums){
    cnt = 0; // reset cnt

    int n = nums.size();
    merge_sort(nums, 0, n-1);

    return cnt;
}

int main(){
    int n;
    cout << "Enter the size of array: \n" ;
    cin >> n;

    vector<int> nums(n) ;
    cout << "Enter the array elements: \n" ;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int inversions = findInversions(nums);

    cout<<"The total no. of inversion paris are: " <<inversions;

    return 0;
}