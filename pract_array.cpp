#include <iostream>
#include <climits>
#include<cmath>
using namespace std;

void maxOfarray(int arr[], int size){
    int maxi= INT_MIN ;
    for(int i = 0; i < size; i++){
       // if(max<arr[i]){
       //     max = arr[i];
       // }
       maxi = max(maxi,arr[i]);
    }
    cout<<"Maximum no. in the array is: "<<maxi<<endl;
}

void minOfarray(int arr[], int size){
    int mini = INT_MAX;
    for(int i = 0; i < size; i++){
        //if(min>arr[i]){
        //    min = arr[i];
        //}
        mini = min(mini,arr[i]);
    }
    cout<<"Minimum no. in the array is: "<<mini<<endl;
}

int main(){
    int size;
    cin>>size;
    int arr[100];

    //taking input in array
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    maxOfarray(arr,size);
    minOfarray(arr,size);
}