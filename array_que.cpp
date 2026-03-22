#include <iostream>
using namespace std;

void SumofArrEl(int arr[], int size){
    int sum=0;
    for(int i = 0; i<size; i++){
        sum += arr[i];
    }
    cout<<"The sum of the array elements is :"<<sum<<endl;
}
int main(){
    int size;
    cout<<"Enter the size of array: \n";
    cin>>size;
    int arr[100];
    cout<<"Enter the array elements: \n";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    SumofArrEl(arr,size);
}