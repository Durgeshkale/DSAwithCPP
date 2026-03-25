#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter te value of n :";
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int largest =arr[0];
    for(int i=0; i<n; i++){
        if(arr[i>largest]){
            largest =arr[i];
        }
    }

    cout<<"The largest element in the array is: "<<largest;
    return 0;
}
