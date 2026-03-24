#include<iostream>
using namespace std;

void linearSearch(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i]==key){
            cout<<"The element "<<key<< " is found in the array at index "<<i<<"\n";
        }
    }
}
int main(){

    int arr[10]={32,44,43,45,65,54,55,65,34,78};
    int key = 34;
    
    linearSearch(arr,10,34);

}