#include<iostream>
using namespace std;

int dummy(int n){
    n++;
    cout<<"The number is "<<n<<endl;

}

int main(){
    int n ;
    cin>>n;

    dummy(n); // output is 6

    cout<<"The number is "<<n<<endl; // output is 5

    /* IN PASS BY VALUE A COPY OF VARIABLE IS SENT TO THE FUNCTIONN. SINCE IT IS THE COPY 
    THE CHANGE DOES NOT REFLECT IN THE MAIN FUNCNTION
    */


}