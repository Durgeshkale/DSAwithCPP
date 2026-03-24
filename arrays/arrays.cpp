#include <iostream>
using namespace std;

void printarray(int arr[],int size){
    cout<<"Printing the array: \n";
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // declare 
    int number[15];

    printarray(number,15);

    //accessing an array
    cout<<"Value at 15 index "<< number[14]<<endl;

    //initialising an array
    int second[3]={5,7,12};

    //accessing elements
    cout<<"value at index 2: "<<second[2]<<endl;

    int third[15]={3,6};

    // print array
    /*for(int i = 0; i<15 ; i++){
        third[i] = 1;
        cout<<third[i]<<" ";
    }
    cout<<endl;*/

    printarray(third,15);



}