#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n];
    //pre computing
    unordered_map<int,int>mpp;
    //map<int, int>mpp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mpp[arr[i]]++;
    }

    //this is how we iterate in map
    for(auto it: mpp){
        cout<<it.first<<"->" <<it.second<<endl;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;

        //fetch
        cout<<mpp[number]<<endl;
    }
}

//maps storess all the values in the sorted order 