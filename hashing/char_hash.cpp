#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    //pre computing
    /*
    int hash[26]={0}; //since we have made it only for lowerspace characters
    for(int i=0; i<s.size(); i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while( q-- ){
        char c;
        cin>>c;

        //fetch
        cout<<hash[c-'a']<<endl;   
    } */

    //if characters are not specified then we must take arr size as 256 

    int hash[256]={0}; //since we have made it only for lowerspace characters
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }

    int q;
    cin>>q;
    while( q-- ){
        char c;
        cin>>c;

        //fetch
        cout<<hash[c]<<endl;   
    }

}
