#include<iostream>
#include <string>
# include <cmath>
using namespace std;

// decimal to binary 
/*
string decimalTobinary(int n){
    if (n == 0) return "0";
    string binary= "";
    while(n>0){
        binary = to_string(n%2)+binary; //  take remainder and reverse
        n /= 2;
    }
    return binary;
}

int main(){
    int n; 
    cout<<"Enter the value of n";
    cin>> n;
    cout<< "Binary :"<< decimalTobinary(n) << "\n";
}
*/

int main(){
    //decimal to binary 
  /*int n;
    cout<<"Enter a number";
    cin>>n;
    int ans = 0;
    int place =1;

    while(n!=0){
        int bit = n & 1;
        ans = (bit * place)+ ans;
        n = n >> 1;
        place *= 10;
    }
    cout<<"Binary: "<< ans;
    */

    // count the no. of 1's in the binary representation 
  /*int  n;
    cout<<"Enter the number n: ";
    cin>>n;
    int count =0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n = n >> 1;
    }
    cout<<"The total no. of one's are: "<<count<<"\n";
    */

    //decimal to binary for negative numbers
    /*int n;
    cout << "Enter a number: ";
    cin >> n;

    const int BITS = 8;   
    int binary[BITS] = {0};  

    if (n >= 0) {
        int i = BITS - 1;
        while (n > 0 && i >= 0) {
            binary[i] = n % 2;
            n /= 2;
            i--;
        }
    } else {// for nagtive numbers
        int absVal = -n;

        int i = BITS - 1;
        while (absVal > 0 && i >= 0) {
            binary[i] = absVal % 2;
            absVal /= 2;
            i--;// converted to binary
        }
        for (int j = 0; j < BITS; j++) {
            binary[j] = 1 - binary[j];//1's complement
        }
        int carry = 1;
        for (int j = BITS - 1; j >= 0; j--) {
            int sum = binary[j] + carry;
            binary[j] = sum % 2;
            carry = sum / 2;// 2's complement
        }
    }
    cout << "Binary (" << BITS << "-bit Two’s Complement): ";
    for (int i = 0; i < BITS; i++) {
        cout << binary[i];
    }
    cout << endl;

    return 0; */

    // binary to decimal;
    int n;
    cout<<"Enter a binary number: \n";
    cin>>n;
    int ans = 0;
    int i=0;
    while(n!=0){
        int digit = n%10;
        if(digit == 1){
            ans = ans + pow(2,i);
            
        }
        n = n / 10;
            i++;
    }
    cout<<ans;
}