#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr[], int n){
    int i = 0, j = n-1;
    while (i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    
}

//frequency of an element in the array
void frequencyEl(int arr[], int n, int key){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(key == arr[i]){
            count++;
        }
    }
    cout<<"The frequency of "<<key<<" is: "<<count<<endl;
}

//second largest element in the array
void secondlargest(int arr[],int n){
    int largest = INT_MIN;
    int second = INT_MIN;

    for(int i = 0; i < n; i++){
        if(largest < arr[i]){
            second = largest;
            largest = arr[i];
        }
        else if(arr[i]>second && arr[i] != largest){
            second = arr[i];
        }
    }
    cout<<"The second largest element in the array is: "<<second<<endl;
}

//swap alternate elements in an array
void swapAlternate(int arr[], int n){
    int i = 0;
    while(i+1<n){
        swap(arr[i],arr[i+1]);
        i += 2;
    }
}

int main(){

    int arr[6]={32,34,5,65,75,56};

    int arr2[5]={3,4,6,9,1};

    reverseArray(arr,6);
    reverseArray(arr2,5);

    printArray(arr,6);
    printArray(arr2,5);

    swapAlternate(arr,6);
    swapAlternate(arr2,5);

    printArray(arr,6);
    printArray(arr2,5);

    int arr3[10]={23,23,34,56,75,87,23,56,53,23};

    frequencyEl(arr3,10,23);

    secondlargest(arr,6);
    secondlargest(arr2,5);
    secondlargest(arr3,10);
}