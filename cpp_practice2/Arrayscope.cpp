#include <iostream>
using namespace std;


void update(int arr[], int n){
    arr[0]=120;
    cout<<"Inside the function \n";

    for(int i =0 ; i < 3; i++){
        cout<<arr[i]<< " ";

    }
    cout<<endl;

    cout<<"Going back to the main function \n";
}

int main(){
    int arr[3]={1,2,3};

    update(arr, 3);
    /* main has given the starting address of the array to the 
    update function, so any process done by the update function will
    be done on the actual array */

    //printing array
    for(int i =0 ; i<3; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}