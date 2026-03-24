#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sortOne(int arr[], int n){
    int left = 0, right = n-1;

    while(left<right){
        while (arr[left]==0 && left<right)
        {
            left++;
        }
        while (arr[right]==1 && left<<right)
        {
            right--;
        }

        if(arr[left]==1 && arr[right]==0 && left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        
        
    }
}

void sort012(int arr[],int n){
    int low =0, mid=0, high=n-1;

    while(mid <= high){

        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }

        else if(arr[mid]==1){
            mid++;
        }

        else{
            swap(arr[mid],arr[high]);
                high--;
        }
    }
}

int main(){

    int arr[10]={0,1,1,1,2,2,0,1,1,1};
    sort012(arr,10);
    printArray(arr,10);
}